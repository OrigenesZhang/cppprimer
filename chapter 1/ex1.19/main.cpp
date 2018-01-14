#include <iostream>
int main(){
	int l, r;
	std::cin>>l>>r;
	if(l<r){
		for(int i=l; i<=r; i++)
			std::cout<<i<<std::endl;
	}
	return 0;
}