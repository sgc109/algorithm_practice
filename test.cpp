#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
vector<string> strs;
vector<int> cnts;
string S[23];
int check[23], incld[23];
int cntAinB(string& A, string& B){
	int ret = 0;
	for(int i = 0 ; i <= sz(B) - sz(A); i++) {
		int ok = 1;
		for(int j = 0; j < sz(A); j++){
			if(B[i + j] != A[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) ret++;
	}
	return ret;
}
int over[23][23];
int mxOver(string& A, string& B){
	for(int i = 1; i < sz(A); i++){
		int ok = 1;
		for(int j = 0; i + j < sz(A); j++){
			if(A[i + j] != B[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) return sz(A) - i;
	}
	return 0;
}
int main() {
	string s1 = "yohohohohohohohohohohohoyo";
	string s2 = "KingGodChungmugongMajestyCoder";
	cout << sz(s2);
	return 0;
	string A = "ABCDE";
	string B = "CDEAB";

	return 0;
}