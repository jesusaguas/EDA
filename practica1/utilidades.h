#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


//Devuelve la misma cadena
string generaCadena(const string& c){
	return c;
}

//Devuelve un booleano resultado de comparar si ambas claves son iguales
bool sonIguales(const string& c1, const string& c2){
	return c1==c2;
}

//Devuelve un booleano resultado de comparar si c1 es menor que c2
bool menorQue(const string& c1, const string& c2){
	return c1<c2;
}

