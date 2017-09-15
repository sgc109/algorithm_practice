/*
https://community.topcoder.com/stat?c=problem_statement&pm=11434

풀이1과 거의 동일한데 재귀함수의 구현 형태가 조금 다르다 풀이1 이 더 빠를것 같지만 이렇게도 생각해 볼 수 있을 것 같아서 써본다.
처음에 길이 N인 덩어리가 있는데 이걸 길이가 1인 덩어리 까지 나누어 가는 과정을 생각해보자. 각각의 소인수들의 지수들을 모두 더한 값을 S라고해보자
이 S가 최대한 나눌 수 있는 횟수일 것이고, 그렇다면 답은 아무리 커도 저 값보다 작거나 같을 것이다. 왜냐하면 길이가 1인 덩어리로 나눠 버리면
우리가 가져가고자 하는 칸은 무조건 가져갈 수가 있기 때문이다. 그렇다면 나누는 순서에 대한 모든 경우의 수를 보면서 매 순간 순간 마다 중간에 
맨 왼쪽 칸과의 최소거리 + 지금까지 나눈 횟수의 최소값을 구하면 이게 답이될 것이다.

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

class DivideAndShift{
public:
	map<int,int> mp;
	vii cnts;
	int ans;
	int n,m;
	int size;
	void go(int cnt, int mult){
		int chunkSize = n/mult;
		int objPos = (m-1)%chunkSize;
		ans=min(ans,cnt + min(objPos,chunkSize-objPos));
		if(mult==n) return;
		FOR(i,size){
			if((n/mult)%cnts[i].first==0) go(cnt+1, mult*cnts[i].first);
		}
	}

	int getLeast(int N, int M){
		n = N, m = M;
		ans = INF;
		int now = N;
		while(now>1){
			for(int i = 2; i <= now; i++){
				if(now%i==0) {
					mp[i]++;
					now/=i;
					break;
				}
			}
		}
		for(auto it = mp.begin(); it != mp.end(); it++){
			cnts.pb({(*it).first,(*it).second});
		}
		size = sz(cnts);
		go(0,1);
		return ans;
	}
};