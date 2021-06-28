#include <iostream>
using namespace std;
int list[19] = { 3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467 };

bool comblist(int n) {
	//cout << n << endl;
	if (n < 0 || list[0] > n) return false;
	if (n == 0) return true;

	bool ret = false;
	for (int i = 18; i >= 0; --i) {
		if (list[i] > n) continue;
		ret += comblist(n - list[i]);
	}

	return ret;
}


int main() {
	int n;
	cin >> n;
	cout << (comblist(n) ? "YES" : "NO");

	return 0;
}