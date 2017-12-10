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
	S_node *parent;
	S_node *children[28];
	int childrenCount;
	vector<int> suffix;
};

class C_Farach{
private:
	S_node* root = new S_node;
	vector<int> numericAlphabet(string ,int);
	vector< pair<int,int> > pairSort(vector<	pair<int,int> >);
	void createTree(vector<int> );
	pair<S_node*,pair<int,int> > placeInTree(vector<int>, S_node*, int);
public:
	void createOddTree(string);
};
