#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main(){
	vector<int> v(10, 5);
	for(auto it=v.begin(); it!=v.end(); ++it)
		(*it)*=2;
	for(auto it:v)
		cout<<it<<' ';
	cout<<endl;
	return 0;
}