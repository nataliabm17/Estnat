#include"AVLTree.h"
#include<cstdio>
#include<ctime>

int main(void){
	AVLTree myTree;
	int data;
	srand(time(NULL));
	for (int i=0; i<10; i++){
		data=rand()%10;
		cout<<"num"<<data<<endl;
		myTree.insertAVL(data);
	}
	cout<<"\nFinal Tree"<<endl;
//	myTree.printTree();
int numero =myTree.buscar(6);
	std::cout << numero<< '\n';
	return 0;
}
