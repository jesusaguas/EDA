//*****************************************************************
// File:   rondaSeleccion.h
// Author: Jesus Aguas, Sergio Costa
// Date:   noviembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#ifndef RONDA_H
#define RONDA_H

#include <string>

using namespace std;

/*
El tipo que se quiera utiliza como Valor debera tener una operacion :
	string info(const Valor& v), que devolvera una cadena con la información del participante.

El tipo que se quiera utilizar como clave deberá tener implementadas las operaciones:
	generaCadena(const Clave& c), que devolvera una cadena con la clave.
	sonIguales (const Clave& c1, const Clave& c2), que devolverá un booleano resultado de comparar ambas claves,
							el cual será 'true' solo si ambas claves son iguales.
	menorQue (const Clave& c1, const Clave& c2), que devolverá un booleano resultado de comparar ambas claves,
							el cual será 'true' solo si c1 es estrictamente menor que c2.
*/


template <typename Clave, typename Valor> struct ronda;


//----OPERACIONES PÚBLICAS----


//Devuelve una ronda de seleccion vacia, sin elementos, y en estado de Inscripcion
template <typename Clave, typename Valor> void crear (ronda<Clave, Valor>& r);

//Devuelve el numero de elementos en la ronda r
template <typename Clave, typename Valor> int cardinal (ronda<Clave, Valor>& r);

//Devuelve verdad si y solo si r no tiene elementos
template <typename Clave, typename Valor> bool esVacia (ronda<Clave, Valor>& r);

//Devuelve el valor asociado a la clave c en un par en r, error es true si no se ha encontrado
template <typename Clave, typename Valor> void buscar (ronda<Clave, Valor>& r, const Clave& c, Valor& v, bool& error);

//Devuelve verdad si y solo si r esta en estado de seleccion
template <typename Clave, typename Valor> bool enSeleccion (ronda<Clave, Valor>& r);

//Si en r no hay ningun par con clave c, devuelve una ronda igual a la resultante de añadir el
//par (c,v) a r; si en r hay un par (c,v'), entonces devuelve una ronda igual a la resultante
//de sustituir (c,v') por el par (c,v) en r
template <typename Clave, typename Valor> void anyadir (ronda<Clave, Valor>& r, const Clave& c, const Valor& v, bool& error);

//Si c esta en r, devuelve una ronda igual a la resultante de vorrar en r el par con clave c;
//si c no esta en r, devuelve una ronda igual a r
template <typename Clave, typename Valor> void quitar (ronda<Clave, Valor>& r, const Clave& c, bool& error);

//Si r esta en estado de Seleccion, devuelve una ronda igual a r; si no devuelve una ronda igual
//a la resultante de poner r en estado de Seleccion y ademas, si no es vacia, fijar el turno
//en el elemento de menor clave en la ronda r
template <typename Clave, typename Valor> void cerrarInscripcion (ronda<Clave, Valor>& r);

//Si r esta en estado de Seleccion, devuelve una ronda igual a la resultante de pasar el turno del
//elemento que actualmente tenga el turno al que le siga en el orden por clave, y teniendo en cuenta
//que si el que tenia el turno era el de mayor clave, el turno debera pasar al elemento de menor
//clave en r
template <typename Clave, typename Valor> void pasarTurno (ronda<Clave, Valor>& r, bool& error);

//Si esta en estado de seleccion devuelve el valor v del par (c,v) que tiene el turno en la ronda
template <typename Clave, typename Valor> void obtenerCandidatoSuValor (ronda<Clave, Valor>& r, Valor& v, bool& error);

//Si esta en estado de seleccion devuelve la clave c del par (c,v) que tiene el turno en la ronda
template <typename Clave, typename Valor> void obtenerCandidatoSuClave (ronda<Clave, Valor>& r, Clave& c, bool& error);

