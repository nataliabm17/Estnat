#include<string>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct S_node{
	int dato;
	S_node *next;
};

class C_HashTable{
protected:
	vector< S_node* > table;

public:
	C_HashTable(){
		this->table.resize(100,NULL);
	}
	~C_HashTable(){
		deleteHashTable();
	}
	bool hashSearch(int dato){
		bool flag = false;
		int key = hash(dato);
		S_node* node;
		node = table[key];
		while(node!=NULL){
			if(node->dato=dato){
				flag=true;
			}
			node=node->next;
		}
		return flag;
	}

	void hashInsert(int dato){
		S_node* node = new S_node();
		int key=hash(dato);
		std::cout << "key"<<key << '\n';
		if(table[key]==NULL){
			node->dato=dato;
			node->next=NULL;
			table[key]=node;
		}
		else{
			S_node* node2 = new S_node();
			node=table[key];
			while(node->next!=NULL){
				node=node->next;
			}
			node->next=node2;
			node2->dato=dato;
			node2->next=NULL;
		}
	}

	int hash(int dato){
		vector<int> array(9);
		int key=0;
		for(int i=1;i<=100000000;i*=10){
			key += (dato/i)%10;
		}
		return key;
	}

	int hashDelete(int dato){
		int key = hash(dato);
		S_node* node;
		S_node* paux=NULL;
		for(int i=0;i<table.size();i++){
			if(table[i]!=NULL){
				node = table[i];
				paux=table[i];
				if(node->dato==dato){
					if(node->next==NULL){
						delete node;
						node = NULL;
					}
					else{
						table[i]=node->next;
						delete node;
					}
				}
				else{
					paux=table[i];
					while(node!=NULL){
						if(node->next!=NULL&&node->dato==dato&&node!=table[i]){
							paux->next=node->next;
							delete node;
							node=NULL;
						}
						else if(node->next==NULL&&node->dato==dato&&node!=table[i]){
							paux->next==NULL;
							delete node->next;
							node=NULL;
						}
						paux=node;
						if(node!=NULL){
							node = node->next;
						}
					}
				}
			}
		}
	}

	void deleteHashTable(void){
		S_node* nodo;
		for(int i=0;i<table.size();i++){
			nodo=table[i];
				while(nodo){
					if(nodo->next){
					nodo=nodo->next;
					}
					else{
						delete nodo;
						nodo=NULL;
					}
				}
			delete nodo;
			nodo = NULL;
		}
	}

};
