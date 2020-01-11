/*
* Nombre del archivo: participante.h
* Autores: Sergio Costa 735317, Jesus Aguas 736935
* Fecha: octubre 2017
* Comentarios: practica1 de EDA
*/

#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H

#include <iostream>
#include <cstring>

using namespace std;


struct participante {
	//funciones
	friend void crear(const string c, const int a, const int f, const int p, participante& pt);
	friend string ct(const participante& pt);
	friend int numAciertos(const participante& pt);
	friend int numFallos(const participante& pt);
	friend int numPases(const participante& pt);
	friend void sumarA(participante& pt);
	friend void sumarF(participante& pt);
	friend void sumarP(participante& pt);
	friend string info(const participante& pt);
	
  private:
  	//campos
	string contacto;
	int aciertos, fallos, pases;
};

#endif
