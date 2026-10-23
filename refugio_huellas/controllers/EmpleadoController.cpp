#include "Controller.h"


void crearEmpleado(const httplib::Request &req, httplib::Response &res)
{
	std::cout << req.body << std::endl;
	nlohmann::json request_body = nlohmann::json::parse(req.body);

	EmpleadoEntity empleadoEntity;
	empleadoEntity.setNombre(request_body["nombre"]);
	empleadoEntity.setApellido(request_body["apellido"]);
	string correoElectronico = request_body["correoElectronico"];
	std::cout << "Correo electrónico recibido: " << correoElectronico << std::endl;
	empleadoEntity.setCorreoElectronico(request_body["correoElectronico"]);
	empleadoEntity.setTelefono(request_body["telefono"]);
	empleadoEntity.setSueldo(request_body["sueldo"]);
	empleadoEntity.setTurno(request_body["turno"]);

	EmpleadoDAO empleadoDAO;
	empleadoDAO.guardarEmpleado(empleadoEntity);

	res.status = 201;
	res.set_content(req.body, "application/json");
}