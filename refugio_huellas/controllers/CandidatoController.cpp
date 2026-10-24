#include "Controller.h"

void crearCandidato(const httplib::Request &req, httplib::Response &res)
{
	try {
		std::cout << "candidato: " << req.body << std::endl;
		nlohmann::json request_body = nlohmann::json::parse(req.body);

		CandidatoEntity candidatoEntity;
		std::cout << "Despues de crear el candidato" << std::endl;
		candidatoEntity.setNombre(request_body["nombre"]);
		candidatoEntity.setApellido(request_body["apellido"]);
		string correoElectronico = request_body["correoElectronico"];
		candidatoEntity.setCorreoElectronico(request_body["correoElectronico"]);
		candidatoEntity.setTelefono(request_body["telefono"]);
		candidatoEntity.setMascotas(request_body["mascotas"]);

		DireccionEntity direccion;
		direccion.setCalle(request_body["direccion"]["calle"]);
		direccion.setEstado(request_body["direccion"]["estado"]);
		direccion.setPais(request_body["direccion"]["pais"]);
		direccion.setNumero(request_body["direccion"]["numero"]);
		candidatoEntity.setDireccion(direccion);

		CandidatoDAO candidatoDAO;
		candidatoDAO.guardarCandidato(candidatoEntity);

		res.status = 201;
		res.set_content(req.body, "application/json");
	} catch(const std::exception& e) {
		std::cerr << "Error al crear candidato: " << e.what() << std::endl;
		res.status = 500;
		nlohmann::json error_response = {
			{"status", "error"},
			{"mensaje", "Ocurrió un error al crear el candidato"}
		};
		res.set_content(error_response.dump(4), "application/json");
	}
}