//Si esta en estado de seleccion devuelve una ronda igual a la resultante de actualizar en r el
//valor del elemento que tiene el turno, actualizandolo a v
template <typename Clave, typename Valor> void actualizarCandidato (ronda<Clave, Valor>& r, Valor& v, bool& error);

//Si esta en estado de seleccion devuelve una ronda iguala la respuesta resultante de eliminar
//de r el elemento que actualmente tenia el turno en r. Ademas, en el caso de que queden mas elementos
//en la ronda, en la ronda resultante debera tener el turno el elemento que seguia en r a aquel que tenia
//el turno (y que ha sido eliminado), teniendo en cuenta que si el que tenia el turno era el de mayor clave,
//el turno debera pasar al de menor clave de los que queden
template <typename Clave, typename Valor> void eliminarCandidato (ronda<Clave, Valor>& r, bool& error);

//Devuelve una cadena que contine la representacion, como cadenas de caracteres, de todos los
//elementos de la ronda r en orden por clave de menor a mayor
template <typename Clave, typename Valor> string listar (ronda<Clave, Valor>& r);

//Prepara el iterador y su cursor para que el siguiente elemento a visitar sea el primero
//de la ronda r (situacion de no haber visitado ningun elemento)
template <typename Clave, typename Valor> void iniciarIterador (ronda<Clave, Valor>& r);

//Devuelve falso si ya se ha visitado el ultimo elemento de r, devuelve verdad en caso
//contrario
template <typename Clave, typename Valor> bool existeSiguiente (const ronda<Clave, Valor>& r);

//Devuelve la clave y el valor del siguiente elemento de r, ademas de la ronda resultante de
//avanzar el cursor del iterador en r
template <typename Clave, typename Valor> void siguiente (ronda<Clave, Valor>& r, Clave& c, Valor& v, bool& error);


//--------------------------------------------------------------------------

template <typename Clave, typename Valor>
struct ronda{
  public:
	//funciones
    friend void crear<Clave, Valor> (ronda<Clave, Valor>& r);
    friend int cardinal<Clave, Valor> (ronda<Clave, Valor>& r);
    friend bool esVacia<Clave, Valor> (ronda<Clave, Valor>& r);
    friend void buscar<Clave, Valor> (ronda<Clave, Valor>& r, const Clave& c, Valor& v, bool& error);
    friend bool enSeleccion<Clave, Valor> (ronda<Clave, Valor>& r);
    friend void anyadir<Clave, Valor> (ronda<Clave, Valor>& r, const Clave& c, const Valor& v, bool& error);
    friend void quitar<Clave, Valor> (ronda<Clave, Valor>& r, const Clave& c, bool& error);
    friend void cerrarInscripcion<Clave, Valor> (ronda<Clave, Valor>& r);
    friend void pasarTurno<Clave, Valor> (ronda<Clave, Valor>& r, bool& error);
    friend void obtenerCandidatoSuValor<Clave, Valor> (ronda<Clave, Valor>& r, Valor& v, bool& error);
    friend void obtenerCandidatoSuClave<Clave, Valor> (ronda<Clave, Valor>& r, Clave& c, bool& error);
    friend void actualizarCandidato<Clave, Valor> (ronda<Clave, Valor>& r, Valor& v, bool& error);
    friend void eliminarCandidato<Clave, Valor> (ronda<Clave, Valor>& r, bool& error);
    friend string listar<Clave, Valor> (ronda<Clave, Valor>& r);
    friend void iniciarIterador<Clave, Valor> (ronda<Clave, Valor>& r);
    friend bool existeSiguiente<Clave, Valor> (const ronda<Clave, Valor>& r);
    friend void siguiente<Clave, Valor> (ronda<Clave, Valor>& r, Clave& c, Valor& v, bool& error);
    
  private:
  	//campos 
     struct Nodo {					//Cada nodo de la ronda está compuesto por un dato de tipo valor,
     	Valor valor;				//un dato de tipo clave, y un puntero al nodo siguiente.
     	Clave clave;
     	Nodo* siguiente;
     };
     
