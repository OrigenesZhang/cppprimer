#include <iostream>
#include "Sales_item.h"
int main(){
	Sales_item item1, item2;
	int num=1;
	if(std::cin>>item1){
		while(std::cin>>item2){
			if(item1.isbn()==item2.isbn()) num++;
			else{
				std::cout<<item1.isbn()<<"-----"<<num<<std::endl;
				item1=item2;
				num=1;
			}
		}
		std::cout<<item1.isbn()<<"-----"<<num<<std::endl;
	}else{
		std::cerr<<"No data?!"<<std::endl;
		return -1;
	}
	return 0;
}