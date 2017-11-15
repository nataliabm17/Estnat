#include<iostream>
#include<algorithm>
#include <iomanip>
#include <queue>
#include <sys/ioctl.h>
#include <cstdio>
#include <unistd.h>
#include <math.h>

using namespace std;

struct S_node{
	int data;
	S_node * left;
	S_node * right;
	int height;
};

class AVLTree{
private:
	S_node * root;
	void preOrder(S_node * node);
	void inOrder(S_node * node);
	void posOrder(S_node * node);
	S_node * insertAVL(S_node * node, int data);
	S_node * rotateRight(S_node * node);
	S_node * doubleRotateRight(S_node * node);
	S_node * rotateLeft(S_node * node);
	S_node * doubleRotateLeft(S_node * node);
	int heightNode(S_node * node);
	void deleteTree(S_node * node);
	void printTree(S_node* node, int indent);

public:
	AVLTree();
	~AVLTree();
	void preOrder(void);
	void inOrder(void);
	void posOrder(void);
	void insertAVL(int data);
	void printTree(void);
	int buscar(int);
	int buscar(int, S_node*, int, int);

};

AVLTree::AVLTree(){
	this->root=NULL;
}
AVLTree::~AVLTree(){
	cout<<"Destructor"<<endl;
}

void AVLTree::deleteTree(S_node * node){
	if(root){
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

S_node * AVLTree::insertAVL(S_node * node, int data){
	if(!node){
		node= new S_node;
		if(!node){
			cout<<"Memoria no asignada, se la comieron los gatitos" << endl;
			return NULL;
		}
		else{
			node->data=data;
			node-> height = 0;
			node->left = node->right = NULL;
		}
	}
	else if(data < node->data){
		node->left=insertAVL(node->left, data);
		if((heightNode(node->left)-heightNode(node->right))>1){
			cout<<"left se cumple para: "<<node->data<<endl;
			if(data<node->left->data){
				cout<<"single"<<endl;
				node=rotateLeft(node);
			}
			else{
				cout<<"double"<<endl;
				node=doubleRotateLeft(node);
			}
		}
	}
	else if(data > node->data){
		node->right=insertAVL(node->right, data);
		if((heightNode(node->right)-heightNode(node->left))>1){
			cout<<"right se cumple para: "<<node->data<<endl;
			if(data>node->right->data){
				cout<<"single"<<endl;
				node=rotateRight(node);
			}
			else{
				cout<<"double"<<endl;
				node=doubleRotateRight(node);
			}
		}
	}
	node->height=max(heightNode(node->left),heightNode(node->right))+1;
	return node;
}

	void AVLTree::preOrder(S_node * node){
		if(node){
			cout<<node->data<<endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void AVLTree::inOrder(S_node * node){
		if(node){
			inOrder(node->left);
			cout<<node->data<<endl;
			inOrder(node->right);
		}
	}
	void AVLTree::posOrder(S_node * node){
		if(node){
			posOrder(node->left);
			posOrder(node->right);
			cout<<node->data<<endl;
		}
	}
	S_node * AVLTree::rotateRight(S_node * node){
		S_node * paux = node->right;
		node->right=paux->left;
		paux->left=node;
		node->height=max(heightNode(node->left),heightNode(node->right))+1;
		paux->height=max(heightNode(paux->left),heightNode(paux->right))+1;
		return paux;
	}
	S_node * AVLTree::doubleRotateRight(S_node * node){
		node->right=rotateLeft(node->right);
		return rotateRight(node);

	}
	S_node * AVLTree::rotateLeft(S_node * node){
		S_node * paux = node->left;
		node->left=paux->right;
		paux->right=node;
		node->height=max(heightNode(node->left),heightNode(node->right))+1;
		paux->height=max(heightNode(paux->left),heightNode(paux->right))+1;
		return paux;
	}
	S_node * AVLTree::doubleRotateLeft(S_node * node){
		node->left=rotateRight(node->left);
		return rotateLeft(node);
	}
	int AVLTree::heightNode(S_node * node){
		if(node){
			return node->height;
		}
		else{
			return -1;
		}
	}
	void AVLTree::preOrder(void){
		preOrder(this->root);
	}
	void AVLTree::inOrder(void){
		inOrder(this->root);
	}
	void AVLTree::posOrder(void){
		posOrder(this->root);
	}
	void AVLTree::insertAVL(int data){
		this->root=insertAVL(this->root, data);
	}


void AVLTree::printTree(S_node* node, int indent){
    if(node != NULL) {
        if(node->right) {
            printTree(node->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< node->data<< " "<<node->height << "\n ";
        if(node->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            printTree(node->left, indent+4);
        }
    }
}

void AVLTree::printTree(void){
	printTree(this->root, 0);
}

int AVLTree::buscar(int numero, S_node* node, int dif2, int num){
	int dif;
	if(node){
	  int dif = abs(node->data-numero);
		if(dif<dif2){
			dif2=dif;
			num=node->data;
		}
		else if(dif==dif2){
			if(node->data<num){
				num=node->data;
			}
		}
			buscar(numero,node->right,dif2,num);
			buscar(numero,node->left,dif2,num);
	}
	return num;
}

int AVLTree::buscar(int numero){

	int i = buscar(numero, this->root,10000,0);
	return i;
}
