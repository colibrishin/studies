#include <iostream>
#include <string>

int main() {
	using namespace std;
	ios::ios_base::sync_with_stdio(false);
	
	string msg;
	char cip[10001];
	msg.reserve(10001);
	int cycle, p, i, did, n = 1, blank;
	
	while(n) {
		cycle = 0;
		p = 0;
		i = 0;
		did = 0;
		blank = 0;

		cin >> n;
		cin.ignore(1);
		if(n == 0) break;

		getline(cin, msg);

		if (n > msg.length()) {
			for (int i = 0; i < msg.length(); i++) {
				if (msg[i] == 32) msg.erase(msg.begin() + i);
				if (msg[i] >= 91) cip[i] = msg[i] -= 32;
				else cip[i] = msg[i];
			}
		}
		
		else {
			for (int i = 0; i < msg.length(); i++)
				if (msg[i] == 32) blank++;

			while (did != (msg.length() - blank)) {
				while (msg[i] == 32) i++;
				if (msg[i] >= 91) msg[i] -= 32;

				cip[p] = msg[i];
				++did;
				p += n;
				i++;

				if (p >= msg.length() - blank) {
					++cycle;
					p = cycle;
				}
			}
		}
		
		for (int i = 0; i < msg.length() - blank; i++)
			cout << cip[i];
		cout << endl;
	}
	return 0;
}