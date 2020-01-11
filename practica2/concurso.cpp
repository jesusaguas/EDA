//*****************************************************************
// File:   concurso.cpp
// Author: Jesus Aguas, Sergio Costa
// Date:   diciembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "concurso.h"

using namespace std;

//Inicializa el concurso c.
void crearConcurso(const int& PMax, const int& FMax, const int& numGmax, concurso& c){
	//inicializa los campos privados del concurso
	c.pasesMax = PMax;
	c.fallosMax = FMax;
	c.ganadoresMax = numGmax;
	c.estado = 0;
	crear(c.colParticipantes);
	crear(c.colPreguntas);
}

//Devuelve el numero total de pases que se permitira a cada participante del concurso.
int maximoPasesPermitidos(const concurso& c){
	return c.pasesMax;
}

//Devuelve el numero total de fallos con los que se descalificara a cada paricipante del concurso.
int maximoFallosPermitidos(const concurso& c){
	return c.fallosMax;
}

//Devuelve el numero maximo de ganadores a seleccionar con el concurso.
int maximoNumeroGanadores(const concurso& c){
	return c.ganadoresMax;
}

//Devuelve verdad si el concurso c está en fase de Documentación.
bool enDocumentacion(const concurso& c){
	return c.estado==0;
}

//Devuelve verdad si el concurso c está en fase de Inscripción.
bool enInscripcion(const concurso& c){
	return c.estado==1;
}

//Devuelve verdad si el concurso c esta en fase de Juego.
bool enJuego(const concurso& c){
	return c.estado==2;
}

//Si en c no hay ninguna pregunta p con identificador IDpreg se anyade, sino se actualiza.
void anyadirPregunta(concurso& c, const int& IDpreg, const pregunta& p, bool& error){
	if(!enDocumentacion(c)){
		error = true;
	}
	else{
		error = false;
		introducir(c.colPreguntas,IDpreg,p);
	}
}

//Si la pregunta con identificador IDpreg esta en el concurso es borrada.
void borrarPregunta(concurso& c, int& IDpreg, bool& error){
	if(!enDocumentacion(c)){
		error = true;
	}
	else{
		error = false;
		borrar(c.colPreguntas,IDpreg);
	}
}

//Devuelve el numero total de preguntas del concurso c.
int totalPreguntas(const concurso& c){
	return tamanyo(c.colPreguntas);
}

//Devuelve verdad si en el concurso c hay alguna pregunta identificada con IDpreg.
bool existePregunta(const concurso& c, const int& IDpreg){
	return existeClave(c.colPreguntas,IDpreg);
}

//Si en el concurso c hay una pregunta identificada con IDpreg se devuelve.
void obtenerPregunta(const concurso& c, const int& IDpreg, pregunta& p, bool& error){
	obtenerDato(c.colPreguntas,IDpreg,p,error);
}

//Si en el concurso c hay una pregunta identificada con IDpreg, se devuelve verdad si la pregunta esta marcada como utilizada.
void preguntaUtilizada(const concurso& c, const int& IDpreg, bool& usado, bool& error){
	error = !existeClave(c.colPreguntas,IDpreg);
	//usado=true si y solo si la pregunta con identificador IDpreg tiene un tiempo marcado
	usado = tieneTiempo(c.colPreguntas,IDpreg);
}

//Si en el concurso c hay una pregunta identificada con IDpreg, se devuelve el instante de la ultima vez que ha sido utilizada.
void obtenerUltimoUsoPregunta(const concurso& c, const int& IDpreg, instante& i, bool& error){
	obtenerTiempo(c.colPreguntas,IDpreg,i,error);
}

//Si en el concurso c hay alguna pregunta identificada con IDpreg, se marcara como utilizada por ultima vez en el instante i.
void marcarPregunta(concurso& c, const int& IDpreg, const instante& i, bool& error){
	marcarTiempo(c.colPreguntas,IDpreg,i,error);
}

//Se inicia la fase de Inscripcion en el concurso.
void iniciarInscripcion(concurso& c){
	if(enDocumentacion(c) && totalPreguntas(c)>0){
		c.estado=1;
	}
}

//Si en el concurso c no hay ningun concursante identificado con IDconcursante sera anyadido, sino sera actualizado.
void anyadirConcursante(concurso& c, const string& IDconcursante, const participante& p, bool& error){
	if(!enInscripcion(c)){
		error = true;
	}
	else{
		error = false;
		anyadir(c.colParticipantes,IDconcursante,p,error);
	}
}

//Si en el concurso c hay algun concursante identificado con IDconcursante sera borrado.
void borrarConcursante(concurso& c, const string& IDconcursante, bool& error){
	if(!enInscripcion(c)){
		error = true;
	}
	else{
		error = false;
		quitar(c.colParticipantes,IDconcursante,error);
	}
}

//Devuelve verdad si en el concurso c hay algun concursante identificado con IDconcursante.
bool existeConcursante(concurso& c, const string& IDconcursante){
	participante p;
	bool error;
	buscar(c.colParticipantes,IDconcursante,p,error);	//error=true si no se encuentra el concursante
	return !error;
}

//Si en el concurso c hay un concursante identificado con IDconcursante, se devuelve la información de dicho concursante.
void obtenerInfoConcursante(concurso& c, const string& IDconcursante, participante& p, bool& error){
	buscar(c.colParticipantes,IDconcursante,p,error);
}

