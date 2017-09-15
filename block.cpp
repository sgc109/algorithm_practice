#include <vector>
#include <iostream>
using namespace std;
const int inf = 0x3c3c3c3c;

int T,N,a;
int go(vector<int> t){
	int n = t.size();
	int mintime = inf;
	for(int i = 0 ; i < n; i++) {
		if(t[i] < n-i && t[i] < i+1) mintime = min(mintime, t[i]);
	}
	vector<int> nt;
	for(int i = 0 ; i < n; i++){
		if(t[i] < n-i && t[i] < i+1 && t[i] == mintime) nt.push_back(t[i]);
		else if(min(t[i], min(n-i, i+1)) > mintime) nt.push_back(t[i]);
	}
	t = nt;
	n = t.size();
	vector<int> cutP;
	for(int i = 0 ; i < n; i++) {
		if(t[i] < n-i && t[i] < i+1 && t[i] == mintime) cutP.push_back(i);
	}
	if(cutP.size() == 0) return (n+1)/2;
	for(int i = 0 ; i < n; i++) t[i] -= mintime;
	int ret = 0;
	int cur = 1;
	cutP.push_back(n-1);
	for(int i = 0 ; i < cutP.size(); i++){
		vector<int> v(t.begin() + cur, t.begin() + cutP[i]);
		ret = max(ret, mintime + go(v));
		cur = cutP[i] + 1;
	}
	return ret;
}
int main() {
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		cin >> N;
		vector<int> towers(N);
		for(int i = 0 ; i < N; i++) cin >> towers[i];
		cout << "Case #" << t << endl;
		cout << go(towers) << endl;
	}
	return 0;
}