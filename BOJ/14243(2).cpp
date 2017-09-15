#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

string ans;
int cnt[3];
int last[3];
int fake[3];
void NO(){
	cout << -1;
	exit(0);
}
void update(char c, int pos){
	cnt[c - 'A']--;
	if(c == 'A'){
		if(fake[1]) ans += 'B', fake[1]--;
		else if(fake[2]) ans += 'C', fake[2]--;
		else ans += 'A';
	}
	else ans += c;

	last[c - 'A'] = max(last[c - 'A'], pos);
}
bool check(string& a, string& b){
	int cnt1[3] = {0, };
	int cnt2[3] = {0, };
	for(int i = 0 ; i < sz(a); i++) cnt1[a[i] - 'A']++;
	for(int i = 0 ; i < sz(b); i++) cnt2[b[i] - 'A']++;
	for(int i = 0 ; i < 3; i++) if(cnt1[i] != cnt2[i]) return false;
	int lst[3] = {-inf, -inf, -inf};
	for(int i = 0 ; i < sz(b); i++){
		int id = b[i] - 'A';
		if(lst[id] >= i - id) return false;
		lst[id] = max(lst[id], i);
	}
	return true;
}
int main() {
	// fastio();
	memset(last,0xc3,sizeof(last));
	string S;
	cin >> S;
	for(int i = 0 ; i < sz(S); i++) cnt[S[i] - 'A']++;
	while(1){
		int pos = sz(ans);
		if(cnt[2] == 1 && last[2] < pos - 2) cnt[0]++, cnt[2]--, fake[2]++;
		if(cnt[1] == 1 && last[1] < pos - 1) cnt[0]++, cnt[1]--, fake[1]++;
		if(cnt[0] && cnt[1] && cnt[2]){
			if(cnt[1] > cnt[2]){
				update('C', pos++);
				update('B', pos++);
				update('A', pos++);
				update('B', pos++);
			}
			else {
				update('C', pos++);
				update('B', pos++);
				update('A', pos++);
			}
		}
		else if(cnt[0] && cnt[1]){
			if(last[1] >= pos - 1) update('A', pos);
			else update('B', pos);
		}
		else if(cnt[1] && cnt[2]){
			if(last[1] >= pos - 1 && last[2] >= pos - 2) NO();
			else if(last[1] < pos - 1) update('B', pos);
			else update('C', pos);
		}
		else if(cnt[0] && cnt[2]){
			if(last[2] >= pos - 2) update('A', pos);
			else update('C', pos);
		}
		else if(cnt[0]){
			while(cnt[0]) update('A', pos);
		}
		else if(cnt[1]){
			if(last[1] >= pos - 1) NO();
			update('B', pos);
		}
		else if(cnt[2]){
			if(last[2] >= pos - 2) NO();
			update('C', pos);
		}
		else break;
	}
	// assert(check(S, ans));
	cout << ans;
	return 0;
}