#include <ctime>
#include "pila.h"
#include "cola.h"
#include "cola2.h"

#define ITE 100000


int main (void)
{
	time_t start, end;
	double diff;

	C_cola vcola;
	C_cola2 vcola2;
	C_base *pBase;

	pBase=&vcola;

	cout << "\nLlenando cola 1..."<<endl;

	time(&start); //useful call
	for (int i=0; i<ITE; ++i)
	{
	//vpila.push(i);
		pBase->agregar(i);
	}
  	time(&end);//useful call
  	diff = difftime(end,start);//this will give you time spent between those two calls.
 	cout<<"Duración de llenado de cola 1: "<<diff<<" segundos\n"<<endl;

	pBase=&vcola2;

	cout << "Llenando cola 2..."<<endl;

	time(&start); //useful call
	for (int i=0; i<ITE; ++i)
	{
	//vpila.push(i);
		pBase->agregar(i);
	}
  	time(&end);//useful call
  	diff = difftime(end,start);//this will give you time spent between those two calls.
 	cout<<"Duración de llenado de cola 2: "<<diff<<" segundos\n"<<endl;
}

