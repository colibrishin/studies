#include <iostream>

int main(void) {
	using namespace std;

	ios::ios_base::sync_with_stdio(false);

	int arr_n[10000];
	int lis_n[10000];
	int i, j, t, n, k;
	bool poss = false;

	cin >> t;

	for (i = 0; i < t; ++i) {

		cin >> n >> k;

		for (j = 0; j < n; ++j)
			cin >> arr_n[j];

		for (j = 0; j < n; ++j)
			lis_n[j] = 1;

		for (j = 1; j < n; ++j) {

			for (int j_2 = 0; j_2 < j; ++j_2) {

				if (arr_n[j_2] < arr_n[j] && lis_n[j_2] + 1 > lis_n[j])
					lis_n[j] = lis_n[j_2] + 1;

			}
		}
		
		for(int j = 0; j < n; ++j){
			if(lis_n[j] == k) {
				poss = true;
				break;
			}
		}

		cout << "Case #" << i + 1 << endl;
		if (poss) cout << 1 << endl;
		else cout << 0 << endl;

		poss = false;
	}
}