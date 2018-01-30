#include <iostream>
#include <vector>
using std::cin;
using std::endl;
using std::cout;
using std::vector;
int main(){
	vector<unsigned> scores(11, 0);
	unsigned grade;
	auto beg=scores.begin();
	while(cin>>grade){
		if(grade<=100)
			(*(beg+grade/10))++;
	}
	for(auto people:scores)
		cout<<people<<' ';
	cout<<endl;
	return 0;
}