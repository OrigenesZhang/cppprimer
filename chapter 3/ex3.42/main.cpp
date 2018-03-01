#include <iostream>
#include <iterator>
#include <vector>
using std::cerr;
using std::cout;
using std::vector;
int main(){
	vector<int> vec={0, 1, 2, 3, 4};
	constexpr size_t arr_size=123;
	if(vec.size()>arr_size){
		cerr<<"The vector is too long.";
		return -1;
	}
	int int_arr[arr_size];
	for(auto i=0; i<vec.size(); i++)
		int_arr[i]=vec[i];
	for(auto i=0; i<vec.size(); i++)
		cout<<int_arr[i]<<' ';
	return 0;
}