     Nodo* elPrimero;				//puntero que apunta al primer nodo de la lista
     Nodo* antPI;					//puntero que apunta al nodo anterior al que tiene el punto de interes
     int longitud;					//entero que representa el número de nodos de la ronda
     Nodo* iterador;				//puntero que apunta al nodo iterador
     bool seleccion;				//booleano que es cierto si y solo si la ronda está en modo seleccion
};

//--------------------------------------------------------------------------


//Devuelve una ronda de seleccion vacia, sin elementos, y en estado de Inscripcion
template <typename Clave, typename Valor> void crear (ronda<Clave, Valor>& r){
	r.elPrimero = NULL;
	r.antPI = NULL;
	r.iterador = NULL;
	r.longitud = 0;
	r.seleccion = false;
}


//Devuelve el numero de elementos en la ronda r
template <typename Clave, typename Valor> int cardinal (ronda<Clave, Valor>& r){
	return r.longitud;
}


//Devuelve verdad si no hay primer elemento en la ronda
template <typename Clave, typename Valor> bool esVacia (ronda<Clave, Valor>& r){
	return r.elPrimero==NULL;
}


//Devuelve el valor asociado a la clave c en un par en r, error es true si no se ha encontrado
template <typename Clave, typename Valor> void buscar (ronda<Clave, Valor>& r, const Clave& c, Valor& v, bool& error){
	typename ronda<Clave, Valor>::Nodo* pAux = r.elPrimero;
	while((pAux!=NULL)&&(menorQue (pAux->clave,c))){
		pAux = pAux->siguiente;
	}
	if(pAux==NULL){
		error = true;
	}
	else{
		if(sonIguales(pAux->clave,c)){
			v = pAux->valor;
			error = false;
		}
		else{
			error = true;
		}
	}
}


//Devuelve verdad si y solo si r esta en estado de seleccion
template <typename Clave, typename Valor> bool enSeleccion (ronda<Clave, Valor>& r){
	return r.seleccion;
}


//Si en la ronda no hay ningún nodo con clave c, añade dicho nodo, si ya existe un nodo con la misma clave, actualiza su valor
//error=true si y solo si la ronda esta en modo seleccion
template <typename Clave, typename Valor> void anyadir (ronda<Clave, Valor>& r, const Clave& c, const Valor& v, bool& error){
	if(!r.seleccion){
		error=false;
		typename ronda<Clave, Valor>::Nodo* pAux;
		if(r.elPrimero==NULL){
			r.elPrimero = new typename ronda<Clave, Valor>::Nodo;
			r.elPrimero->clave = c;
			r.elPrimero->valor = v;
			r.elPrimero->siguiente = NULL;
			r.longitud= 1;
		}
		else{
			if(menorQue (c,r.elPrimero->clave)){
				pAux = r.elPrimero;
				r.elPrimero = new typename ronda<Clave, Valor>::Nodo;
				r.elPrimero->clave = c;
				r.elPrimero->valor = v;
				r.elPrimero->siguiente = pAux;
				r.longitud = r.longitud + 1;
			}
			else{
				if(sonIguales (c,r.elPrimero->clave)){
					r.elPrimero->valor = v;
				}
				else{
					pAux = r.elPrimero;
					while((pAux->siguiente!=NULL) && (menorQue (pAux->siguiente->clave,c))){
						pAux = pAux->siguiente;
					}
					if((pAux->siguiente!=NULL) && (sonIguales(pAux->siguiente->clave,c))){
						pAux->siguiente->valor=v;
					}
					else{
						typename ronda<Clave, Valor>::Nodo* nuevo = new typename ronda<Clave, Valor>::Nodo;
						nuevo->clave = c;
						nuevo->valor = v;
						nuevo->siguiente = pAux->siguiente;
						pAux->siguiente = nuevo;
						r.longitud = r.longitud + 1; 
						
					}
				}
			}
		}
	}
	else{
		error = true;
	}
}


