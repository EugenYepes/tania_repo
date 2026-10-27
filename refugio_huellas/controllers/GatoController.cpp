#include "Controller.h"
#include "dao/EmpleadoDAO.h"
#include "dao/GatoDAO.h"
#include "entities/GatoEntity.h"

void crearGato(const httplib::Request &req, httplib::Response &res)
{
	try {
		std::cout << "gato: " << req.body << std::endl;
		nlohmann::json request_body = nlohmann::json::parse(req.body);

		GatoEntity gatoEntity;
		gatoEntity.setEstado(request_body.at("estado").get<std::string>());
		gatoEntity.setEdad(request_body["edad"]);
		gatoEntity.setNombre(request_body["nombre"]);
		gatoEntity.setDiagnostico(request_body["diagnostico"]);
        gatoEntity.setTest(request_body["test"]);
        gatoEntity.setIndoor(request_body["indoor"]);

		EmpleadoDAO empleadoDAO;
		EmpleadoEntity cuidador = empleadoDAO.getCuidadorConMenosMascotas();
		gatoEntity.setCuidador(&cuidador);
		std::cout << "cuidador con menos mascotas encontrado " << cuidador.getNombre() << std::endl;
		GatoDAO gatoDAO;
		gatoDAO.guardarGato(gatoEntity);

		res.status = 201;
		res.set_content(req.body, "application/json");
	} catch(const std::exception& e) {
		std::cerr << "Error al crear gato: " << e.what() << std::endl;
		res.status = 500;
		nlohmann::json error_response = {
			{"status", "error"},
			{"mensaje", "Ocurrió un error al crear el gato"}
		 };
		res.set_content(error_response.dump(4), "application/json");
	}
}


/**/