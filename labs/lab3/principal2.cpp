#include "matriz2.h"
#include <iostream>
/*************************************************************/
void llenar_matriz(int x,int y,C_matriz &);
/*************************************************************/
using namespace std;
/*************************************************************/
int main(void)
{
	const int n=2;
	const int m=3;
	cout<<"Probando los operadores sobrecargados =, + and *:"<<endl;
	cout<<"A:"<<endl;
	C_matriz A(n,m);
	llenar_matriz(n,m,A);
	A.desplegar();
	cout<<"B:"<<endl;
	C_matriz B(A);
	B=A*2;
	B.desplegar();
	cout<<"C:"<<endl;
	C_matriz C=A+B;
	C.desplegar();
	cout<<C(1,1)<<"\n"<<C(2,2)<< endl;
	return 0;
}
/*************************************************************/
void llenar_matriz(int x,int y,C_matriz &Matriz)
{
	float element=0;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			Matriz.set(i,j,element);
			element++;
		}
	}
};
/*************************************************************/
