#include <iostream>
int main(){
	int ia[3][4]={
			{0, 1, 2, 3},
			{4, 5, 6, 7},
			{8, 9, 10, 11}
	};
	for(size_t row=0; row<3; row++)
		for(size_t col=0; col<4; col++)
			std::cout<<ia[row][col]<<std::endl;
	return 0;
}