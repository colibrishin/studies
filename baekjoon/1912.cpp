#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
int main(void){
	ios::ios_base::sync_with_stdio(false);
	
	int n;
	int arr[100000] = { 0, };
	int sum[100000] = { 0, };
	int sum_max = INT_MIN;

	cin >> n;

	for(int i = 1; i <= n; ++i) cin >> arr[i];

	for(int i = 1; i <= n; ++i){
		if(sum[i - 1] + arr[i] > arr[i]) sum[i] = sum[i - 1] + arr[i];
		else sum[i] = arr[i];
	}

	for(int i = 1; i <= n; ++i) sum_max = max(sum_max, sum[i]);
	cout << sum_max;
}