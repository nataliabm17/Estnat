//principal3.cpp
//-----------------------------------------------------------------------------------------------------------------------/
#include "matriz.h"
#include <iostream>
/*************************************************************/
void llenar_matriz(int x,int y,C_matriz &);
/*************************************************************/

/*************************************************************/
int main(void)
{
	const int n=2;
	const int m=3;
	cout<<" Probando los operadores sobrecargados =, + and *:"<<endl;
	cout<<"A:"<<endl;
	C_matriz A(n,m);
	llenar_matriz(n,m,A);
//	cout<<A<<endl;;
	A.desplegar();
	cout<<"B:"<<endl;
	C_matriz B(A);
	//cout<<A<<endl;;
	B=3*A;
//	cout<<B<<endl;;
	B.desplegar();
	cout<<"C:"<<endl;
	C_matriz C=B-A;
	//cout<<C<<endl;
	C.desplegar();
	return 0;
}
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
