#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	map<string, bool, greater<string>> m;

    string str, s;
    int n;
    cin >> n;
    while(n--){
        cin>> str>>s;
        if(s=="enter") m[str] = true;
        else m[str]= false;
    }

    for(auto it : m) 
        if(it.second) cout << it.first << "\n";
	return 0;
}