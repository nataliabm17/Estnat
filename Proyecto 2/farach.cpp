#include "farach.h"

vector<int> C_Farach::numericAlphabet(string s, int size){
//	char a[] = s;
//  char* a = s.c_str();
//	strcpy(a, s.c_str());
	vector<int>	numeric(size,0);
	vector<char> a(s.begin(),s.end());
	if(!isdigit(a[0])){
		vector<char> list;

		int c = 1;
		bool found = false;

		for(int i=0;i<size;i++){
			for(int j=0;j<list.size();j++){
				if(list[j]==a[i]){
					numeric[i]=j+1;
					found=true;
				}
			}
			if(found==false){
				list.push_back(a[i]);
				numeric[i]=c;
				c++;
			}
			found = false;
		}
	}
	return numeric;
}

void C_Farach::createOddTree(string s){

	pair<int,int> pair;
	pair= make_pair(1,2);
}


int main(void){
	string s = ("hjkhloo");
	C_Farach f;
	vector<int> a;
	a=f.numericAlphabet(s,s.length());
	for(int i =0;i<s.length();i++){
		std::cout <<"i"<< a[i] << '\n';
	}
}
