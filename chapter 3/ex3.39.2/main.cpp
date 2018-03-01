#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
int main(){
	size_t max_size=123;
	char s1[max_size], s2[max_size];
	cin>>s1>>s2;
	int res=strcmp(s1, s2);
	if(res>0){
		cout<<"First one is larger.";
	}else if(res<0){
		cout<<"Second one is larger.";
	}else{
		cout<<"They are equal.";
	}
	return 0;
}