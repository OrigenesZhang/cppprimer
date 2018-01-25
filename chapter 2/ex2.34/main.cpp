#include <iostream>
int main(){
	int i=0, &r=i;
	auto a=r;
	const int ci=i, &cr=ci;
	auto b=ci;
	auto c=cr;
	auto d=&i;
	auto e=&ci;
	const auto f=ci;
	auto &g=ci;
	//auto &h=42;
	const auto &j=42;
	auto k=ci, &l=i;
	auto &m=ci, *p=&ci;
	//auto &n=i, *p2=&ci;
	std::cout<<a<<std::endl;
	a=42;
	std::cout<<a<<std::endl;
	std::cout<<b<<std::endl;
	b=42;
	std::cout<<b<<std::endl;
	std::cout<<c<<std::endl;
	c=42;
	std::cout<<c<<std::endl;
	//taking pointer from integer without a cast
	/*std::cout<<d<<std::endl;
	d=42;
	std::cout<<d<<std::endl;*/
	//taking pointer from integer without a cast
	/*std::cout<<e<<std::endl;
	e=42;
	std::cout<<e<<std::endl;*/
	//Variable is declared constant and is not assignable
	/*std::cout<<f<<std::endl;
	f=42;
	std::cout<<f<<std::endl;*/
	return 0;
}