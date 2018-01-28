#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main(){
	vector<int> v1;
	cout<<v1.size()<<endl;
	for(auto i:v1) cout<<i<<endl;
	cout<<endl;

	vector<int> v2(10);
	cout<<v2.size()<<endl;
	for(auto i:v2) cout<<i<<endl;
	cout<<endl;

	vector<int> v3(10, 42);
	cout<<v3.size()<<endl;
	for(auto i:v3) cout<<i<<endl;
	cout<<endl;

	vector<int> v4{10};
	cout<<v4.size()<<endl;
	for(auto i:v4) cout<<i<<endl;
	cout<<endl;

	vector<int> v5{10, 42};
	cout<<v5.size()<<endl;
	for(auto i:v5) cout<<i<<endl;
	cout<<endl;

	vector<string> v6{10};
	cout<<v6.size()<<endl;
	for(auto& i:v6) cout<<i<<endl;
	cout<<endl;

	vector<string> v7{10, "hi"};
	cout<<v7.size()<<endl;
	for(auto& i:v7) cout<<i<<endl;
	cout<<endl;

	return 0;
}