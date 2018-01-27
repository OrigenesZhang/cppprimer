#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
int main(){
	string s;
	if(cin>>s){
		for(auto& c:s)
			c='X';
		cout<<s<<endl;
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}