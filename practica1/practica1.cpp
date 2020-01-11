//*****************************************************************
// File:   practica1.cpp
// Author: Jesus Aguas, Sergio Costa
// Date:   noviembre 2017
// Coms:   Practica 1 de EDA
//*****************************************************************

#include <iostream>
#include <fstream>
#include "utilidades.h"
#include "participante.h"
#include "rondaSeleccion.h"
#include <cstring>

using namespace std;



/*
Procedimiento que dada una instruccion lee del flujo de entrada los datos necesarios
para escribir en el flujo de salida el resultado
Recibe como parametros un flujo de entrada, un flujo de salida y una cadena con
la instruccion a ejecutar
*/
void procesador(ifstream& fe, ofstream& fs, ronda<string,participante>& r){
	string instruccion;
	getline(fe,instruccion);
	//Inscribir participante
	if(instruccion=="ipa"){
		string clave, contacto;
		bool error;
		if(!enSeleccion(r)){		//si esta en inscripcion
			getline(fe,clave);
			participante p;
			buscar(r,clave,p,error);
			getline(fe,contacto);
			crear(contacto,0,0,0,p);
			if(!error){				//si esta en la ronda
				anyadir(r,clave,p,error);
				fs<<"participante ACTUALIZADO: "<<clave<<";"<<info(p)<<endl;
			}
			else{					//si no esta en la ronda
				anyadir(r,clave,p,error);
				fs<<"participante INSCRITO: "<<clave<<";"<<info(p)<<endl;
			}
		}
		else{						//si esta en seleccion
			getline(fe,clave);
			getline(fe,contacto);
			participante p;
			crear(contacto,0,0,0,p);
			fs<<"inscripcion CERRADA: "<<clave<<";"<<info(p)<<endl;
		}
	}
	//Borrar participante
	else if(instruccion=="bpa"){
		string clave;
		bool error;
		if (!enSeleccion(r)){		//si esta en inscripcion
			getline(fe,clave);
			participante p;
			buscar(r,clave,p,error);
			if(error){				//no esta en la ronda
				fs<<"participante NO ENCONTRADO: "<< clave <<endl;
			}
			else{					//esta en la ronda
				quitar(r,clave,error);
				fs<<"participante BORRADO: "<< clave <<endl;
			}
		}
		else{						//si esta en seleccion
			participante p;
			buscar(r,clave,p,error);
			fs<<"BORRADO participante DESCARTADO: "<< clave<<endl;
		}
	}
	//Mostrar participante
	else if(instruccion=="mpa"){
		string clave, valor;
		bool error;
		getline(fe,clave);
		participante p;
		buscar(r,clave,p,error);
		if (error){					//si no esta en la ronda
			fs<<"participante DESCONOCIDO: "<< clave <<endl;
		}
		else{						//si esta en la ronda
			fs<<"participante ENCONTRADO: "<<clave<<";"<<info(p)<<endl;
		}
	}
	//Cerrar inscripcion
	else if(instruccion=="ci"){
		if(!enSeleccion(r)){
			cerrarInscripcion(r);
			iniciarIterador(r);
			fs<<"inscripcion CERRADA con participantes TOTALES: "<<cardinal(r)<<endl;
		}
		else{
			fs<<"CIERRE de inscripcion DESCARTADO"<<endl;
		}
	}
	//Obtener candidato
	else if(instruccion=="oc"){
		if(!enSeleccion(r)){
			fs<<"CONSULTA candidato DESCARTADA"<<endl;
		}
		else if(esVacia(r)){
			fs<<"ronda VACIA"<<endl;
		}
		else{
			string clave;
			participante p;
			bool error;
			obtenerCandidatoSuClave(r,clave,error);
			obtenerCandidatoSuValor(r,p,error);
			fs<<"CANDIDATO a evaluar: "<<clave<<";"<<info(p)<<endl;
		}
	}
	//Descartar candidato
	else if(instruccion=="dc"){
		if(!enSeleccion(r)){
			fs<<"ELIMINACION candidato DESCARTADA"<<endl;
		}
		else if(esVacia(r)){
			fs<<"ronda VACIA"<<endl;
		}
		else{
			string clave;
			participante p;
			bool error;
			obtenerCandidatoSuClave(r,clave,error);
			obtenerCandidatoSuValor(r,p,error);
			eliminarCandidato(r,error);
			fs<<"candidato ELIMINADO: "<<clave<<";"<<info(p)<<endl;
		}
	}
	//Actualizar candidato
	else if(instruccion=="ac"){
		if(!enSeleccion(r)){
			fs<<"ACTUALIZACION candidato DESCARTADA"<<endl;
		}
		else if(esVacia(r)){
			fs<<"ronda VACIA"<<endl;
		}
		else{
			string letra, clave;
			participante p;
			bool error;
			getline(fe,letra);
			if(letra=="A"){
				obtenerCandidatoSuValor(r,p,error);
				sumarA(p);
				actualizarCandidato(r,p,error);
			}
			else if(letra=="F"){
				obtenerCandidatoSuValor(r,p,error);
				sumarF(p);
				actualizarCandidato(r,p,error);
			}
			else if(letra=="P"){
				obtenerCandidatoSuValor(r,p,error);
				sumarP(p);
				actualizarCandidato(r,p,error);
			}
			obtenerCandidatoSuClave(r,clave,error);
			fs<<"candidato ACTUALIZADO: "<<clave<<";"<<info(p)<<endl;
		}
	}
	//Pasar turno
	else if(instruccion=="pt"){
		if(!enSeleccion(r)){
			fs<<"CAMBIO de turno DESCARTADO"<<endl;
		}
		else if(esVacia(r)){
			fs<<"ronda VACIA"<<endl;
		}
		else {
			string clave;	
			participante p;
			bool error;
			pasarTurno(r,error);
			obtenerCandidatoSuClave(r,clave,error);
			obtenerCandidatoSuValor(r,p,error);
			fs<<"TURNO en candidato: "<<clave<<";"<<info(p)<<endl;
		}
	}
	else if(instruccion=="lr"){
		string seleccion;
		if (enSeleccion(r)){
			seleccion = "SELECCION";
		}
		else{
			seleccion = "INSCRIPCION";
		}
		fs << "***** Ronda en fase: " << seleccion <<endl;
		fs << "TOTAL: " << to_string(cardinal(r)) <<endl;
		fs << listar(r)<<flush;
		if (enSeleccion(r)){
			fs << "TURNO en candidato: "<<flush;
			bool error;
			string alias;
			obtenerCandidatoSuClave(r,alias,error);
			if(error){
				fs << "---"<<endl;
			}
			else{
				fs << alias <<endl;
			}	
		}
		fs << "*****"<<endl;
	}
}

int main(){
	//se declara e inicializa la ronda
	ronda<string,participante> r;
	crear(r);
	//se declaran flujos de entrada y salida para los ficheros que se utilizaran
	ifstream fe("rondaentrada.txt");
	ofstream fs("rondasalida.txt");
	
	if(fe.is_open() && fs.is_open()){
		while(!fe.eof()){
			procesador(fe,fs,r);
		}
	}
	else{
		cout<<"Error, ficheros no abiertos"<<endl;
	}
	
	fe.close();
	fs.close();
	
	return 0;
}
