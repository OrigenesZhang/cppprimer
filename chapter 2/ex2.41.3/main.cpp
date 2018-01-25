#include <iostream>
struct Sales_data{
	std::string bookNo;
	unsigned units_sold=0;
	double revenue=0;
};
int main(){
	Sales_data total;
	double price=0;
	unsigned totCnt=0;
	if(std::cin>>total.bookNo>>total.units_sold>>price){
		total.revenue=price*total.units_sold;
		totCnt=total.units_sold;
		Sales_data trans;
		while(std::cin>>trans.bookNo>>trans.units_sold>>price){
			if(trans.bookNo==total.bookNo){
				total.revenue+=price*trans.units_sold;
				totCnt+=trans.units_sold;
			}else{
				std::cout<<total.bookNo<<' '<<totCnt<<' '<<total.revenue<<' ';
				if(totCnt!=0) std::cout<<total.revenue/totCnt<<std::endl;
				else std::cout<<"(no sales)"<<std::endl;
				total=trans;
				total.revenue=price*total.units_sold;
				totCnt=total.units_sold;
			}
		}
	}else{
		std::cerr<<"No data?!"<<std::endl;
		return -1;
	}
	std::cout<<total.bookNo<<' '<<totCnt<<' '<<total.revenue<<' ';
	if(totCnt!=0) std::cout<<total.revenue/totCnt<<std::endl;
	else std::cout<<"(no sales)"<<std::endl;
	return 0;
}