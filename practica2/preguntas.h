/*
* Nombre del archivo: preguntas.h
* Autores: Sergio Costa 735317, Jesus Aguas 736935
* Fecha: diciembre 2017
* Comentarios: practica2 de EDA
*/

#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <iostream>
#include <string>

using namespace std;


struct pregunta;

//----OPERACIONES PUBLICAS----

//crea una pregunta con sus opciones y el identificador de respuesta verdadera
void crear(const string& pr, const string& op1, const string& op2, const int r, pregunta& p);

//devuelve una cadena con la informacion de la pregunta
string info(const pregunta& p);

//devuelve cierto si y solo si r es la opcion correcta de la pregunta p, si no devuelve falso
bool respuesta(const pregunta& p, const int r);


//--------------------------------------------------------------------------


struct pregunta {
	//funciones
	friend void crear(const string& pr, const string& op1, const string& op2, const int r, pregunta& p);
	friend string info(const pregunta& p);
	friend bool respuesta(const pregunta& p, const int r);

private:
	//campos
	string preg;	//cadena que contiene la pregunta
	string op[2];	//vector de cadenas; posicion 0 del vector primera opcion, posicion 1 del vector segunda opcion
	int respuesta;	//entero que toma valor 1 o 2 dependiendo que opcion sea la correccta
};

#endif
