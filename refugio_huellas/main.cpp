#include "entities/CandidatoEntity.h"
#include <iostream>
#include <httplib.h>
#include <nlohmann/json.hpp>
#include "controllers/Controller.h"

using json = nlohmann::json;

int main(void)
{
	httplib::Server server;
	server.Get("/test", [](const httplib::Request &req, httplib::Response &res)
	{
		std::cout << "Se recibio una solicitud GET en /test" << std::endl;
		json response = {
			{"status", "exito"},
			{"mensaje", "El servidor inicio correctamente"}
		};
		std::cout << "Se responde una solicitud GET en /test" << std::endl;

		res.set_content(response.dump(4), "application/json"); 
	});

	server.Post("/empleado", crearEmpleado);
	server.Post("/candidato", crearCandidato);
	server.Post("/perro", crearPerro);

	std::cout << "Servidor iniciado ANTES en http://localhost:3000" << std::endl;

	server.listen("0.0.0.0", 3000);
	std::cout << "Servidor iniciado en http://localhost:3000" << std::endl;
			
}