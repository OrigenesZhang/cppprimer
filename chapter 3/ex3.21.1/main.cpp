#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
int main(){
	vector<string> v;
	string word;
	if(cin>>word){
		v.push_back(word);
		while(cin>>word) v.push_back(word);
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	for(auto it1=v.begin(); it1!=v.end(); ++it1)
		for(auto it2=it1->begin(); it2!=it1->end(); ++it2)
			*it2=toupper(*it2);
	int cnt=0;
	for(auto it=v.cbegin(); it!=v.cend(); ++it){
		++cnt;
		cout<<*it;
		if(cnt!=8){
			cout<<' ';
		}else{
			cout<<endl;
			cnt=0;
		}
	}
	return 0;
}