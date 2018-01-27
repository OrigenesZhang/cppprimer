#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
int main(){
	string res, s;
	if(cin>>res){
		while(cin>>s) res+=s;
		cout<<res<<endl;
	}else{
		cerr<<"No input?!"<<endl;
		return -1;
	}
	if(cin>>res){
		while(cin>>s) res+=" "+s;
		cout<<res<<endl;
	}else{
		cerr<<"No input?!"<<endl;
		return -1;
	}
	return 0;
}