#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,K;
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> K;
		queue<pair<int,unsigned long long>> q;
		q.push({0,1ll});
		unsigned long long ansm = 1e18;
		while(!q.empty()){
			int curD = q.front().first;
			unsigned long long cur = q.front().second;
			q.pop();
			if(curD == K) {
				ansm = min(ansm, cur);
				continue;
			}
			if((cur-1)%3==0 && (cur-1)/3%2==1 && cur!=4) q.push({curD+1, (cur-1)/3});
			q.push({curD+1, cur*2});
		}
		cout << "Case #" << t << "\n";
		cout << ansm << " " << ((unsigned long long)1<<K) << "\n";
	}
	return 0;
}