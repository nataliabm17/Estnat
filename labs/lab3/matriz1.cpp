#include "matriz1.h"

C_matriz::C_matriz(int filas, int columnas)
{
	this->filas = filas;
	this->columnas =  columnas;
	this->ptr_data = new float[filas*columnas];
}

C_matriz::~C_matriz(){
	delete [] ptr_data;
}
C_matriz::C_matriz(const C_matriz & matriz)
{
	this->filas = matriz.filas;
	this->columnas =  matriz.columnas;
	this->ptr_data = new float[matriz.filas*matriz.columnas];

	int n = (this->columnas -1)+(this->filas-1)*columnas;
	for(int i=1;i<=this->filas;i++)
		{
			for(int j=1;j<=this->columnas;j++)
			{
				this->ptr_data[n] = matriz.ptr_data[n];
			}
		}
	}

float C_matriz::get(int fila, int columna)const{

	int n = (columna-1)+(fila-1)*this->columnas;
	return ptr_data[n];
}

void C_matriz::set(int fila, int columna ,float dato){
	int n = (columna-1)+(fila-1)*this->columnas;
	ptr_data[n] = dato;
}
