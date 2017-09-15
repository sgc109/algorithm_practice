#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
vector<pair<double,int> > v;
int main() {
	cin >> N;
	int me;
	for(int i = 0 ; i < N; i++){
		double a,b;
		cin >> a >> b;
		if(a == 97 && b == 81.75) me = i;
		v.push_back({-(a+b), i});
	}	
	sort(v.begin(), v.end());
	for(int i = 0 ; i < v.size(); i++){
		if(v[i].second == me) {
			cout << "my rating : " << i+1 << endl;
			break;
		}
	}
	return 0;
}