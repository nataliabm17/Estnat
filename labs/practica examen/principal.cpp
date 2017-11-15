#include "practica.h"
int main(void){
	C_cola2<int> cola;
	for(int i = 0;i<5;i++){
		cola.agregar(i);
	}

	for(int i = 0;i<5;i++){
		std::cout << cola.quitar() << '\n';
	}
}
