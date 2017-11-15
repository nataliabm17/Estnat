#include "cola2.h"


C_cola2::C_cola2(void) : C_base()
{
	ultimo_elemento = NULL;
}

C_cola2::~C_cola2(void)
{
   cout << "Destructor de cola2" << endl;
   while(primer_elemento != NULL)
   	quitar();
}

bool C_cola2::agregar(int mi_dato)
{
	T_celda *paux;
	paux = new T_celda;
	paux->dato=mi_dato;


	if(primer_elemento==NULL){
		primer_elemento=paux;
		paux->proximo=paux;
		paux->anterior=paux;

	}
	else{
		paux->anterior=primer_elemento->anterior;
		primer_elemento->anterior=paux;
		primer_elemento->anterior->proximo=paux;
		paux->proximo=primer_elemento;
	}

	return true;
}

int C_cola2::quitar(void)
{
	int tdato=0;
	T_celda *paux;

	if(primer_elemento!=NULL){
		tdato=primer_elemento->dato;
		paux=primer_elemento;
		primer_elemento=primer_elemento->proximo;
		primer_elemento->anterior=paux->anterior;
		primer_elemento->anterior->proximo=paux->anterior->proximo;
		delete paux;
	}
	return tdato;
}
