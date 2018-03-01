#include <iostream>
#include <iterator>
using std::cout;
using std::begin;
using std::end;
int main(){
	constexpr size_t array_size=10;
	unsigned arr[array_size];
	unsigned *pbegin=begin(arr), *pend=end(arr);
	for(unsigned* p=pbegin; p!=pend; ++p)
		*p=0;
	for(auto it:arr)
		cout<<it<<' ';
	return 0;
}