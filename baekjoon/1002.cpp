#include <iostream>
#include <cmath>
using namespace std;

int square(int a){
	return a * a;
}

int mkAbsol(int a){
	if (a < 0) return a * -1;
	else return a;
}

int main() {
	int tc;

	cin >> tc;

	while (tc--){
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2){
			if (r1 == r2) cout << -1 << endl;
			else cout << 0 << endl;
		}
		else {
			double dist = sqrt(double(square(x1 - x2) + square(y1 - y2)));

			if (mkAbsol(r1 - r2) > dist || r1 + r2 < dist)
				cout << 0;
			else if (r1 + r2 == dist || mkAbsol(r1 - r2) == dist)
				cout << 1;
			else if (mkAbsol(r1 - r2) < dist && dist < r1 + r2)
				cout << 2;
			cout << endl;
		}
	}
}