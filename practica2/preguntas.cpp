/*
* Nombre del archivo: preguntas.cpp
* Autores: Sergio Costa 735317, Jesus Aguas 736935
* Fecha: diciembre 2017
* Comentarios: practica2 de EDA; necesario -std=c++11 para su compilacion
*/

#include <iostream>
#include <string>
#include "preguntas.h"


using namespace std;

//crea una pregunta con sus opciones y el identificador de respuesta verdadera
void crear(const string& pr, const string& o1, const string& o2, const int r, pregunta& p){
	p.preg = pr;
	p.op[0] = o1;
	p.op[1] = o2;
	p.respuesta = r;
};

//devuelve una cadena con la informacion de la pregunta
string info(const pregunta& p){
	string cadena = "<*" + p.preg + "*>:\n<A) " + p.op[0] + " ; B) " + p.op[1] + " ; OK: " + to_string(p.respuesta) + ">";
	return cadena;
};

//devuelve cierto si y solo si r es la opcion correcta de la pregunta p, si no devuelve falso
bool respuesta(const pregunta& p, const int r){
	return p.respuesta==r;
};
