#include "cola.h"


C_cola::C_cola(void) : C_base()
{
	
}

C_cola::~C_cola(void)
{
   cout << "Destructor de cola" << endl;
   while(primer_elemento != NULL)
    quitar();
}

bool C_cola::agregar(int mi_dato)
{
	T_celda *paux;
	paux = new T_celda;

	paux->dato=mi_dato;
	paux->proximo=NULL;

	if(primer_elemento==NULL){
		primer_elemento=paux;
	}

	else{
		T_celda *pTemp1, *pTemp2;
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

int C_cola::quitar(void)
{
	int tdato=0;
	T_celda *paux;

	if(primer_elemento!=NULL){
		paux=primer_elemento;

		tdato=primer_elemento->dato;
		primer_elemento=primer_elemento->proximo;
		delete paux;
	}
	return tdato;
}
