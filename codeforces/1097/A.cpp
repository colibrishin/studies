#include<iostream>
#include<set>
#include<set>
using namespace std;
 
int main(void){
	string own;
	char tmp;
	set<char> hand;
	
	ios::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>own;
	cin.ignore();
	for(int i=0;i<5;++i){
		for(int j=0;j<2;++j){
			cin.get(tmp);
			hand.insert(tmp);
		}
		cin.get(tmp);
	}
	
	cout<<(((hand.find(own[0])!=hand.end())+(hand.find(own[1])!=hand.end()))?"YES":"NO");
}
