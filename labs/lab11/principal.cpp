#include<string>
#include<iostream>
#include <stdlib.h>
#include"grafos.h"

int main(void){
	C_Grafo grafo(6);
	grafo.edge(0,1);
	grafo.edge(1,0);
	grafo.edge(1,2);
	grafo.edge(1,3);
	grafo.edge(2,1);
	grafo.edge(2,4);
	grafo.edge(2,5);
	grafo.edge(3,1);
	grafo.edge(3,4);
	grafo.edge(4,2);
	grafo.edge(4,3);
	grafo.edge(5,2);
	std::cout << "DFS" << '\n';
	grafo.DFS();
	std::cout << "************************" << '\n';
	std::cout << "BFS" << '\n';
	grafo.BFS();
}
