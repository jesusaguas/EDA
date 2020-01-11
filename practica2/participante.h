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


struct participante;

//----OPERACIONES PUBLICAS----

//crea un participante que tiene como campos los argumentos dados
void crear(const string c, const int a, const int f, const int p, participante& pt);

//devuelve el nombre del participante
string ct(const participante& pt);

//devuelve el numero de aciertos del participante
int numAciertos(const participante& pt);

//devuelve el numero de fallos del participante
int numFallos(const participante& pt);

//devuelve el numero de veces que ha optado por pasar el participante
int numPases(const participante& pt);

//incrementa el numero de aciertos del participante
void sumarA(participante& pt);

//incrementa el numero de fallos del participante
void sumarF(participante& pt);

//incrementa el numero de pases del participante
void sumarP(participante& pt);

//muestra por pantalla la informacion del participante
string info(const participante& pt);


//--------------------------------------------------------------------------


struct participante {
  public:
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
