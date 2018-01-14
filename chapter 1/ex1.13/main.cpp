#include <iostream>
int main(){
	//rewrite ex 1.9
	int sum=0;
	for(int i=50; i<=100; i++)
		sum+=i;
	std::cout<<sum<<std::endl;
	//rewrite ex 1.10
	for(int i=10; i>=0; i--)
		std::cout<<i<<std::endl;
	//rewrite ex 1.11
	int l, r;
	std::cin>>l>>r;
	for(int i=l; i<=r; i++)
		std::cout<<i<<std::endl;
	return 0;
}