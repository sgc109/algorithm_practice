#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 500005;

vector<int> getSA(string& S){
	int n = (int)S.size();
	vector<int> SA(n), g(n+1), tg(n+1);

	for(int i = 0 ; i < n; i++) SA[i] = i;
	for(int i = 0 ; i < n; i++) g[SA[i]] = S[i];
	
	for(int t = 1; t < n; t*=2){
		g[n] = -1;
		auto cmp = [&](int a, int b)->bool{
            if(g[a] == g[b]) return g[a+t] < g[b+t];
            return g[a] < g[b];
        };
		sort(SA.begin(), SA.end(), cmp);

		tg[SA[0]] = 0;
		for(int i = 1 ; i < n; i++) {
			tg[SA[i]] = tg[SA[i-1]] + cmp(SA[i-1], SA[i]);
		}
		g = tg;
	}
	return SA;
}

vector<int> getLCP(string& S, vector<int>& SA){
	int n = (int)S.size();	
	vector<int> LCP(n), rank(n);
	for(int i = 0 ; i < n; i++) rank[SA[i]] = i;
	int k = 0;
	for(int i = 0 ; i < n; i++){
		if(k > 0) k--;
		if(!rank[i]) continue;
		int j = SA[rank[i]-1];
		while(i+k < n && j+k < n && S[i+k] == S[j+k]) k++;
		LCP[rank[i]] = k;
	}
	return LCP;
}

int main() {
	string S,B;
	cin >> S >> B;
	S += '#';
	S += B;
	int n = (int)S.size();
	vector<int> SA = getSA(S);
	vector<int> LCP =  getLCP(S, SA);
	int bLen = (int)B.size();
	int ans = 0;
	int ansb = 0;
	for(int i = 1; i < n; i++){
		int a = SA[i-1];
		int b = SA[i];
		int cond1 = n-a-1 >= bLen;
		int cond2 = n-b-1 >= bLen;
		if(cond1 == cond2) continue;
		if(ans < LCP[i]){
			ans = max(ans, LCP[i]);
			ansb = SA[i];
		}
	}

	cout << ans << endl;
	string ansS = S.substr(ansb, ans);
	cout << ansS << endl;

	return 0;
}