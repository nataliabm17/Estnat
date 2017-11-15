#include<string>
#include<iostream>
#include"Bintree.h"

int main(void){
	C_BinTree tree;
	tree.insertAVL(8);
	tree.insertAVL(9);
	tree.insertAVL(10);
	tree.insertAVL(1);
	tree.insertAVL(11);
	tree.insertAVL(5);
	tree.insertAVL(4);
	tree.insertAVL(1);
	tree.insertAVL(10);
	tree.insertAVL(3);
	tree.insertAVL(2);
	tree.printTree();
	std::cout << "Borrar 9" << '\n';
	tree.borrar(9);
	tree.printTree();
}
