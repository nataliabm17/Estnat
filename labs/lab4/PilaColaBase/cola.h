/*********************************************************************
*
C_cola.h
*********************************************************************
*/

#include "base.h"

#ifndef CLASEcola
#define CLASEcola

template <typename T>
class C_cola : public C_base<T>{
	public:
		C_cola(void);
		~C_cola(void);
		bool agregar(T);
		T quitar(void);
		bool agregar(T,int);
		T quitar(int);

};

template <typename T>
C_cola<T>::C_cola(void) : C_base<T>()
{
//	primer_elemento = NULL;
}

template <typename T>
C_cola<T>::~C_cola(void)
{
   cout << "Destructor de cola" << endl;
   while(this->primer_elemento != NULL)
    quitar();
}

template <typename T>
bool C_cola<T>::agregar(T mi_dato, int posicion)
{

	if(this->count()<posicion){

	}

	else{
		S_celda<T> *paux;
		S_celda<T> *paux2;
		S_celda<T> *paux3;
		paux2=this->primer_elemento;
		paux = new S_celda<T>;
		paux->dato = mi_dato;

		for(int i= 0;i<posicion-1;i++){
			paux2 = paux2->proximo;
		}
		paux3=paux2->proximo;
		paux2->proximo=paux;
		paux->proximo = paux3;
	}
	return true;
}

template <typename T>
T C_cola<T>::quitar(int posicion)
{
	if(this->count()<posicion){
	}
	else{
		S_celda<T> *paux;
		S_celda<T> *paux2;
		paux = this->primer_elemento;
		for(int i=0; i<posicion-1;i++){
			paux = paux->proximo;
		}

		paux2 = paux->proximo;
		T dato = paux2->dato;
		paux->proximo=paux2->proximo;
		return dato;
	}

}

template <typename T>
bool C_cola<T>::agregar(T mi_dato)
{
	S_celda<T> *paux;
	paux = new S_celda<T>;

	paux->dato=mi_dato;
	paux->proximo=NULL;

	if(this->primer_elemento==NULL){
		this->primer_elemento=paux;
	}

	else{
		S_celda<T> *pTemp1, *pTemp2;
		pTemp1=pTemp2=this->primer_elemento;
		while(pTemp2!=NULL)
		{
			pTemp1=pTemp2;
			pTemp2=pTemp1->proximo;
		}
		pTemp1->proximo=paux;
	}

	return true;
}

template <typename T>
T C_cola<T>::quitar(void)
{
	int tdato=0;
	S_celda<T> *paux;

	if(this->primer_elemento!=NULL){
		paux=this->primer_elemento;

		tdato=this->primer_elemento->dato;
		this->primer_elemento=this->primer_elemento->proximo;
		delete paux;
	}
	return tdato;
}

#endif
