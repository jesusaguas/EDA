/*
* Nombre del archivo: instantes.h
* Autores: Sergio Costa 735317, Jesus Aguas 736935
* Fecha: diciembre 2017
* Comentarios: practica2 de EDA; necesario -std=c++11 para su compilacion
*/

#ifndef INSTANTES_H
#define INSTANTES_H

#include <iostream>
#include <string>

using namespace std;


struct instante;

//----OPERACIONES PUBLICAS----

//crea un instante con las horas y minutos dados
void crear(const int h, const int m, instante& i);

//devuelve una cadena con la informacion del instante
string mostrar(const instante& i);

//devuelve una cadena con las horas del instante
string mostrarH(const instante& i);

//devuelve una cadena con los minutos del instante
string mostrarMin(const instante& i);


//--------------------------------------------------------------------------


struct instante {
	//funciones
	friend void crear(const int h, const int m, instante& i);
	friend string mostrar(const instante& i);
	friend string mostrarH(const instante& i);
	friend string mostrarMin(const instante& i);
	
private:
	//campos
	int horas, minutos;
};

#endif
