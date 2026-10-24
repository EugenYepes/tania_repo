#include "Controller.h"
#include "dao/EmpleadoDAO.h"
#include "dao/PerroDAO.h"
#include "entities/PerroEntity.h"

void crearPerro(const httplib::Request &req, httplib::Response &res)
{
	try {
		std::cout << "perro: " << req.body << std::endl;
		nlohmann::json request_body = nlohmann::json::parse(req.body);

		PerroEntity perroEntity;
		perroEntity.setEstado(request_body.at("estado").get<std::string>());
		perroEntity.setEdad(request_body["edad"]);
		perroEntity.setNombre(request_body["nombre"]);
		perroEntity.setDiagnostico(request_body["raza"]);

		perroEntity.setRaza(request_body["raza"]);
		perroEntity.setEnergia(request_body["energia"]);

		EmpleadoDAO empleadoDAO;
		EmpleadoEntity cuidador = empleadoDAO.getCuidadorConMenosMascotas();
		perroEntity.setCuidador(&cuidador);

		PerroDAO perroDAO;
		perroDAO.guardarPerro(perroEntity);

		res.status = 201;
		res.set_content(req.body, "application/json");
	} catch(const std::exception& e) {
		std::cerr << "Error al crear perro: " << e.what() << std::endl;
		res.status = 500;
		nlohmann::json error_response = {
			{"status", "error"},
			{"mensaje", "Ocurrió un error al crear el perro"}
		};
		res.set_content(error_response.dump(4), "application/json");
	}
}