//Devuelve el numero total de concursantes que hay en el concurso c.
int totalConcursantes(concurso& c){
	return cardinal(c.colParticipantes);
}

//Se inicia la fase de Juego en el concurso.
void iniciarJuego(concurso& c){
	if(enInscripcion(c) && totalConcursantes(c)>maximoNumeroGanadores(c)){
		c.estado=2;
		cerrarInscripcion(c.colParticipantes);
	}
}

//Devuelve verdad si existe un concursante que actualmente tiene el turno para jugar.
bool existeConcursanteActual(concurso& c){
	return enJuego(c) && totalConcursantes(c)>0;
}

//Devuelve la cadena que corresponde al IDconcursante del concursante que actualmente tiene el turno para jugar.
void obtenerConcursanteActual(concurso& c, string& cadena, bool& error){
	if(!enJuego(c) || (enJuego(c) && totalConcursantes(c)==0)){
		error = true;
	}
	else{
		error = false;
		obtenerCandidatoSuClave(c.colParticipantes,cadena,error);	//error!=true porque siempre que el concurso esta en Juego la ronda esta en Seleccion y totalConcursantes(c)>0
	}
}

//Devuelve verdad si hay ganadores del concurso.
bool hayGanadores(concurso& c){
	return enJuego(c) && totalConcursantes(c)<=maximoNumeroGanadores(c);
}

//Pone a prueba con la pregunta identificada como IDpreg al concursante que tiene el turno, ademas marca la pregunta como ultima vez usada en el instante t.
void probarConcursanteActual(concurso& c, const int IDpreg, const instante& t, const int& resp, bool& error){
	if(!existePregunta(c,IDpreg) || resp<0 || 2<resp || !enJuego(c) || (enJuego(c) && totalConcursantes(c)==0)){
		error = true;
	}
	else{
		error = false;
		//se obtiene el participante que tiene el turno gracias a su clave
		string concursante;
		obtenerConcursanteActual(c,concursante,error);
		participante p;
		obtenerInfoConcursante(c,concursante,p,error);
		//concursante decide pasar
		if(resp==0){
			//participante p obtenido antes
			if(numPases(p)<maximoPasesPermitidos(c)){
				//se suma un pase al concursante y se actualiza el valor en la ronda del concurso
				sumarP(p);
				actualizarCandidato(c.colParticipantes,p,error);
				pasarTurno(c.colParticipantes,error);
			}
		}
		//concursante decide responder
		else{
			pregunta v;
			obtenerDato (c.colPreguntas,IDpreg,v,error);
			//respuesta correcta
			if(respuesta(v,resp)){
				//participante p obtenido antes
				//se suma un acierto al concursante y se actualiza el valor en la ronda del concurso
				sumarA(p);
				actualizarCandidato(c.colParticipantes,p,error);
			}
			//respuesta incorrecta
			else{
				//participante p obtenido antes
				//se suma un fallo al concursante y se actualiza el valor en la ronda del concurso
				sumarF(p);
				actualizarCandidato(c.colParticipantes,p,error);
				//caso de que haya que eliminar al concursante
				if(numFallos(p)==maximoFallosPermitidos(c)){
					eliminarCandidato(c.colParticipantes,error);
				}
			}
			pasarTurno(c.colParticipantes,error);
			marcarTiempo(c.colPreguntas,IDpreg,t,error);
		}
	}
}

//Devuelve una cadena que contiene la informacion de la coleccion de preguntas de c.
string listarPreguntas(concurso& c){
	string cadena = "--- LISTADO DE PREGUNTAS ---\nTOTAL preguntas: " + to_string(totalPreguntas(c)) + "\n";
	cadena += listar(c.colPreguntas);
	cadena += "------";
	return cadena;
}

//Devuelve una cadena que contiene la informacion de la coleccion de concursantes de c.
string listarConcursantes(concurso& c){
	string cadena = "-*- LISTADO DE CONCURSANTES -*-\nTOTAL concursantes: " + to_string(totalConcursantes(c)) + "\n";
	cadena += listar(c.colParticipantes);
	cadena += "-*-*-*-";
	return cadena;
}

//Devuelve una cadena que contiene la informacion del concurso c.
string listarConcurso(concurso& c){
	string cadena = "********** ESTADO del CONCURSO **********\nFASE: ";
	if(enDocumentacion(c)){cadena += "Documentacion";}
	else if(enInscripcion(c)){cadena += "Inscripcion";}
	else {cadena += "Juego";}
	cadena += "\nLIMITES maximos-> Pases: " + to_string(maximoPasesPermitidos(c));
	cadena += " Fallos: " + to_string(maximoFallosPermitidos(c));
	cadena += " Ganadores: " + to_string(maximoNumeroGanadores(c)) + "\n";
	if (enJuego(c)){
		cadena += "JUGANDO concursante: ";
		bool error;
		string concursante;
		participante pt;
		obtenerConcursanteActual(c,concursante,error);
		obtenerInfoConcursante(c,concursante,pt,error);
		if(error){
			cadena += "---\n";
		}
		else{
			cadena += concursante + "\n";
		}
	}
	cadena += listarConcursantes(c) + "\n" + listarPreguntas(c) + "\n" + "******************************";
	return cadena;
}
