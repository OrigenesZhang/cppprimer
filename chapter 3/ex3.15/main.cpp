#include <iostream>
#include <vector>
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
int main(){
	vector<string> v;
	string cur;
	if(cin>>cur){
		v.push_back(cur);
		while(cin>>cur) v.push_back(cur);
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}