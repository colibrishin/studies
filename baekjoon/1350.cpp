#include <iostream>

int main(void){
	
	using namespace std;
	ios::ios_base::sync_with_stdio(false);
	
	int t;
	long long size[1000], cluster, rtn;
	
	cin >> t;
	
	for(int i = 0; i < t; ++i) cin >> size[i];
	
	cin >> cluster;
	
	for(int i = 0; i < t; i++){
		rtn += size[i] / cluster;
		if(size[i] % cluster) rtn++;
	}
		
	cout << rtn * cluster;
	
}