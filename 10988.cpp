#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

string str;
int main() {
	cin >> str;
	int isPalin = 1;
	for(int i = 0 ; i < str.size()/2; i++){
		if(str[i] != str[str.size()-1-i]) isPalin = 0;
	}
	printf("%d",isPalin);
	return 0;
}
