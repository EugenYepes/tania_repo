#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <httplib.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include "entities/EmpleadoEntity.h"
#include "dao/EmpleadoDAO.h"
#include "entities/CandidatoEntity.h"
#include "dao/CandidatoDAO.h"
#include "entities/PerroEntity.h"
#include "dao/PerroDAO.h"
#include "entities/GatoEntity.h"
#include "dao/GatoDAO.h"

void crearEmpleado(const httplib::Request &req, httplib::Response &res);
void crearCandidato(const httplib::Request &req, httplib::Response &res);
void crearPerro(const httplib::Request &req, httplib::Response &res);
void crearGato(const httplib::Request &req, httplib::Response &res);

#endif // CONTROLLER_H