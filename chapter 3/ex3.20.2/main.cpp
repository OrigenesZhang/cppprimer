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
			if(v.size()%2==1){
				cerr<<"The number of elements is odd."<<endl;
				return -1;
			}
			for(decltype(v.size()) i=0, j=v.size()-1; i<j; i++, j--){
				cout<<v[i]+v[j]<<endl;
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