#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int tc;

	cin >> tc;

	while (tc--){
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2){
			if(r1 == 0 && r2 == 0)
			{
				cout << 1 << endl;
			}
			else if (r1 == r2)
			{
				cout << -1 << endl;
			}
			else 
			{
				cout << 0 << endl;
			}
		}
		else {
			double dist = sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));

			if (std::abs(r1 - r2) > dist || r1 + r2 < dist)
				cout << 0;
			else if (std::abs(r1 - r2) == dist || r1 + r2 == dist)
				cout << 1;
			else if (std::abs(r1 - r2) < dist && dist < r1 + r2)
				cout << 2;
			cout << endl;
		}
	}
}