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
	for(int i = 0 ; i < n; i++) g[SA[i]] = S[i] - 'a';
	
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
	string S;
	cin >> S;
	vector<int> SA = getSA(S);
	vector<int> LCP =  getLCP(S, SA);
	for(int i = 0 ; i < (int)SA.size(); i++) printf("%d ", SA[i]+1);
	printf("\nx ");
	for(int i = 1 ; i < (int)LCP.size(); i++) printf("%d ", LCP[i]);
	return 0;
}