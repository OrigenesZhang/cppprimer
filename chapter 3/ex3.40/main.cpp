#include <cstring>
#include <iostream>
using std::cout;
using std::cerr;
int main(){
	constexpr size_t max_size=123;
	const char s1[]="Hello";
	const char s2[]=" World";
	if(strlen(s1)+strlen(s2)>=max_size){
		cerr<<"Strings are too long.";
		return -1;
	}
	char res[max_size];
	strcpy(res, s1);
	strcat(res, s2);
	cout<<res;
	return 0;
}