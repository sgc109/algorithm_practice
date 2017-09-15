#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
string str;
int A[2000005];
int main() {
	cin >> T;
	while(T--){
		str = '~';
		string s;
		cin >> N >> s;
		for(int i = 1 ; i <= N; i++){
			str += '#';
			str += s[i-1];
		}
		str += '#';
		str += '!';
		int R = -1, p;
		for(int i = 1 ; i < str.size()-1; i++){
			if(i <= R) A[i] = min(A[2*p -i], R - i);
			else A[i] = 0;
			while(str[i - A[i] - 1] == str[i + A[i] + 1]) A[i]++;
			if(R < A[i] + i) R = A[i] + i, p = i;
		}
		ll ans = 0;
		for(int i = 1; i < str.size()-1; i++) ans += A[i]/2;

		cout << ans << endl;
	}
	return 0;
}