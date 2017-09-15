/*
그냥 재귀함수로 구현하면된다
인자로는 상하반전여부와 색반전여부 그리고 남아있는 왼쪽끝과 오른쪽끝만 가지고있으면된다
왜냐하면 공을 빼도 양 끝으로만 빠져나가기 때문에 가운데는 그대로 남아있게 되기떄문에 좌 혹은 우로 한칸씩만 변하게 되기때문이다.
시간 복잡도는 O(N) 즉 10만번정도 돈다.
*/

#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

class MathContest{
public:
	string S;
	int ans;
	void go(int l, int r, int rev, int inv){
		if(l>r) return;
		int pos = (rev?r:l);
		char color = (S[pos]=='W'&&!inv) || (S[pos]=='B'&&inv)?'W':'B';
		if(rev) r--;
		else l++;
		if(color=='B') inv^=1,ans++;
		else rev^=1;
		go(l,r,rev,inv);
	}
	int countBlack(string ballSequence, int repetitions){
		FOR(i,repetitions) S+=ballSequence;
		ans=0;
		go(0,sz(ballSequence)*repetitions-1,0,0);
		return ans;
	}
};