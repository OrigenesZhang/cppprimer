#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
int main(){
	vector<int> v;
	int cur;
	if(cin>>cur){
		v.push_back(cur);
		if(cin>>cur){
			v.push_back(cur);
			while(cin>>cur) v.push_back(cur);
			for(decltype(v.size()) ix=1; ix<v.size(); ix++){
				cout<<v[ix-1]+v[ix]<<endl;
			}
		}else{
			cerr<<"Insufficient data..."<<endl;
			return -1;
		}
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}