//Si c esta en r, devuelve una ronda igual a la resultante de vorrar en r el par con clave c;
//si c no esta en r, devuelve una ronda igual a r
template <typename Clave, typename Valor> void quitar (ronda<Clave, Valor>& r, const Clave& c, bool& error){
	if (!r.seleccion){											//si esta en seleccion
		error = false;
		if (r.elPrimero!=NULL){									//si no esta vacia
			if ((menorQue (r.elPrimero->clave,c))||(sonIguales (r.elPrimero->clave,c))){						//si no esta la clave
				if (sonIguales (r.elPrimero->clave,c)){					//si es la primera clave
					typename ronda<Clave, Valor>::Nodo* pAux1 = r.elPrimero;
					r.elPrimero = r.elPrimero->siguiente;
					delete(pAux1);
					r.longitud = r.longitud-1;
				}
				else{
					bool parar = false;
					typename ronda<Clave, Valor>::Nodo* pAux1;
					typename ronda<Clave, Valor>::Nodo* pAux2;
					pAux1 = r.elPrimero->siguiente;
					pAux2 = r.elPrimero;
					while((pAux1!=NULL) && !parar){
						if(menorQue (c,pAux1->clave)){
							parar = true;
						}
						else if(sonIguales (c,pAux1->clave)){
							pAux2->siguiente = pAux1->siguiente;
							delete(pAux1);
							parar = true;
							r.longitud = r.longitud-1;
						}
						else{
							pAux2 = pAux1;
							pAux1 = pAux1->siguiente;
						}
					}
				}
			}
		}
	}
	else{
		error=true;
	}
}


//Si r esta en estado de Seleccion, devuelve una ronda igual a r; si no devuelve una ronda igual
//a la resultante de poner r en estado de Seleccion y ademas, si no es vacia, fijar el turno
//en el elemento de menor clave en la ronda r
template <typename Clave, typename Valor> void cerrarInscripcion (ronda<Clave, Valor>& r){
	if(!r.seleccion){
		r.seleccion = true;
		r.antPI = NULL;
	}
}


//Si r esta en estado de Seleccion, devuelve una ronda igual a la resultante de pasar el turno del
//elemento que actualmente tenga el turno al que le siga en el orden por clave, y teniendo en cuenta
//que si el que tenia el turno era el de mayor clave, el turno debera pasar al elemento de menor
//clave en r
template <typename Clave, typename Valor> void pasarTurno (ronda<Clave, Valor>& r, bool& error){
	if (!r.seleccion || r.elPrimero==NULL){
		error = true;
	}
	else{
		error = false;
		if (r.antPI==NULL && r.elPrimero->siguiente==NULL){}	//si solo hay un elemento
		else if(r.antPI==NULL){									//si el punto de interes esta en el primer elemento
			r.antPI=r.elPrimero;
		}
		else if (r.antPI->siguiente->siguiente==NULL){			//si el punto de interes esta en el ultimo elemento
			r.antPI = NULL;
		}
		else{													//si el punto de interes NO esta en el ultimo elemento
			r.antPI = r.antPI->siguiente;
		}
	}
}


//Si esta en estado de seleccion devuelve el valor v del par (c,v) que tiene el turno en la ronda
template <typename Clave, typename Valor> void obtenerCandidatoSuValor (ronda<Clave, Valor>& r, Valor& v, bool& error){
	if (!r.seleccion || r.elPrimero==NULL){
		error = true;
	}
	else{
		error = false;
		if(r.antPI==NULL){
			v = r.elPrimero->valor;
		}
		else{
			v = r.antPI->siguiente->valor;
		}
	}
}


//Si esta en estado de seleccion devuelve la clave c del par (c,v) que tiene el turno en la ronda
template <typename Clave, typename Valor> void obtenerCandidatoSuClave (ronda<Clave, Valor>& r, Clave& c, bool& error){
	if (!r.seleccion || r.elPrimero==NULL){
		error = true;
	}
	else{
		error = false;
		if(r.antPI==NULL){
			c = r.elPrimero->clave;
		}
		else{
			c = r.antPI->siguiente->clave;
		}
	}
}


