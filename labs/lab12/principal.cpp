#include "grafos.h"
int main(void){
/*	C_Grafo miGrafo(6);
	miGrafo.edge(0,1);
	miGrafo.edge(0,2);
	miGrafo.edge(1,3);
	miGrafo.edge(2,1);
	miGrafo.edge(2,3);
	miGrafo.edge(2,4);
	miGrafo.edge(3,5);
	miGrafo.edge(4,3);
	vector< vector<int> > tabla = miGrafo.caminoCorto(2);
std::cout << "distancia" << '\n';
	for(int i=0;i<6;i++){
		std::cout << tabla[i][1] << '\n';
	}
std::cout << "previo" << '\n';
	for(int i=0;i<6;i++){
		std::cout << tabla[i][2] << '\n';
	}*/
	C_Grafo miGrafo2(7);
	miGrafo2.edge(0,2,4);
	miGrafo2.edge(0,3,1);
	miGrafo2.edge(1,0,2);
	miGrafo2.edge(1,4,5);
	miGrafo2.edge(1,6,2);
	miGrafo2.edge(2,1,1);
	miGrafo2.edge(2,3,3);
	miGrafo2.edge(2,5,2);
	miGrafo2.edge(3,5,2);
	miGrafo2.edge(5,4,2);
vector< vector<int> > tabla2 = miGrafo2.caminoCortoPeso(0);

std::cout << "distancia" << '\n';
	for(int i=0;i<7;i++){
		std::cout << tabla2[i][1] << '\n';
	}
std::cout << "previo" << '\n';
	for(int i=0;i<7;i++){
		std::cout << tabla2[i][2] << '\n';
	}
}
