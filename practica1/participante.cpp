/*
* Nombre del archivo: participante.cpp
* Autores: Sergio Costa 735317, Jesus Aguas 736935
* Fecha: octubre 2017
* Comentarios: practica1 de EDA
*/

#include <iostream>
#include "participante.h"
#include <cstring>


using namespace std;

//crea un participante que tiene como campos los argumentos dados
void crear(const string c, const int a, const int f, const int p, participante& pt){
	pt.contacto = c;
	pt.aciertos = a;
	pt.fallos = f;
	pt.pases = p;
};

string ct(const participante& pt){
	return pt.contacto;
};

//devuelve el numero de aciertos del participante
int numAciertos(const participante& pt){
	return pt.aciertos;
};

//devuelve el numero de fallos del participante
int numFallos(const participante& pt){
	return pt.fallos;
};

//devuelve el numero de veces que ha optado por pasar el participante
int numPases(const participante& pt){
	return pt.pases;
};

//incrementa el numero de aciertos del participante
void sumarA(participante& pt){
	pt.aciertos++;
};

//incrementa el numero de fallos del participante
void sumarF(participante& pt){
	pt.fallos++;
};

//incrementa el numero de pases del participante
void sumarP(participante& pt){
	pt.pases++;
};

//muestra por pantalla la informacion del participante
string info(const participante& pt){
	string a = to_string(numAciertos(pt));
	string f = to_string(numFallos(pt));
	string i = to_string(numPases(pt));
	string informacion = "OK: " + a + "||F: " + f + "||P: " + i + "||D: " + ct(pt);
	return informacion;
};

