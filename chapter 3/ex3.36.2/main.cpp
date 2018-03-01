#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
int main(){
	unsigned sz1, sz2;
	cin>>sz1>>sz2;
	if(sz1!=sz2){
		cout<<"Two arrays are not equal.";
		return 0;
	}
	vector<int> vec1(sz1), vec2(sz2);
	for(auto& it:vec1)
		cin>>it;
	for(auto& it:vec2)
		cin>>it;
	for(auto i=0; i<vec1.size(); i++){ c
		if(vec1[i]!=vec2[i]){
			cout<<"Two arrays are not equal.";
			return 0;
		}
	}
	cout<<"Two arrays are equal.";
	return 0;
}