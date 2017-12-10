#include "matriz3.h"
#include<iostream>
using namespace std;

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

void C_matriz::desplegar(void)
{
	for(int i=1;i<=this->filas;i++)
	{
		for(int j=1;j<=this->columnas;j++)
		{
			cout<<this->get(i,j)<<"\t";

		}
			cout<<endl;
	}
 //próxima fila
 }

 C_matriz &C_matriz::operator=(const C_matriz & matriz){
	 	 if(this->filas==matriz.filas&&this->columnas==matriz.columnas){
				 for(int i=1;i<=this->filas;i++){
						 for(int j=1;j<=this->columnas;j++){
							 this->ptr_data[j-1+columnas*(i-1)] = matriz.ptr_data[j-1+columnas*(i-1)];
						 }
			    }
				return *this;
		 }

			else{
				delete[] ptr_data;
				ptr_data = new float[matriz.filas*matriz.columnas];
				for(int i=1;i<=this->filas;i++){
						for(int j=1;j<=this->columnas;j++){
							this->ptr_data[j-1+columnas*(i-1)] = matriz.ptr_data[j-1+columnas*(i-1)];
						}
					}
				return *this;
			}
 } //Operador de asignación

 float C_matriz::operator()(int fila, int columna)const{
	 return get(fila, columna);
 }

 C_matriz C_matriz::operator+(const C_matriz & matriz){

	 if(this->filas==matriz.filas&&this->columnas==matriz.columnas){
	 	C_matriz suma(this->filas,this->columnas);
		for(int i=0;i<this->filas*this->columnas;i++){
				suma.ptr_data[i]=this->ptr_data[i]+matriz.ptr_data[i];
			}

			return suma;
 	}
}

	C_matriz C_matriz::operator-(const C_matriz &matriz){

		if(this->filas==matriz.filas&&this->columnas==matriz.columnas){
		 C_matriz resta(this->filas,this->columnas);
		 for(int i=0;i<this->filas*this->columnas;i++){
				 resta.ptr_data[i]=this->ptr_data[i]-matriz.ptr_data[i];
			 }

			 return resta;
	 }

 }
 //suma dos matrices
// C_matriz C_matriz::operator*(const float & numero)
C_matriz operator*(const C_matriz & matriz,const float & numero){
	 C_matriz multiplicada(matriz.filas,matriz.columnas);
	 for(int i=0;i<matriz.filas*matriz.columnas;i++ ){

		 multiplicada.ptr_data[i]=numero*matriz.ptr_data[i];
	 }

	 return multiplicada;

 }

C_matriz operator*(const float & numero,const C_matriz & matriz){

	C_matriz multiplicada(matriz.filas,matriz.columnas);
	for(int i=0;i<matriz.filas*matriz.columnas;i++ ){

		multiplicada.ptr_data[i]=numero*matriz.ptr_data[i];
	}

	return multiplicada;

}

ostream & operator<<(ostream & Output,const C_matriz &Matriz)
{
for(int i=1;i<=Matriz.filas;i++)
{
for(int j=1;j<=Matriz.columnas;j++)
{
Output<<Matriz(i,j)<<"\t"; //Output puede ser algo como cout
}
cout<<endl;
}
return Output;
};