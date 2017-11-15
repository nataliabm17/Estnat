#include "matriz1.h"
#include <iostream>
/*************************************************************/
void desplegar_matriz(int ,int ,const C_matriz &);
void llenar_matriz(int x,int y,C_matriz &);
/*************************************************************/
using namespace std;
/*************************************************************/
int main(void)
{
const int n=2;
const int m=3;
cout<<"Probando el constructor y el método get():"<<endl;
C_matriz A(n,m);
desplegar_matriz(n,m,A);
//use get() member function
cout<<"Probando el método set():"<<endl;
llenar_matriz(n,m,A);
//use set() member function
desplegar_matriz(n,m,A);
cout<<"Probando el constructor con parámetros por defecto:"<<endl;
C_matriz B;
desplegar_matriz(1,1,B);
cout<<"Probando el constructor de copia:"<<endl;
C_matriz C(A);
desplegar_matriz(n,m,C);
return 0;
}
/*************************************************************/
void desplegar_matriz(int x,int y,const C_matriz &Matriz)
{
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cout<<Matriz.get(i,j)<<"\t";

		}
			cout<<endl;
	}
 //próxima fila
};
/*************************************************************/
void llenar_matriz(int x,int y,C_matriz &Matriz)
{
	float elemento=0;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			Matriz.set(i,j,elemento);
			elemento++;
		}
	}
};
/*************************************************************/
