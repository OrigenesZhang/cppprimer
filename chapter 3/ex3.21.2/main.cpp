#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
int main(){
	vector<int> v;
	int num;
	if(cin>>num){
		v.push_back(num);
		while(cin>>num) v.push_back(num);
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	if(v.size()%2!=0){
		cerr<<"This set has odd number of integers."<<endl;
		return -1;
	}
	for(auto it=v.cbegin()+1; it!=v.cend(); ++it)
		cout<<(*it)+(*(it-1))<<endl;
	return 0;
}