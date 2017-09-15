#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

string plas(string A, string B){
	string ret;
	int lenA = sz(A), lenB = sz(B);
	if(lenA > lenB) swap(A, B), swap(lenA, lenB);
	reverse(all(A));
	reverse(all(B));
	int carry = 0;
	for(int i = 0 ; i < lenA; i++){
		int sum = A[i] -'0' + B[i] - '0' + carry;
		if(sum >= 10) carry = 1, sum -= 10;
		else carry = 0;
		ret += sum + '0';
	}

	for(int i = lenA; i < lenB; i++){
		int sum = B[i] - '0' + carry;
		if(sum >= 10) carry = 1, sum -= 10;
		else carry = 0;
		ret += sum + '0';
	}
	if(carry) ret += '1';
	reverse(all(ret));
	return ret;
}
string ans, s;
int main() {

	// string A = "0", B = "109";
	// string C = plas(A, B);
	// cout << C;
	string ans = "0";
	for(int i = 0 ; i < 100; i++){
		cin >> s;
	 	ans = plas(ans, s);
	}

	for(int i = 0 ; i < 10; i++) cout << ans[i];
	
	return 0;
}