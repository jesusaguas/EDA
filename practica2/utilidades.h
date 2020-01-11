//*****************************************************************
// File:   utilidades.h
// Author: Jesus Aguas, Sergio Costa
// Date:   diciembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <fstream>
#include <string>
#include "participante.h"
#include "preguntas.h"
#include "instantes.h"

using namespace std;


//Devuelve la misma cadena
string generaCadena(const string& c);

//Devuelve un booleano resultado de comparar si ambas claves son iguales
bool sonIguales(const string& c1, const string& c2);

//Devuelve un booleano resultado de comparar si la cadena c1 es menor que c2
bool menorQue(const string& c1, const string& c2);

//Devuelve la cadena que representa la clave c
string generaCadena(const int& c);

//Devuelve la cadena que representa al participante p
string generaCadena(const participante& p);

//Devuelve la cadena que representa el dato p
string generaCadena(const pregunta& p);

//Devuelve la cadena que representa el instante t
string generaCadena(const instante& t);

//Devuelve un booleano resultado de comparar si ambas claves son iguales, ambas enteros
bool igualClave(const int& o1, const int& o2);

//Devuelve un booleano resultado de comparar si o1 es menor que o2, ambos enteros
bool mayorClave(const int& o1, const int& o2);


#endif
