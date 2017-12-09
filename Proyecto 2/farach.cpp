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
	else{
		for(int i=0;i<a.size();i++){
			numeric[i]=(int)a[i]-48;
		}
	}
	numeric.push_back(-1);
	return numeric;
}

void C_Farach::createOddTree(string s){
	vector<int> numeric=numericAlphabet(s,s.length());
	vector< pair<int,int> > pairs;
	for(int i=0;i<numeric.size();i=i+2){
		pair<int,int> pair;
		if(numeric[i+1]){
			pair = make_pair(numeric[i],numeric[i+1]);
		}
		else{
			pair = make_pair(numeric[i],-2);
		}
		pairs.push_back(pair);
	}
	int c = 0;
	bucketSort(pairs);
	for(int i=0;i<pairs.size();i++){
		for(int j=c;j<pairs.size();j++){
			if((pairs[i].first==pairs[j].first)&&(pairs[i].second==pairs[j].second)){
				pairs.erase (pairs.begin()+j);
			}
		}
		c++;
	}
}

vector< pair<int,int> > C_Farach::bucketSort(vector<	pair<int,int> > pairs){
	vector< pair<int,int> > vect;
	for(int i=0;i<pairs.size();i++){
		vect.push_back(pairs[i]);
	}
	sort(vect.begin(), vect.end());

	for(int i=0;i<pairs.size();i++){
		std::cout << "pairs"<< vect[i].first<<"  "<<vect[i].second << '\n';
	}
/*	vector< vector< pair<int,int> > > aux(12,NULL);
	vector< vector< pair<int,int> > > aux2(11,NULL);
	for(int i=0;i<pairs.size();i++){
		aux[pairs[i].second+2].push_back(pairs[i]);
	}
	for(int i=0;i<12;i++){
		if(aux[i]){
			for(int j=0;j<aux[i].size();j++){
				aux2[aux[i].first+1].push_back(aux[i][j]);
			}
		}

		aux[pairs[i].first].push_back(pairs[i]);
	}
	for(int i=0;i<aux.size();i++){
		if(aux[i]!=-2){
			aux2[aux[i].first]
		}
	}*/
}


int main(void){
	string s = ("12889");
	C_Farach f;
	vector<int> a;

/*	a=f.numericAlphabet(s,s.length());
	for(int i =0;i<s.length()+1;i++){
		std::cout << a[i] << '\n';
	}*/
	f.createOddTree(s);
}
