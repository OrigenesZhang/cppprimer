#include <iostream>
using std::cout;
int main(){
	constexpr size_t array_size=10;
	int arr[array_size]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(auto i:arr)
		cout<<i<<' ';
	return 0;
}