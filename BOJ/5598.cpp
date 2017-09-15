#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

string str;
int main() {
	cin >> str;
	for(int i = 0 ; i < str.size(); i++){
		int a = str[i]-'A';
		a = (a + 23) % 26;
		printf("%c",a+'A');
	}
	return 0;
}
