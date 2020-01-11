/*
* Nombre del archivo: instantes.cpp
* Autores: Sergio Costa 735317, Jesus Aguas 736935
* Fecha: diciembre 2017
* Comentarios: practica2 de EDA; necesario -std=c++11 para su compilacion
*/

#include <iostream>
#include <string>
#include "instantes.h"


using namespace std;

//crea un instante con las horas y minutos dados
void crear(const int h, const int m, instante& i){
	i.horas = h;
	i.minutos = m;
};

//devuelve una cadena con la informacion del instante
string mostrar(const instante& i){
	string cadena = to_string(i.horas) + ":" + to_string(i.minutos);
	return cadena;
};

//devuelve una cadena con las horas del instante
string mostrarH(const instante& i){
	string cadena = to_string(i.horas);
	return cadena;
};

//devuelve una cadena con los minutos del instante
string mostrarMin(const instante& i){
	string cadena = to_string(i.minutos);
	return cadena;
};
