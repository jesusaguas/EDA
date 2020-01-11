//*****************************************************************
// File:   cmt.h
// Author: Jesus Aguas, Sergio Costa
// Date:   diciembre 2017
// Coms:   Practica 2 de EDA
//*****************************************************************

#ifndef CMT_H
#define CMT_H

#include <string>

using namespace std;

/*
El tipo que se quiera utiliza como Dato debera tener una operacion :
	generaCadena(const Dato& v), que devolvera una cadena que represente el Dato.
	
El tipo que se quiera utiliza como Tiempo debera tener una operacion :
	generaCadena(const Tiempo& t), que devolvera una cadena que represente el Tiempo.

El tipo que se quiera utilizar como Clave deberá tener implementadas las operaciones:
	generaCadena(const Clave& o), que devolvera una cadena con la Clave.
	igualClave(const Clave& o1, const Clave& o2), que de devolvera cierto si y solo si o1=o2
	mayorClave(const Clave& o1, const Clave& o2), que de devolvera cierto si y solo si o1>o2
*/


template <typename Clave, typename Dato, typename Tiempo> struct cmt;



//----OPERACIONES PÚBLICAS----


//Crea una coleccion vacia, sin ternas
template <typename Clave, typename Dato, typename Tiempo> void crear (cmt<Clave, Dato, Tiempo>& c);

//Devuelve verdad si y solo si c no contiene ninguna terna
template <typename Clave, typename Dato, typename Tiempo> bool esVacio (const cmt<Clave, Dato, Tiempo>& c);

//Devuelve verdad si y solo si en c existe una terna con clave k
template <typename Clave, typename Dato, typename Tiempo> bool existeClave (const cmt<Clave, Dato, Tiempo>& c, const Clave& k);

//Si en c no existe ninguna terna con clave k (not existeClave(c,k)),
//devuelve la colección resultante de añadir en c una terna (k,v,-).
//Si en c ya existe una terna (k,v1,t) o (k,v1,-) entonces devuelve
//la colección resultante de susituir dicha terna en c, por una terna (k,v,-)
template <typename Clave, typename Dato, typename Tiempo> void introducir (cmt<Clave, Dato, Tiempo>& c, const Clave& k, const Dato& v);

//Si en c existe una terna con clave k y un valor de tiempo asignado (k,v,t), devuelve verdad.
//En cualquier otro caso, devuelve falso.
template <typename Clave, typename Dato, typename Tiempo> bool tieneTiempo (const cmt<Clave, Dato, Tiempo>& c,const Clave& k);

//Si en c existe una terna (k,v,t) o (k,v,-), devuelve su dato v.
//Parcial: la operación no está definida si not existeClave(c,k).
template <typename Clave, typename Dato, typename Tiempo> void obtenerDato (const cmt<Clave, Dato, Tiempo>& c, const Clave& k, Dato& v, bool& error);

//Si en c existe una terna (k,v,t) devuelve su valor t.
//Parcial: la operación no está definida si not existeClave(c,k) o si not tieneTiempo(c,k).
template <typename Clave, typename Dato, typename Tiempo> void obtenerTiempo (const cmt<Clave, Dato, Tiempo>& c, const Clave& k, Tiempo& t, bool& error);

//Si en c ya existe una terna (k,v,t1) o (k,v,-), entonces devuelve la colección resultante de sustituir
//dicha terna en c, por una terna (k,v,t).
//Parcial: la operación no está definida si not existeClave(c,k).
template <typename Clave, typename Dato, typename Tiempo> void marcarTiempo (cmt<Clave, Dato, Tiempo>& c, const Clave& k, const Tiempo& t, bool& error);

//Si en c existe una terna con clave k, entonces devuelve una colección igual a la resultante de
//eliminar de c la terna con clave k.
//Si not existeClave(c,k), devuelve una colección igual a c.
template <typename Clave, typename Dato, typename Tiempo> void borrar (cmt<Clave, Dato, Tiempo>& c, const Clave& k);

//Devuelve el nº de ternas en la colección c.
template <typename Clave, typename Dato, typename Tiempo> int tamanyo (const cmt<Clave, Dato, Tiempo>& c);

//Devuelve una cadena que contine la representacion, como cadenas de caracteres,
//de todas las ternas de c en orden por clave de menor a mayor
template <typename Clave, typename Dato, typename Tiempo> string listar (cmt<Clave, Dato, Tiempo>& c);

