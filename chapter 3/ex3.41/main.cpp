#include <iostream>
#include <iterator>
#include <vector>
using std::cout;
using std::begin;
using std::end;
using std::vector;
int main(){
	int int_arr[]={0, 1, 2, 3, 4};
	vector<int> vec(begin(int_arr), end(int_arr));
	for(auto it:vec)
		cout<<it<<' ';
	return 0;
}