//Si esta en estado de seleccion devuelve una ronda igual a la resultante de actualizar en r el
//valor del elemento que tiene el turno, actualizandolo a v
template <typename Clave, typename Valor> void actualizarCandidato (ronda<Clave, Valor>& r, Valor& v, bool& error){
	if(!r.seleccion || r.elPrimero==NULL){
		error = true;
	}
	else{
		error = false;
		if(r.antPI==NULL){
			r.elPrimero->valor = v;
		}
		else{
			r.antPI->siguiente->valor = v;
		}
	}
}


//Si esta en estado de seleccion devuelve una ronda iguala la respuesta resultante de eliminar
//de r el elemento que actualmente tenia el turno en r. Ademas, en el caso de que queden mas elementos
//en la ronda, en la ronda resultante debera tener el turno el elemento que seguia en r a aquel que tenia
//el turno (y que ha sido eliminado), teniendo en cuenta que si el que tenia el turno era el de mayor clave,
//el turno debera pasar al de menor clave de los que queden
template <typename Clave, typename Valor> void eliminarCandidato (ronda<Clave, Valor>& r, bool& error){
	if (!r.seleccion || r.elPrimero==NULL){
		error = true;
	}
	else{
		error = false;
		if(r.antPI==NULL){
			typename ronda<Clave, Valor>::Nodo* pAux = r.elPrimero;
			r.elPrimero = r.elPrimero->siguiente;
			delete(pAux);
			r.longitud = r.longitud-1;
		}
		else{
			typename ronda<Clave, Valor>::Nodo* pAux = r.antPI->siguiente->siguiente;
			delete(r.antPI->siguiente);
			r.antPI->siguiente = pAux;
			r.longitud = r.longitud-1;
			if(r.antPI->siguiente==NULL){
				r.antPI=NULL;
			}
		}
	}
}


//Devuelve una cadena que contine la representacion, como cadenas de caracteres, de todos los
//elementos de la ronda r en orden por clave de menor a mayor
template <typename Clave, typename Valor> string listar (ronda<Clave, Valor>& r){
	iniciarIterador(r);
	string cadena = "";
	Clave c;
	Valor v;
	bool error;
	while(existeSiguiente(r)){
		siguiente(r,c,v,error);
		cadena = cadena + "[" + generaCadena(c) + ":::" + info(v) + "]\n";
	}
	return cadena;
}


//Prepara el iterador y su cursor para que el siguiente elemento a visitar sea el primero
//de la ronda r (situacion de no haber visitado ningun elemento)
template <typename Clave, typename Valor> void iniciarIterador (ronda<Clave, Valor>& r){
	r.iterador = NULL;
}



//Devuelve falso si ya se ha visitado el ultimo elemento de r, devuelve verdad en caso
//contrario
template <typename Clave, typename Valor> bool existeSiguiente (const ronda<Clave, Valor>& r){
	if (r.iterador==NULL){
		return r.elPrimero!=NULL;
	}
	else if (r.iterador->siguiente==NULL){
		return false;
	}
	else{
		return true;
	}
}


//Devuelve la clave y el valor del siguiente elemento de r, ademas de la ronda resultante de
//avanzar el cursor del iterador en r
template <typename Clave, typename Valor> void siguiente (ronda<Clave, Valor>& r, Clave& c, Valor& v, bool& error){
	if (r.iterador==NULL){
		error = false;
		c = r.elPrimero->clave;
		v = r.elPrimero->valor;
		r.iterador = r.elPrimero;
	}
	else if (r.iterador->siguiente==NULL){
		error = true;
	}
	else{
		error = false;
		c = r.iterador->siguiente->clave;
		v = r.iterador->siguiente->valor;
		r.iterador = r.iterador->siguiente;
	}
}


#endif
