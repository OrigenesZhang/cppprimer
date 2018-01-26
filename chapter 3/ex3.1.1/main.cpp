//Rewriting exercise 1.11 with 'using' declarations
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
	int l, r, cur;
	cin>>l>>r;
	cur=l;
	while(cur<=r){
		cout<<cur<<endl;
		cur++;
	}
	return 0;
}