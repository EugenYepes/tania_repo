#ifndef ANIMALENTITY_H
#define ANIMALENTITY_H

#include <httplib.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include "entities/EmpleadoEntity.h"
#include "dao/EmpleadoDAO.h"

void crearEmpleado(const httplib::Request &req, httplib::Response &res);

#endif // ANIMALENTITY_H