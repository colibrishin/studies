#include <iostream>
#include <vector>

long long trr_init(std::vector<long long> &arr, std::vector<long long> &trr, int n, int b, int e) {
	if (b == e) return trr[n] = arr[b];
	else return trr[n] = trr_init(arr, trr, n * 2, b, (b + e) / 2) + 
						 trr_init(arr, trr, n * 2 + 1, (b + e) / 2 + 1, e);
}

long long trr_sum(std::vector<long long> &trr, int n, int b, int e, int l, int r){
	if (l > e || r < b) return 0;
	if (l <= b && e <= r) return trr[n];
	return trr_sum(trr, n * 2, b, (b + e) / 2, l, r) + 
		   trr_sum(trr, n * 2 + 1, (b + e) / 2 + 1, e, l, r);
}

void trr_update(std::vector<long long> &trr, int n, int b, int e, int i, long long tgt) {
	if (i < b || i > e) return;
	trr[n] = trr[n] + tgt;
	if (b != e) {
		trr_update(trr, n * 2, b, (b + e) / 2, i, tgt);
		trr_update(trr, n * 2 + 1, (b + e) / 2 + 1, e, i, tgt);
	}
}

int main(void) {
	using namespace std;
	ios::ios_base::sync_with_stdio(false);

	int n, m, k;
	vector<long long> arr(1000000), trr(4000000);

	cin >> n >> m >> k;
	m += k;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	trr_init(arr, trr, 1, 0, n - 1);

	int a, b;
	long long c, tgt;

	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			--b;
			tgt = c - arr[b];
			arr[b] = c;
			trr_update(trr, 1, 0, n - 1, b, tgt);
		}
		
		else cout << trr_sum(trr, 1, 0, n - 1, b - 1, c - 1) << endl;
	}
}