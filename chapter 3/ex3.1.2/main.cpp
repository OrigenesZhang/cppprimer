//Rewrite exercise 2.42 (the first part) with 'using' declarations
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
struct Sales_data{
	string bookNo;
	unsigned units_sold=0;
	double revenue=0;
};
int main(){
	Sales_data data1, data2;
	double price=0;
	cin>>data1.bookNo>>data1.units_sold>>price;
	data1.revenue=data1.units_sold*price;
	cin>>data2.bookNo>>data2.units_sold>>price;
	data2.revenue=data2.units_sold*price;
	if(data1.bookNo==data2.bookNo){
		unsigned totCnt=data1.units_sold+data2.units_sold;
		double totRevenue=data1.revenue+data2.revenue;
		cout<<data1.bookNo<<' '<<totCnt<<' '<<totRevenue<<' ';
		if(totCnt!=0) cout<<totRevenue/totCnt<<endl;
		else cout<<"(no sales)"<<endl;
		return 0;
	}else{
		cerr<<"Different ISBN"<<endl;
		return -1;
	}
}