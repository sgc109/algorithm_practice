#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).sz())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, pair<int, int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N, T, a, b, c, sz;
struct Node {
	int sum;
	int maxPsum;
	Node(int a, int b):sum(a),maxPsum(b){}
	Node(){}
};
struct Mine {
	int x, y, kind;
	Mine(int a, int b, int c):x(a),y(b),kind(c){}
	Mine(){}
	bool operator<(const Mine& rhs)const {
		return x<rhs.x;
	}
};
Node d[400003];
Mine mines[100003];
int arr[100003];
int leftIron, rightCu;
void init() {
	for (int i = 2 * sz; i>sz - 1; i--) d[i].maxPsum = max(d[i].sum, 0);
	for (int i = sz - 1; i >= 1; i--) {
		d[i].sum = d[2 * i].sum + d[2 * i + 1].sum;
		d[i].maxPsum = max(d[2 * i].maxPsum, d[2 * i].sum + d[2 * i + 1].maxPsum);
	}
}
void update(int pos) {
	pos += sz;
	d[pos].sum = -d[pos].sum;
	d[pos].maxPsum = max(d[pos].sum, 0);
	for (int i = pos / 2; i >= 1; i >>= 1) {
		d[i].sum = d[i * 2].sum + d[i * 2 + 1].sum;
		d[i].maxPsum = max(d[2 * i].maxPsum, d[2 * i].sum + d[2 * i + 1].maxPsum);
	}
}
int main() {
	inp1(T);
	for (int t = 0; T - t; t++) {
		leftIron = 0, rightCu = 0;
		FOR(i, 400003) d[i] = Node(0,0);
		inp1(N);
		for(sz=1; sz<N;sz<<=1){}
		FOR(i, N) {
			inp3(a, b, c);
			a--, b--;
			mines[i] = Mine(a,b,c);
			if (c == 0) d[b + sz].sum--, rightCu++;
			else d[b + sz].sum++;
		}
		sort(mines, mines + N);
		init();
		int ans = -1;
		FOR(i, N) {
			ans = max(ans, leftIron + rightCu + d[1].maxPsum);
			update(mines[i].y);
			if (mines[i].kind == 0) rightCu--;
			else leftIron++;
		}
		ans = max(ans, leftIron + rightCu + d[1].maxPsum);
		printf("Case #%d\n%d\n", t + 1, ans);
	}
	return 0;
}
