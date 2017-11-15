#include "pila.h"
#include "cola.h"

int main (void)
{

  C_cola<int> vcola;
  C_base<int> *pCola;
  C_pila<int> vpila;
  C_base<int> *pBase;

  pBase = &vpila;
  pCola = &vcola;

  for (int i=100; i<110; ++i)
  {
    pCola->agregar(i);
  	pBase->agregar(i);
  }
  pBase->invert();

  cout <<"\n Resultado para la pila"<<endl;
  for (int i=0; i<10; ++i)
  {
     cout << i <<"-) " << pBase->quitar() << endl;
  }

  pCola->agregar(1,3);
  pCola->quitar(2);

  cout <<"\n Resultado para la cola"<<endl;
  for (int i=0; i<10; ++i)
  {
     cout << i <<"-) " << pCola->quitar() << endl;
  }



}
