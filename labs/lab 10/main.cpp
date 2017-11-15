#include<string>
#include<iostream>
#include <stdlib.h>
#include"heap.h"

int main(void){
	C_Heap tree(10,1);
	for(int i=0;i<5;i++){
		int num = rand() % 10 + 1;
		tree.insert(num);
	}
	tree.imprimir();
}
