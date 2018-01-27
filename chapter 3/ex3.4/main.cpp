#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
int main(){
	string s1, s2;
	if(cin>>s1>>s2){
		if(s1==s2) cout<<"Two strings are equal."<<endl;
		else cout<<"Two strings are not equal."<<endl;
		if(s1.size()==s2.size()) cout<<"Two strings have the same length."<<endl;
		else if(s1.size()<s2.size()) cout<<"The second string is longer."<<endl;
		else cout<<"The first string is longer."<<endl;
	}else{
		cerr<<"No input?!"<<endl;
		return -1;
	}
	return 0;
}