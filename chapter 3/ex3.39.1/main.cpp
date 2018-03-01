#include <iostream>
using std::cin;
using std::cout;
using std::string;
int main(){
	string s1, s2;
	cin>>s1>>s2;
	if(s1>s2){
		cout<<"First one is larger.";
	}else if(s1<s2){
		cout<<"Second one is larger.";
	}else{
		cout<<"They are equal.";
	}
	return 0;
}