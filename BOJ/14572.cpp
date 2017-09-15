#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct student{
	int skill;
	vector<int> knowProb;
	bool operator<(const student& lhs) const{
		return skill < lhs.skill;
	}
};
int N,K,D;
student students[100003];
int cnt[33];
int main() {
	cin >> N >> K >> D;
	for(int i = 0 ; i < N ; i++){
		int k;
		cin >> k >> students[i].skill;
		for(int j = 0 ; j < k; j++){
			int a;
			cin >> a;
			students[i].knowProb.push_back(a);
		}
	}
	sort(students,students+N);
	int lo = 0, hi = 0;
	int ans = 0;
	while(hi < N-1){
		for(;students[hi].skill - students[lo].skill <= D && hi < N; hi++){
			for(auto prob : students[hi].knowProb) cnt[prob]++;
		}

		int knowAll = 0;
		int allKnow = 0;
		for(int i = 1; i <= 30; i++) {
			if(cnt[i] > 0) knowAll++;
			if(cnt[i] == hi-lo) allKnow++;
		}
		ans = max(ans,(knowAll - allKnow)*(hi-lo));
		for(;students[hi].skill - students[lo].skill > D && lo < hi; lo++){
			for(auto prob : students[lo].knowProb) cnt[prob]--;	
		}
	}

	cout << ans;
	return 0;
}
