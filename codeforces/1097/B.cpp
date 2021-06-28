#include<iostream>
#include<vector>
using namespace std;
 
bool findzero(vector<int> &v, int n, int crad){
	if(n==0){ if(crad%360==0) return true;
else return false;
}
	vector<int> nv(v);
	int tg;
	for(int i=0;i<n;++i){
		nv=v, tg = *(nv.begin()+i), nv.erase(nv.begin()+i);
		return findzero(nv, n-1, crad-tg) + findzero(nv, n-1, crad+tg);
	}
}
 
 
 
int main(void){
	ios::ios_base::sync_with_stdio(false), cin.tie(nullptr);
	vector<int> v;
	int n,tmp;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>tmp;
		v.push_back(tmp);
	}
	cout<<(findzero(v,n,0)?"YES":"NO");
}
