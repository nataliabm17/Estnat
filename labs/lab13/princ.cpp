#include "lab111.h"
int main(void){
	C_HashTable tabla;
	tabla.hashInsert(117300279);
	tabla.hashInsert(171300279);
	tabla.hashInsert(711300279);
	tabla.hashInsert(123001414);
	tabla.hashInsert(258963147);
	tabla.hashInsert(566387021);
	tabla.hashInsert(789562155);
	tabla.hashDelete(171300279);
std::cout << "search " << tabla.hashSearch(117300279)<< '\n';
std::cout << "search " << tabla.hashSearch(117305479)<< '\n';
std::cout << "destructor" << '\n';
tabla.deleteHashTable();
}
