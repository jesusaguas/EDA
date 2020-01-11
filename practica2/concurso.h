//*****************************************************************
// File:   concurso.h
// Author: Jesus Aguas, Sergio Costa
// Date:   diciembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include "participante.h"
#include "instantes.h"
#include "preguntas.h"
#include "utilidades.h"
#include "rondaSeleccion.h"
#include "cmt.h"


struct concurso;


//----OPERACIONES PUBLICAS----

//Inicializa el concurso c.
void crearConcurso(const int& PMax, const int& FMax, const int& numGmax, concurso& c);

//Devuelve el numero total de pases que se permitira a cada participante del concurso.
int maximoPasesPermitidos(const concurso& c);

//Devuelve el numero total de fallos con los que se descalificara a cada paricipante del concurso.
int maximoFallosPermitidos(const concurso& c);

//Devuelve el numero maximo de ganadores a seleccionar con el concurso.
int maximoNumeroGanadores(const concurso& c);

//Devuelve verdad si el concurso c está en fase de Documentación.
bool enDocumentacion(const concurso& c);

//Devuelve verdad si el concurso c está en fase de Inscripción.
bool enInscripcion(const concurso& c);

//Devuelve verdad si el concurso c esta en fase de Juego.
bool enJuego(const concurso& c);

//Si en c no hay ninguna pregunta p con identificador IDpreg se anyade, sino se actualiza.
void anyadirPregunta(concurso& c, const int& IDpreg, const pregunta& p, bool& error);

//Si la pregunta con identificador IDpreg esta en el concurso es borrada.
void borrarPregunta(concurso& c, int& IDpreg, bool& error);

//Devuelve el numero total de preguntas del concurso c.
int totalPreguntas(const concurso& c);

//Devuelve verdad si en el concurso c hay alguna pregunta identificada con IDpreg.
bool existePregunta(const concurso& c, const int& IDpreg);

//Si en el concurso c hay una pregunta identificada con IDpreg se devuelve.
void obtenerPregunta(const concurso& c, const int& IDpreg, pregunta& p, bool& error);

//Si en el concurso c hay una pregunta identificada con IDpreg, se devuelve verdad si la pregunta esta marcada como utilizada.
void preguntaUtilizada(const concurso& c, const int& IDpreg, bool& usado, bool& error);

//Si en el concurso c hay una pregunta identificada con IDpreg, se devuelve el instante de la ultima vez que ha sido utilizada.
void obtenerUltimoUsoPregunta(const concurso& c, const int& IDpreg, instante& i, bool& error);

//Si en el concurso c hay alguna pregunta identificada con IDpreg, se marcara como utilizada por ultima vez en el instante i.
void marcarPregunta(concurso& c, const int& IDpreg, const instante& i, bool& error);

//Se inicia la fase de Inscripcion en el concurso.
void iniciarInscripcion(concurso& c);

//Si en el concurso c no hay ningun concursante identificado con IDconcursante sera anyadido, sino sera actualizado.
void anyadirConcursante(concurso& c, const string& IDconcursante, const participante& p, bool& error);

//Si en el concurso c hay algun concursante identificado con IDconcursante sera borrado.
void borrarConcursante(concurso& c, const string& IDconcursante, bool& error);

//Devuelve verdad si en el concurso c hay algun concursante identificado con IDconcursante.
bool existeConcursante(concurso& c, const string& IDconcursante);

//Si en el concurso c hay un concursante identificado con IDconcursante, se devuelve la información de dicho concursante.
void obtenerInfoConcursante(concurso& c, const string& IDconcursante, participante& p, bool& error);

//Devuelve el numero total de concursantes que hay en el concurso c.
int totalConcursantes(concurso& c);

//Se inicia la fase de Juego en el concurso.
void iniciarJuego(concurso& c);

//Devuelve verdad si existe un concursante que actualmente tiene el turno para jugar.
bool existeConcursanteActual(concurso& c);

//Devuelve la cadena que corresponde al IDconcursante del concursante que actualmente tiene el turno para jugar.
void obtenerConcursanteActual(concurso& c, string& cadena, bool& error);

//Devuelve verdad si hay ganadores del concurso.
bool hayGanadores(concurso& c);

//Pone a prueba con la pregunta identificada como IDpreg al concursante que tiene el turno, ademas marca la pregunta como ultima vez usada en el instante t.
void probarConcursanteActual(concurso& c, const int IDpreg, const instante& t, const int& resp, bool& error);

//Devuelve una cadena que contiene la informacion de la coleccion de preguntas de c.
string listarPreguntas(concurso& c);

//Devuelve una cadena que contiene la informacion de la coleccion de concursantes de c.
string listarConcursantes(concurso& c);

//Devuelve una cadena que contiene la informacion del concurso c.
string listarConcurso(concurso& c);


//--------------------------------------------------------------------------


struct concurso{

//funciones
public:

friend void crearConcurso(const int& PMax, const int& FMax, const int& numGmax, concurso& c);
friend int maximoPasesPermitidos(const concurso& c);
friend int maximoFallosPermitidos(const concurso& c);
friend int maximoNumeroGanadores(const concurso& c);
friend bool enDocumentacion(const concurso& c);
friend bool enInscripcion(const concurso& c);
friend bool enJuego(const concurso& c);
friend void anyadirPregunta(concurso& c, const int& IDpreg, const pregunta& p, bool& error);
friend void borrarPregunta(concurso& c, int& IDpreg, bool& error);
friend int totalPreguntas(const concurso& c);
friend bool existePregunta(const concurso& c, const int& IDpreg);
friend void obtenerPregunta(const concurso& c, const int& IDpreg, pregunta& p, bool& error);
friend void preguntaUtilizada(const concurso& c, const int& IDpreg, bool& usado, bool& error);
friend void obtenerUltimoUsoPregunta(const concurso& c, const int& IDpreg, instante& i, bool& error);
friend void marcarPregunta(concurso& c, const int& IDpreg, const instante& i, bool& error);
friend void iniciarInscripcion(concurso& c);
friend void anyadirConcursante(concurso& c, const string& IDconcursante, const participante& p, bool& error);
friend void borrarConcursante(concurso& c, const string& IDconcursante, bool& error);
friend bool existeConcursante(concurso& c, const string& IDconcursante);
friend void obtenerInfoConcursante(concurso& c, const string& IDconcursante, participante& p, bool& error);
friend int totalConcursantes(concurso& c);
friend void iniciarJuego(concurso& c);
friend bool existeConcursanteActual(concurso& c);
friend void obtenerConcursanteActual(concurso& c, string& cadena, bool& error);
friend bool hayGanadores(concurso& c);
friend void probarConcursanteActual(concurso& c, const int IDpreg, const instante& t, const int& resp, bool& error);
friend string listarPreguntas(concurso& c);
friend string listarConcursantes(concurso& c);
friend string listarConcurso(concurso& c);

//-----------------------------------------------------------------------------------------------------------------------

private:
//campos
	int pasesMax, fallosMax, ganadoresMax;			//enteros que representan los valores maximos de los pases, fallos y ganadores
	int estado; 									//0 si Documentacion, 1 si Inscripcion, 2 si Juego
	ronda<string, participante> colParticipantes;	//ronda privada del concurso
	cmt<int, pregunta, instante> colPreguntas;		//coleccion con marca de tiempo privada del concurso

};
