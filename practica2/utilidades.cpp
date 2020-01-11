//*****************************************************************
// File:   utilidades.cpp
// Author: Jesus Aguas, Sergio Costa
// Date:   diciembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "utilidades.h"

using namespace std;


//Devuelve la misma cadena
string generaCadena(const string& c){
	return c;
}

//Devuelve un booleano resultado de comparar si ambas claves son iguales
bool sonIguales(const string& c1, const string& c2){
	return c1==c2;
}

//Devuelve un booleano resultado de comparar si la cadena c1 es menor que c2
bool menorQue(const string& c1, const string& c2){
	return c1<c2;
}

//Devuelve la cadena que representa la clave c
string generaCadena(const int& c){
	return to_string(c);
}

//Devuelve la cadena que representa al participante p
string generaCadena(const participante& p){
	return info(p);
}

//Devuelve la cadena que representa el dato p
string generaCadena(const pregunta& p){
	return info(p);
}

//Dado un instante t, devuelve la cadena que representa t
string generaCadena(const instante& t){
	return mostrar(t);
}

//Devuelve un booleano resultado de comparar si ambas claves son iguales, ambas enteros
bool igualClave(const int& o1, const int& o2){
	return o1==o2;
}

//Devuelve un booleano resultado de comparar si o1 es menor que o2, ambos enteros
bool mayorClave(const int& o1, const int& o2){
	return o1>o2;
}
