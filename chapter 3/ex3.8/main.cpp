#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
int main(){
	string s;
	if(cin>>s){
		decltype(s.size()) idx=0;
		while(idx<s.size())
			s[idx++]='X';
		cout<<s<<endl;
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	if(cin>>s){
		for(decltype(s.size()) index=0; index!=s.size(); ++index)
			s[index]='X';
		cout<<s<<endl;
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}