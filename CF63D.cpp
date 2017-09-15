#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int a,b,c,d,n;
char pane[53][103];
int cnt[30];
int curAlpha;
int main() {
	int swapped = 0;
	cin >> a >> b >> c >> d >> n;
	if(b > d) {
		swapped = 1;
		swap(a,c);
		swap(b,d);
	}
	for(int i = 1; i <= max(b,d); i++){
		for(int j = 1 ; j <= a+c; j++){
			pane[i][j] = '.';
		}
	}

	for(int i = 0 ; i < n; i++) cin >> cnt[i];
	for(int j = 1 ; j <= a; j++){
		if((j+a) % 2 == 0) {
			for(int i = b; i >= 1; i--){
				pane[i][j] = curAlpha+'a';
				if((--cnt[curAlpha]) == 0) curAlpha++;
			}
		}
		else {
			for(int i = 1; i <= b; i++){
				pane[i][j] = curAlpha+'a';
				if((--cnt[curAlpha]) == 0) curAlpha++;
			}
		}
	}

	for(int j = a+1 ; j <= a+c; j++){
		if((j-a) % 2 == 0) {
			for(int i = d; i >= 1; i--){
				pane[i][j] = curAlpha+'a';
				if((--cnt[curAlpha]) == 0) curAlpha++;
			}
		}
		else {
			for(int i = 1; i <= d; i++){
				pane[i][j] = curAlpha+'a';
				if((--cnt[curAlpha]) == 0) curAlpha++;
			}
		}
	}
	if(swapped){
		for(int i = 1; i <= max(b,d); i++) reverse(pane[i]+1, pane[i]+1+a+c);
	}
	cout << "YES" << endl;
	for(int i = 1; i <= max(b,d); i++){
		for(int j = 1; j <= a+c; j++){
			cout << pane[i][j];
		}
		cout << endl;
	}
	return 0;
}