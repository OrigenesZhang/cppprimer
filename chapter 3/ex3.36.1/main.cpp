#include <iostream>
#include <iterator>
using std::cin;
using std::cout;
using std::cerr;
using std::begin;
using std::end;
int main(){
	constexpr size_t max_size=123;
	int arr1[max_size], arr2[max_size];
	size_t sz1, sz2;
	cin>>sz1>>sz2;
	if(sz1!=sz2){
		cout<<"Two arrays are not equal.";
		return 0;
	}
	if(sz1>max_size||sz2>max_size){
		cerr<<"The array sizes are too large.";
		return -1;
	}
	for(auto i=0; i<sz1; i++)
		cin>>arr1[i];
	for(auto i=0; i<sz2; i++)
		cin>>arr2[i];
	int *p1begin=begin(arr1), *p1end=p1begin+sz1;
	int *p2begin=begin(arr2), *p2end=p2begin+sz2;
	for(auto p1=p1begin, p2=p2begin; p1!=p1end&&p2!=p2end; ++p1, ++p2){
		if(*p1!=*p2){
			cout<<"Two arrays are not equal.";
			return 0;
		}
	}
	cout<<"Two arrays are equal.";
	return 0;
}