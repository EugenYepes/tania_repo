#ifndef CANDIDATODAO_H
#define CANDIDATODAO_H

#include "CandidatoEntity.h"
#include <list>
#include "DAO.h"

class CandidatoDAO : public DAO
{
public:
	void guardarCandidato(CandidatoEntity candidato);

	CandidatoEntity getCandidato(string telefono, string email);

	list<CandidatoEntity> getAllCandidatos();
};

#endif