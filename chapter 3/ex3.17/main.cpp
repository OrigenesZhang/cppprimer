#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
int main(){
	vector<string> v;
	string s;
	if(cin>>s){
		v.push_back(s);
		while(cin>>s) v.push_back(s);
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	int cnt=0;
	for(auto& it:v){
		++cnt;
		cout<<it;
		if(cnt==8){
			cout<<endl;
			cnt=0;
		}else{
			cout<<' ';
		}
	}
	return 0;
}