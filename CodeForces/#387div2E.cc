#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>	
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

string S;
stack<int> s;
vector<string> ans[1000000];
int main() {
	cin >> S;
	s.push(INF);
	int prev=0;
	int cnt=0;
	string str;
	string pushStr;
	int num;
	int depth=0;
	FOR(i,S.size()+1){
		if(i < S.size() && S[i]!=',') continue;
		cnt++;
		str = S.substr(prev,i-prev);
		prev = i+1;
		if(cnt%2==0) {
			num=stoi(str);
			while(s.top()==0) {
				s.pop();
				depth--;
			}
			int t = s.top();
			s.pop();
			s.push(t-1);
			ans[depth].pb(pushStr);
			if(num==0) continue;
			s.push(num);
			depth++;
		}
		else pushStr = str;
	}

	int ansCnt=0;
	FOR(i,1000000) {
		if(ans[i].size()==0) break;
		ansCnt++;
	}
	printf("%d\n",ansCnt);
	FOR(i,1000000){
		if(ans[i].size()==0) break;
		FOR(j,ans[i].size()){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}