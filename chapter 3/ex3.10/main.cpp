#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ispunct;
int main(){
	string s, res;
	bool flag=false;
	if(cin>>s){
		for(auto c:s){
			if(ispunct(c)) flag=true;
			else res+=c;
		}
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	if(!flag){
		cerr<<"No punctuation."<<endl;
		return -1;
	}
	cout<<res<<endl;
	return 0;
}