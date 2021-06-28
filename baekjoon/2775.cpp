#include <iostream>

using namespace std;

int apt[15][15] = { 0, };


int main(void){
	std::ios::ios_base::sync_with_stdio(false);

	int tc, last_work = 0;

	cin >> tc;

	while (tc--){

		int floor, room;

		cin >> floor;
		cin >> room;

		int i, j, k;

		if (apt[0][0] == 0) {
			int rise = 1;
			for (i = 0; i < room; i++){
				apt[0][i] += rise;
				++rise;
			}
		}

		if(apt[0][0]) {
			for (i = 1; i < floor; i++) {
				for (j = 0; j < room; j++){
					for (k = 0; k < j + 1; k++){
						apt[i][j] += apt[i - 1][k];
					}
				}
			}
		}

		int result = 0;

		for (j = 0; j < room; j++)
			result += apt[floor - 1][j];

		cout << result << endl;

		for (i = 0; i < floor; i++){
			for (j = 0; j < room; j++){
				apt[i][j] = 0;
			}
		}
	}
}
