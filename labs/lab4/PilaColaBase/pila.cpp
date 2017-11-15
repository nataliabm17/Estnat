#include "pila.h"

template <typename T>
C_pila<T>::C_pila(void) : C_base<T>()
{
	//primer_elemento = NULL;
}

template <typename T>
C_pila<T>::~C_pila(void)
{
   cout << "Destructor de pila" << endl;
   while(primer_elemento != NULL)
    pull();
}

template <typename T>
bool C_pila<T>::push(T mi_dato)
{
	S_celda<T> *paux;
	paux = new S_celda<T>;
	paux->dato=mi_dato;
	paux->proximo=primer_elemento;
	primer_elemento=paux;
	return true;
}

template <typename T>
T C_pila<T>::pull(void)
{
	if(primer_elemento != NULL)
	{
		S_celda<T> *paux;
		T temp;
		paux=primer_elemento;
		primer_elemento=paux->proximo;
		temp=paux->dato;
		delete paux;
		return temp;
	}
	else
		return 0;
}

template <typename T>
bool C_pila<T>::agregar(T mi_dato)
{
	return this->push(mi_dato);
}

template <typename T>
T C_pila<T>::quitar(void)
{
	return pull();
}
