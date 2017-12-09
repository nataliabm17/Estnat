#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

struct S_node{
	int index;
	S_node *father;
	int children;
	int suffix;
};

class C_Farach{
private:
	S_node *root;
	vector<int> numericAlphabet(string ,int);
	vector< pair<int,int> > pairSort(vector<	pair<int,int> >);
	void createTree(vector<int> );
public:
	void createOddTree(string);
};
