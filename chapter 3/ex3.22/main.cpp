#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
int main(){
	string text;
	if(getline(cin, text)){
		for(auto it=text.begin(); it!=text.end(); ++it)
			*it=toupper(*it);
		cout<<text<<endl;
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}