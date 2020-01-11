//*****************************************************************
// File:   practica2.cpp
// Author: Jesus Aguas, Sergio Costa
// Date:   diciembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#include <iostream>
#include <fstream>
#include "utilidades.h"
#include "participante.h"
#include "preguntas.h"
#include "instantes.h"
#include "utilidades.h"
#include "rondaSeleccion.h"
#include "cmt.h"
#include "concurso.h"
#include <cstring>

using namespace std;



/*
Procedimiento que dada una instruccion lee del flujo de entrada los datos necesarios
para escribir en el flujo de salida el resultado
Recibe como parametros un flujo de entrada, un flujo de salida y el concurso que tiene que tratar
*/
void procesador(ifstream& fe, ofstream& fs, concurso& c){
	string instruccion;
	getline(fe,instruccion);
	//Introducir pregunta
	if(instruccion=="ip"){
		string lectura;
		string preg, o1, o2;
		int IDpreg, resp;
		pregunta p;
		bool error;
		fe>>IDpreg;
		getline(fe,lectura);
		getline(fe,preg);
		getline(fe,o1);
		getline(fe,o2);
		fe>>resp;
		getline(fe,lectura);
		crear(preg,o1,o2,resp,p);
		if(!enDocumentacion(c)){
			fs<<"INSERCION DESCARTADA: ";
		}
		else if(existePregunta(c,IDpreg)){
			anyadirPregunta(c,IDpreg,p,error);
			fs<<"ACTUALIZACION REALIZADA: ";
		}
		else{
			anyadirPregunta(c,IDpreg,p,error);
			fs<<"INSERCION REALIZADA: ";
		}
		//INFO PREGUNTA
		fs<<IDpreg<<":::";
		bool usado;
		preguntaUtilizada(c,IDpreg,usado,error);
		if(usado){
			instante i;
			obtenerUltimoUsoPregunta(c,IDpreg,i,error);
			fs<<mostrar(i)<<endl;
		}
		else{
			fs<<"-"<<endl;
		}
		fs<<info(p)<<"\n";
	}
	//Listar una pregunta
	else if(instruccion=="lp"){
		string lectura;
		int IDpreg;
		fe>>IDpreg;
		getline(fe,lectura);
		bool error;
		if(existePregunta(c,IDpreg)){
			fs<<"PREGUNTA ENCONTRADA: ";
			//INFO PREGUNTA
			fs<<IDpreg<<":::";
			bool usado;
			preguntaUtilizada(c,IDpreg,usado,error);
			if(usado){
				instante i;
				obtenerUltimoUsoPregunta(c,IDpreg,i,error);
				fs<<mostrar(i)<<endl;
			}
			else{
				fs<<"-"<<endl;
			}
			pregunta p;
			obtenerPregunta(c,IDpreg,p,error);
			fs<<info(p);
		}
		else{
			fs<<"PREGUNTA NO encontrada: "<<lectura<<endl;
		}
	}
	//Borrar pregunta
	else if(instruccion=="bp"){
		string lectura;
		int IDpreg;
		fe>>IDpreg;
		getline(fe,lectura);
		bool error;
		if(!enDocumentacion(c)){
			fs<<"BORRADO pregunta NO POSIBLE: ";
		}
		else if(existePregunta(c,IDpreg)){
			borrarPregunta(c,IDpreg,error);
			fs<<"PREGUNTA BORRADA: ";
		}
		else{
			fs<<"BORRADO DESCARTADO: ";
		}
		fs<<IDpreg<<endl;
	}
	//Listar todas las preguntas
	else if(instruccion=="lc"){
		fs<<listarPreguntas(c);
	}
	//Marcar con tiempo una pregunta
	else if(instruccion=="mp"){
		string lectura;
		int IDpreg, hora, minutos;
		fe>>IDpreg;
		getline(fe,lectura);
		fe>>hora;
		getline(fe,lectura,':');
		fe>>minutos;
		getline(fe,lectura);
		if(existePregunta(c,IDpreg)){
			instante i;
			bool error;
			crear(hora,minutos,i);
			marcarPregunta(c,IDpreg,i,error);
			fs<<"PREGUNTA MARCADA: "<<IDpreg<<";";
			string tiempo = to_string(hora) + ":" + to_string(minutos);
			fs<<tiempo<<endl;
		}
		else{
			fs<<"MARCA DESCARTADA: "<<IDpreg<<endl;
		}
		fs<<lectura;
	}
	//Inscribir concursante
	else if(instruccion=="ipa"){
		string IDconcursante, contacto;
		bool error;
		if(enInscripcion(c)){		//si esta en inscripcion
			getline(fe,IDconcursante);
			participante p;
			obtenerInfoConcursante(c,IDconcursante,p,error);
			getline(fe,contacto);
			crear(contacto,0,0,0,p);
			if(!error){				//si ya esta inscrito
				anyadirConcursante(c,IDconcursante,p,error);
				fs<<"participante ACTUALIZADO: "<<IDconcursante<<";"<<info(p)<<endl;
			}
			else{					//si tiene que ser inscrito
				anyadirConcursante(c,IDconcursante,p,error);
				fs<<"participante INSCRITO: "<<IDconcursante<<";"<<info(p)<<endl;
			}
		}
		else{						//si no esta en inscripcion
			getline(fe,IDconcursante);
			getline(fe,contacto);
			participante p;
			crear(contacto,0,0,0,p);
			fs<<"inscripcion CERRADA: "<<IDconcursante<<";"<<info(p)<<endl;
		}
	}
	//Borrar concursante
	else if(instruccion=="bpa"){
		string IDconcursante;
		bool error;
		if (enInscripcion(c)){		//si esta en inscripcion
			getline(fe,IDconcursante);
			participante p;
			obtenerInfoConcursante(c,IDconcursante,p,error);
			if(error){				//no esta en la ronda
				fs<<"participante NO ENCONTRADO: "<<IDconcursante<<endl;
			}
			else{					//esta en la ronda
				borrarConcursante(c,IDconcursante,error);
				fs<<"participante BORRADO: "<<IDconcursante<<endl;
			}
		}
		else{						//si no esta en seleccion
			participante p;
			obtenerInfoConcursante(c,IDconcursante,p,error);
			fs<<"BORRADO participante DESCARTADO: "<<IDconcursante<<endl;
		}
	}
	//Mostrar concursante
	else if(instruccion=="mpa"){
		string IDconcursante, valor;
		bool error;
		getline(fe,IDconcursante);
		participante p;
		obtenerInfoConcursante(c,IDconcursante,p,error);
		if (error){					//si no esta en la ronda
			fs<<"participante DESCONOCIDO: "<<IDconcursante<<endl;
		}
		else{						//si esta en la ronda
			fs<<"participante ENCONTRADO: "<<IDconcursante<<";"<<info(p)<<endl;
		}
	}
	//Obtener concursante actual
	else if(instruccion=="oc"){
		if(!enJuego(c)){
			fs<<"CONSULTA candidato DESCARTADA"<<endl;
		}
		else if(!existeConcursanteActual(c)){
			fs<<"ronda VACIA"<<endl;
		}
		else{
			string IDconcursante;
			participante p;
			bool error;
			obtenerConcursanteActual(c,IDconcursante,error);
			obtenerInfoConcursante(c,IDconcursante,p,error);
			fs<<"CANDIDATO a evaluar: "<<IDconcursante<<";"<<info(p)<<endl;
		}
	}
	//Listar concursantes
	else if(instruccion=="lr"){
		fs<<listarConcursantes(c);
	}
	//Iniciar inscripcion
	else if(instruccion=="ii"){
		if(enDocumentacion(c)){
			iniciarInscripcion(c);
			fs<<"INSCRIPCION ABIERTA"<<endl;
		}
		else{
			fs<<"INSCRIPCION CANCELADA"<<endl;
		}
	}
	//Iniciar juego
	else if(instruccion=="ij"){
		if(enInscripcion(c) && totalConcursantes(c)>maximoNumeroGanadores(c)){
			iniciarJuego(c);
			fs<<"INICIANDO JUEGO: "<<totalConcursantes(c)<<endl;
		}
		else{
			fs<<"NO ES POSIBLE iniciar JUEGO"<<endl;
		}
	}
	//Probar concursante actual
	else if(instruccion=="pca"){
		string lectura;
		int IDpreg, hora, minutos, resp;
		fe>>IDpreg;
		getline(fe,lectura);
		fe>>hora;
		getline(fe,lectura,':');
		fe>>minutos;
		getline(fe,lectura);
		fe>>resp;
		getline(fe,lectura);
		bool error;
		if(!enJuego(c)){
			fs<<"PROBAR concursante DESCARTADO"<<endl;
		}
		else if(totalConcursantes(c)==0){
			fs<<"ronda VACIA"<<endl;
		}
		else if(!existePregunta(c,IDpreg)){
			fs<<"PREGUNTA no encontrada: "<<IDpreg<<endl;
		}
		else if(resp<0 || resp>2){
			fs<<"RESPUESTA NO VALIDA"<<endl;
		}
		else{
			string cadena = "+++ RESPONDE CONCURSANTE +++\n";
			string IDconcursante;
			participante p;
			pregunta preg;
			obtenerConcursanteActual(c,IDconcursante,error);
			obtenerInfoConcursante(c,IDconcursante,p,error);
			obtenerPregunta(c,IDpreg,preg,error);
			instante i;
			crear(hora,minutos,i);
			int antes = totalConcursantes(c);
			probarConcursanteActual(c,IDpreg,i,resp,error);
			cadena += "CONCURSANTE: " + IDconcursante + ";" + info(p) + "\n";
			cadena += "PREGUNTA: " + info(preg) + "\n";
			cadena += "RESPUESTA DADA: " + to_string(resp) + " TIEMPO: " + mostrar(i) + "\n";
			if(antes!=totalConcursantes(c)){
				cadena += "CONCURSANTE ELIMINADO\n";
			}
			cadena += "+++++++++++\n";
			fs<<cadena;
		}
	}
	//Hay ganadores
	else if(instruccion=="hg"){
		if(hayGanadores(c)){
			fs<<"<<< CONCURSANTES GANADORES >>>"<<endl;
			fs<<listarConcursantes(c)<<endl;
		}
		else {
			fs<<"SIN GANADORES"<<endl;
		}
	}
	//Listar todos los datos del concurso
	else if(instruccion=="lt"){
		fs<<listarConcurso(c)<<endl;
	}
}

int main(){
	//se declara e inicializa el concurso
	concurso c;
	crearConcurso(2,2,1,c);
	//se declaran flujos de entrada y salida para los ficheros que se utilizaran
	ifstream fe("concursoentrada.txt");
	ofstream fs("concursosalida.txt");
	if(fe.is_open() && fs.is_open()){
		while(!fe.eof()){
			procesador(fe,fs,c);
		}
	}
	else{
		cout<<"Error, ficheros no abiertos"<<endl;
	}
	
	fe.close();
	fs.close();
	
	return 0;
}
