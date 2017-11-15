#include<string>
#include<iostream>
#include"Bintree.h"

int main(void){
	C_BinTree tree;
	tree.insertBST(8);
	tree.insertBST(9);
	tree.insertBST(10);
	tree.insertBST(1);
	tree.insertBST(11);
	tree.insertBST(3);
	std::cout << "postorder" << '\n';
	tree.postorder();
	std::cout << "preorder" << '\n';
	tree.preorder();
	std::cout << "inorder" << '\n';
	tree.inorder();
	std::cout << "height: "<< tree.height() << '\n';

	std::cout << "borrar 3" << '\n';
	tree.borrar(3);
	tree.inorder();
	std::cout << "---------------------" << '\n';
	std::cout << "borrar 11" << '\n';
	tree.borrar(11);
	tree.inorder();
	std::cout << "---------------------" << '\n';
	std::cout << "insertcomplete 5" << '\n';
	tree.insertComplete(5);
	tree.inorder();
	std::cout << "imprimir arbol" << '\n';
	tree.preorder();
	std::cout << "**************************" << '\n';
/*
	if(tree.buscarElemento(5)){
		std::cout << "5 si esta" << '\n';
	}
	else{
		std::cout << "5 no esta" << '\n';
	}
	if(tree.buscarElemento(2)){
		std::cout << "2 si esta" << '\n';
	}
	else{
		std::cout << "2 no esta" << '\n';
	}
	//std::cout << "mayor"<< tree.max() << '\n';
	//std::cout << "menor"<< tree.min() << '\n';*/
	tree.printTree();
//	tree.eliminarHoja();
//	tree.preorder();
	tree.borrarRango(4,6);
	tree.preorder();
	tree.~C_BinTree();


}