//Inicializa el iterador para recorrer las ternas de la colección c, de forma que
//la siguiente terna a visitar sea la primera (situación de no haber visitado ninguna terna).
template <typename Clave, typename Dato, typename Tiempo> void iniciarIterador (cmt<Clave, Dato, Tiempo>& c);

//Devuelve verdad si y sólo si queda alguna terna por visitar con el iterador de la colección c.
template <typename Clave, typename Dato, typename Tiempo> bool existeSiguiente (const cmt<Clave, Dato, Tiempo>& c);

//Devuelve la clave, el dato y el tiempo de la siguiente terna de c, ademas del cmt resultante de
//avanzar el cursor del iterador en c
template <typename Clave, typename Dato, typename Tiempo> void siguiente (cmt<Clave, Dato, Tiempo>& c, Clave& k, Dato& v, Tiempo& t, bool& error);




//----OPERACIONES PRIVADAS----

template <typename Clave, typename Dato, typename Tiempo> bool existeClave2 (const Clave& k, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
template <typename Clave, typename Dato, typename Tiempo> bool introducir2 (const Clave& k, const Dato& v, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux,typename cmt<Clave, Dato, Tiempo>::Terna*& pAux2);
template <typename Clave, typename Dato, typename Tiempo> bool tieneTiempo2 (const Clave& k, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
template <typename Clave, typename Dato, typename Tiempo> void obtenerDato2 (const Clave& k, Dato& v, bool& error, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
template <typename Clave, typename Dato, typename Tiempo> void obtenerTiempo2 (const Clave& k, Tiempo& t, bool& error, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
template <typename Clave, typename Dato, typename Tiempo> void marcarTiempo2 (const Clave& k, const Tiempo& t, bool& error, typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
template <typename Clave, typename Dato, typename Tiempo> void max (typename cmt<Clave, Dato, Tiempo>::Terna*& pAux);
template <typename Clave, typename Dato, typename Tiempo> void min (typename cmt<Clave, Dato, Tiempo>::Terna*& pAux);
template <typename Clave, typename Dato, typename Tiempo> bool borrar2 (const Clave& k, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux,typename cmt<Clave, Dato, Tiempo>::Terna*& pAux2);




//--------------------------------------------------------------------------

template <typename Clave, typename Dato, typename Tiempo>
struct cmt{
  public:
    friend void crear<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c);
    friend bool esVacio<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c);
    friend bool existeClave<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c, const Clave& k);
    friend void introducir<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c, const Clave& k, const Dato& v);
    friend bool tieneTiempo<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c, const Clave& k);
    friend void obtenerDato<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c, const Clave& k, Dato& v, bool& error);
    friend void obtenerTiempo<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c, const Clave& k, Tiempo& t, bool& error);
    friend void marcarTiempo<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c, const Clave& k, const Tiempo& t, bool& error);
    friend void borrar<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c, const Clave& k);
    friend int tamanyo<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c);
    friend string listar<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c);
    friend void iniciarIterador<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c);
    friend bool existeSiguiente<Clave, Dato, Tiempo> (const cmt<Clave, Dato, Tiempo>& c);
    friend void siguiente<Clave, Dato, Tiempo> (cmt<Clave, Dato, Tiempo>& c, Clave& k, Dato& v, Tiempo& t, bool& error);
    
  private: 
	
	struct Terna {					//Cada elemento de la coleccion consiste en una terna
     	Clave clave;				//Contiene un dato de tipo clave
     	Dato dato;					//Contiene un dato de tipo dato
     	Tiempo tiempo;				//Contiene un dato de tipo tiempo
     	Terna* izq;					//puntero que apunta a la terna que le sigue a la izquierda (siguiendo un modelo ABB)
     	Terna* dcho;				//puntero que apunta a la terna que le sigue a la derecha (siguiendo un modelo ABB)
		Terna* padre;				//puntero que apunta a la terna que le precede
		bool marcaTiempo;			//booleano que es cierto si y solo si la terna contiene un tiempo válido
     };
     
     Terna* raiz;					//puntero que apunta al primer elemento de la coleccion
     int tamanyo;					//entero que representa el numero total de elementos de la coleccion
     Terna* iterador;				//puntero que apunta al elemento en el que está el iterador


	friend bool introducir2<Clave, Dato, Tiempo> (const Clave& k, const Dato& v, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux,typename cmt<Clave, Dato, Tiempo>::Terna*& pAux2);
    friend bool existeClave2<Clave, Dato, Tiempo> (const Clave& k, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
	friend bool tieneTiempo2<Clave, Dato, Tiempo> (const Clave& k, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);    
	friend void obtenerDato2<Clave, Dato, Tiempo> (const Clave& k, Dato& v, bool& error, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
	friend void obtenerTiempo2<Clave, Dato, Tiempo> (const Clave& k, Tiempo& t, bool& error, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
	friend void marcarTiempo2<Clave, Dato, Tiempo> (const Clave& k, const Tiempo& t, bool& error, typename cmt<Clave, Dato, Tiempo>::Terna* pAux);
    friend void max<Clave, Dato, Tiempo> (typename cmt<Clave, Dato, Tiempo>::Terna*& pAux);
    friend void min<Clave, Dato, Tiempo> (typename cmt<Clave, Dato, Tiempo>::Terna*& pAux);
    friend bool borrar2<Clave, Dato, Tiempo> (const Clave& k, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux2);

};

//--------------------------------------------------------------------------

//Crea una arbol (ABB) c vacio, sin ternas
template <typename Clave, typename Dato, typename Tiempo> void crear (cmt<Clave, Dato, Tiempo>& c){
	c.raiz = NULL;
	c.tamanyo = 0;
}


//Devuelve verdad si y solo si el arbol c esta vacio, no contiene ninguna terna
template <typename Clave, typename Dato, typename Tiempo> bool esVacio (const cmt<Clave, Dato, Tiempo>& c){
	return c.raiz==NULL;
}


//Función auxiliar para poder utilizar recursión inmersiva en la función existeClave(), devuelve un booleano que indica lo mismo que existeClave().
template <typename Clave, typename Dato, typename Tiempo> bool existeClave2 (const Clave& k, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux){
	if(pAux==NULL){															//Clave no encontrada
		return false;
	}
	if(igualClave(k,pAux->clave)){											//Terna con clave k encontrada
		return true;
	}	
	else if(mayorClave(k,pAux->clave)){										//Buscamos en el hijo derecho
		return existeClave2<Clave,Dato,Tiempo>(k,pAux->dcho);
	}
	else{																	//Buscamos en el hijo izquierdo
		return existeClave2<Clave,Dato,Tiempo>(k,pAux->izq);
	}
}


//Devuelve verdad si y solo si en el arbol c existe una terna con clave k
template <typename Clave, typename Dato, typename Tiempo> bool existeClave (const cmt<Clave, Dato, Tiempo>& c, const Clave& k){
	return existeClave2<Clave,Dato,Tiempo>(k,c.raiz);						//Recursión inmersiva
}




//Función auxiliar para poder utilizar recursión inmersiva en la función introducir(), devuelve un booleano
//que indica cierto,si y solo si, se ha introducido una terna nueva en el arbol c
template <typename Clave, typename Dato, typename Tiempo> bool introducir2 (const Clave& k, const Dato& v, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux,typename cmt<Clave, Dato, Tiempo>::Terna*& pAux2){
	if(pAux==NULL){																	//Insertamos nuevo elemento
		pAux = new typename cmt<Clave, Dato, Tiempo>::Terna;
		pAux->clave = k;
		pAux->dato = v;
		pAux->marcaTiempo = false;
		pAux->izq = NULL;
		pAux->dcho = NULL;
		pAux->padre=pAux2;
		return true;
	}
	else if(igualClave(k,pAux->clave)){												//si tenemos que sustituir el elemento con la misma clave
		pAux->dato = v;
		pAux->marcaTiempo = false;
		return false;
	}
	else if(mayorClave(k,pAux->clave)){												//buscamos en el hijo derecho
		introducir2<Clave,Dato,Tiempo>(k,v,pAux->dcho,pAux);
	}
	else{																			//buscamos en el hijo izquierdo
		introducir2<Clave,Dato,Tiempo>(k,v,pAux->izq,pAux);
	}
}


//Si en el arbol c no existe ninguna terna con clave k, añade en el árbol una terna de clave k, dato v y sin marca de tiempo.
//Si en el arbol ya existe una terna de clave k, entonces cambia el dato de dicha terna a v, y sin marca de tiempo.
template <typename Clave, typename Dato, typename Tiempo> void introducir (cmt<Clave, Dato, Tiempo>& c, const Clave& k, const Dato& v){
	typename cmt<Clave, Dato, Tiempo>::Terna* pAux2 = NULL;				//Puntero auxiliar que guardará el padre en cada invocación recursiva
	if(introducir2<Clave,Dato,Tiempo>(k,v,c.raiz,pAux2)){
		c.tamanyo++;
	}
}




//Función auxiliar para poder utilizar recursión inmersiva en la función tieneTiempo(), devuelve un booleano que indica lo mismo que tieneTiempo().
template <typename Clave, typename Dato, typename Tiempo> bool tieneTiempo2 (const Clave& k, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux){
	if(pAux==NULL){															//Clave no encontrada
		return false;
	}
	else if(igualClave(k,pAux->clave)){										//Terna con clave k encontrada
		if(pAux->marcaTiempo){												//Tiene marca de tiempo
			return true;
		}
		else{																//No tiene marca de tiempo
			return false;
		}
	}	
	else if(mayorClave(k,pAux->clave)){										//Buscamos en el hijo derecho
		return tieneTiempo2<Clave,Dato,Tiempo>(k,pAux->dcho);
	}
	else{																	//Buscamos en el hijo izquierdo
		return tieneTiempo2<Clave,Dato,Tiempo>(k,pAux->izq);
	}
}

	
//Si en el arbol c existe una terna con clave k y tiene marca de tiempo devuelve cierto.
//En cualquier otro caso, devuelve falso.
template <typename Clave, typename Dato, typename Tiempo> bool tieneTiempo (const cmt<Clave, Dato, Tiempo>& c, const Clave& k){
	return tieneTiempo2<Clave,Dato,Tiempo>(k,c.raiz);
}


//Función auxiliar para poder utilizar recursión inmersiva en la función obtenerDato()
template <typename Clave, typename Dato, typename Tiempo> void obtenerDato2 (const Clave& k, Dato& v, bool& error, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux){
	if(pAux==NULL){															//Clave no encontrada		
		error = true;
	}
	else if(igualClave(k,pAux->clave)){										//Terna con clave k encontrada
		v = pAux->dato;
		error = false;
	}	
	else if(mayorClave(k,pAux->clave)){										//Buscamos en el hijo derecho
		obtenerDato2<Clave,Dato,Tiempo>(k,v,error,pAux->dcho);
	}
	else{																	//Buscamos en el hijo izquierdo
		obtenerDato2<Clave,Dato,Tiempo>(k,v,error,pAux->izq);
	}
}

//Si en el arbol c existe una terna con clave k, devuelve su dato v. (error=false)
//Si no existe, error=true.
template <typename Clave, typename Dato, typename Tiempo> void obtenerDato (const cmt<Clave, Dato, Tiempo>& c, const Clave& k, Dato& v, bool& error){
	obtenerDato2<Clave,Dato,Tiempo>(k,v,error,c.raiz);
}


//Función auxiliar para poder utilizar recursión inmersiva en la función obtenerTiempo()
template <typename Clave, typename Dato, typename Tiempo> void obtenerTiempo2 (const Clave& k, Tiempo& t, bool& error, const typename cmt<Clave, Dato, Tiempo>::Terna* pAux){
	if(pAux==NULL){															//Clave no encontrada		
		error = true;
	}
	else if(igualClave(k,pAux->clave)){										//Terna con clave k encontrada
		if(pAux->marcaTiempo){												//La terna tiene un tiempo definido
			t = pAux->tiempo;
			error = false;
		}
		else{																//La terna no tiene un tiempo definido
			error = true;
		}
	}	
	else if(mayorClave(k,pAux->clave)){										//Buscamos en el hijo derecho
		obtenerTiempo2<Clave,Dato,Tiempo>(k,t,error,pAux->dcho);
	}
	else{																	//Buscamos en el hijo izquierdo
		obtenerTiempo2<Clave,Dato,Tiempo>(k,t,error,pAux->izq);
	}
}

//Si en el arbol c existe una terna de clave k devuelve su valor t. (error=false)
//Si no existe clave o no tiene tiempo, error=true.
template <typename Clave, typename Dato, typename Tiempo> void obtenerTiempo (const cmt<Clave, Dato, Tiempo>& c, const Clave& k, Tiempo& t, bool& error){
	obtenerTiempo2<Clave,Dato,Tiempo>(k,t,error,c.raiz);
}


//Función auxiliar para poder utilizar recursión inmersiva en la función marcarTiempo()
template <typename Clave, typename Dato, typename Tiempo> void marcarTiempo2 (const Clave& k, const Tiempo& t, bool& error, typename cmt<Clave, Dato, Tiempo>::Terna* pAux){
	if(pAux==NULL){															//Clave no encontrada		
		error = true;
	}
	else if(igualClave(k,pAux->clave)){										//Terna con clave k encontrada
		pAux->tiempo = t;
		pAux->marcaTiempo = true;
		error = false;
	}	
	else if(mayorClave(k,pAux->clave)){										//Buscamos en el hijo derecho
		marcarTiempo2<Clave,Dato,Tiempo>(k,t,error,pAux->dcho);
	}
	else{																	//Buscamos en el hijo izquierdo
		marcarTiempo2<Clave,Dato,Tiempo>(k,t,error,pAux->izq);
	}
}


//Si en el arbol c existe una terna con clave k cambia su tiempo a t. (error=false)
//Si no existe ninguna terna en el arbol con clave k, error=true
template <typename Clave, typename Dato, typename Tiempo> void marcarTiempo (cmt<Clave, Dato, Tiempo>& c, const Clave& k, const Tiempo& t, bool& error){
	marcarTiempo2<Clave,Dato,Tiempo>(k,t,error,c.raiz);
}


//Desplaza el puntero por el arbol hasta llegar a el elemento con clave mayor
template <typename Clave, typename Dato, typename Tiempo> void max (typename cmt<Clave, Dato, Tiempo>::Terna*& pAux){
	if(pAux->dcho!=NULL){
		pAux=pAux->dcho;
		max<Clave,Dato,Tiempo>(pAux);
	}
}


//Desplaza el puntero por el arbol hasta llegar a el elemento con clave menor
template <typename Clave, typename Dato, typename Tiempo> void min (typename cmt<Clave, Dato, Tiempo>::Terna*& pAux){
	if(pAux->izq!=NULL){
		pAux=pAux->izq;
		min<Clave,Dato,Tiempo>(pAux);
	}
}



//Función auxiliar para poder utilizar recursión inmersiva en la función borrar(), devuelve un booleano
//que indica cierto, si y solo si, se ha borrado exitosamente una terna con clave k del arbol c.
template <typename Clave, typename Dato, typename Tiempo> bool borrar2 (const Clave& k, typename cmt<Clave, Dato, Tiempo>::Terna*& pAux,typename cmt<Clave, Dato, Tiempo>::Terna*& pAux2){
	if(pAux!=NULL){
		if(igualClave(k,pAux->clave)){											//Terna con clave k encontrada							
			if(pAux->izq==NULL){												//Borramos la terna
				typename cmt<Clave, Dato, Tiempo>::Terna* pAuxBORRAR = pAux;
				pAux=pAux->dcho;
				if(pAux!=NULL){pAux->padre=pAux2;}
				delete(pAuxBORRAR);	
				return true;
			}
			else{																//Sustituimos la terna a borrar, por la que tiene la clave más grande de su hijo izquierdo,
				typename cmt<Clave, Dato, Tiempo>::Terna* pAuxHoja = pAux->izq;	//la terna que apunta pAux y la terna a la que apunta pAuxHoja, respectivamente.
				max<Clave,Dato,Tiempo>(pAuxHoja);
				pAux->clave = pAuxHoja->clave;
				pAux->dato = pAuxHoja->dato;
				pAux->tiempo = pAuxHoja->tiempo;
				borrar2<Clave,Dato,Tiempo>(pAuxHoja->clave,pAux->izq,pAux);
			}
		}	
		else if(mayorClave(k,pAux->clave)){										//Buscamos en el hijo derecho
			borrar2<Clave,Dato,Tiempo>(k,pAux->dcho,pAux);
		}
		else{																	//Buscamos en el hijo izquierdo
			borrar2<Clave,Dato,Tiempo>(k,pAux->izq,pAux);
		}
	}
	else{																		//Ninguna terna con clave k
		return false;
	}
}


//Si en el arbol c existe una terna con clave k, entonces elimina dicha terna del arbol.
//Si en el arbol c no existe ninguna terna de clave k, no modifica el arbol.
template <typename Clave, typename Dato, typename Tiempo> void borrar (cmt<Clave, Dato, Tiempo>& c, const Clave& k){
	typename cmt<Clave, Dato, Tiempo>::Terna* pAux2 = NULL;				//Puntero auxiliar que guardará el padre de pAux en cada invocación recursiva
	if(borrar2<Clave,Dato,Tiempo>(k,c.raiz,pAux2)){
		c.tamanyo--;
	}
}



	
//Devuelve el nº de ternas del arbol c
template <typename Clave, typename Dato, typename Tiempo> int tamanyo (const cmt<Clave, Dato, Tiempo>& c){
	return c.tamanyo;
}


//Devuelve una cadena que contine la representacion, como cadenas de caracteres,
//de todas las ternas del arbol c en orden por clave de menor a mayor (in-orden).
template <typename Clave, typename Dato, typename Tiempo> string listar (cmt<Clave, Dato, Tiempo>& c){
	iniciarIterador<Clave,Dato,Tiempo>(c);								//Inicio iterador
	string cadena = "";
	Clave k;
	Dato v;
	Tiempo t;		
	bool error;
	while(existeSiguiente<Clave,Dato,Tiempo>(c)){						//Mientras exista siguiente
		siguiente<Clave,Dato,Tiempo>(c,k,v,t,error);
		cadena = cadena + "[" + generaCadena(k) + ":::";
		if(tieneTiempo(c,k)){											//Si tiene un tiempo marcado lo mostramos
			cadena = cadena + generaCadena(t);
		}	
		else{															//Sino mostramos el caracter "-"
			cadena = cadena + "-";	
		}
		cadena = cadena + "\n" + generaCadena(v) + "\n]\n";
	}
	return cadena;
}

//Inicializa el iterador para recorrer las ternas del arbol c in-orden, de forma que la
//siguiente terna a visitar sea la primera (la de menor clave).
template <typename Clave, typename Dato, typename Tiempo> void iniciarIterador (cmt<Clave, Dato, Tiempo>& c){
	c.iterador=c.raiz;
	if(c.iterador!=NULL){
		min<Clave,Dato,Tiempo>(c.iterador);
	}
}

//Devuelve verdad si y sólo si queda alguna terna por visitar con el iterador en el arbol c.
template <typename Clave, typename Dato, typename Tiempo> bool existeSiguiente (const cmt<Clave, Dato, Tiempo>& c){
	return c.iterador!=NULL;
}

//Devuelve la clave, el dato y el tiempo de la siguiente terna de c, ademas del arbol resultante de
//avanzar el cursor del iterador. (error=false)
//Si a el iterador ya ha pasado por todas las ternas del arbol, error=true.
template <typename Clave, typename Dato, typename Tiempo> void siguiente (cmt<Clave, Dato, Tiempo>& c, Clave& k, Dato& v, Tiempo& t, bool& error){
	if (c.iterador==NULL){																
		error = true;
	}
	else{
		error=false;
		k=c.iterador->clave;																//obtenemos datos terna apuntada por el iterador
		v=c.iterador->dato;
		t=c.iterador->tiempo;
		if(c.iterador->dcho!=NULL){															//iterador apuntando a un padre
			typename cmt<Clave, Dato, Tiempo>::Terna* pAux = c.iterador->dcho;				//pasa a apuntar al mínimo de su hijo derecho
			min<Clave,Dato,Tiempo>(pAux);
			c.iterador=pAux;
		}
		else if(c.iterador->padre==NULL){													//caso en el que la raiz del arbol(c) es el ultimo 
			c.iterador = NULL;																//elemento por visitar
		}
		else if(c.iterador==c.iterador->padre->izq){										//iterador apuntando a un hijo izquierdo,
			c.iterador=c.iterador->padre;													//pasa a apuntar a su padre
		}

		else if(c.iterador==c.iterador->padre->dcho){										//iterador apuntando a un hijo derecho
			typename cmt<Clave, Dato, Tiempo>::Terna* pAux = c.iterador->padre;				//pasa a apuntar al padre del primero de sus antecesores
			while(pAux->padre!=NULL && pAux==pAux->padre->dcho){							//que es hijo izquierdo de su padre.
				pAux=pAux->padre;
			}
			c.iterador=pAux->padre;
		}
	}
}


#endif
