/*
https://community.topcoder.com/stat?c=problem_statement&pm=11379

이 문제는 N개의 상한이 주어지고 그 상한보다 작거나 같은 수들을 N개 선택하여 그 N개의 합과 OR 이 같은 경우의 수를 구하는 문제이다.
조금만 생각해보면 상한보다 작거나 같은 N개의 수를 2진수로 표현했을 때 각각의 비트가 겹치지 않는 수들의 조합을 구하라는 말과 동치임을 알 수 있다.
그렇다면 우선 상한읜 최대 10^18 이니까 64개의 비트면 충분히 표현 가능할 것이다. 그렇다면 63번째 비트부터 차례로 내려가면서 각각의 상한을 넘지
않도록 어떤 수에게 1을 줄 것인지를 결정하면 된다.(물론 아무 수에게도 1을 안줘도됨) 어떤 수에게 1을 줄 것인지 결정하는 부분은 그냥 
재귀 함수 내에서 반복문으로 구현하면 되는데 문제는 각각의 수마다 상한을 넘는지 넘지 않는지를 체크 해줘야 하는데 어떤 수에게 1을 주면 수가 변하기
때문에 그에 대한 정보가 인자로 필요하다. 그런데 모든 수를 인자로 주기엔 O(64*10^19) 개의 공간이 필요하므로 힘들다.
좀만 생각해보면 상한을 2진수로 표현했을 때 특정 자리가 1인데 그 자리에 이 수에게 1을 주지 않으면 그 아래 자리에 아무리 1을 줘도 절대 상한을 
넘지 않는 다는 것을 알 수가 있고, 상한을 2진수로 표현했을 때 특정 자리가 0이면 절대로 1을 줄 수가 없다는 것을 알 수가 있다.
이걸 그때 그때 적절히 갱신해 주기 위해서는 매 자리수 마다 N개 각각의 상한이 1인지를 봐서 지금 1을 주는 수를 제외하곤 모두 bit를 켜주면 된다.
(구현할땐 현재 자리수의 상한비트가 1인 수를 미리 다 켜놓고 실제로 1을 줄 수를 고를때 그 수만 꺼주면된다. 단, )
그렇다면 비트마스크로 현재 보고있는 자리수에서  k번째 수가 1이되도 절대 상한을 넘을 가능성이 없는지에대한 여부를 0과 1로 저장하고있고 그때그때
잘 갱신해 준다면 상한을 넘기지 않도록 쉽게 처리해 줄 수가 있다.

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
const int MOD = 1e9+9;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
class YetAnotherORProblem{
public:
	int dp[61][1<<10];
	int N;
	long long A[10];
	int go(int pos, int state){
		if(pos<0) return 1;
		int& cache = dp[pos][state];
		if(cache != -1) return cache;
		int newState = state;
		for(int i = 0 ; i < N; i++){
			if(state&(1<<i)) continue;
			if(A[i]&(1ll<<pos)) newState|=(1<<i);
		}

		int ret = go(pos-1, newState);
		for(int i = 0; i < N; i++){
			int code = (state&(1<<i))>>i;
			if(code==0){
				bool isOff = (A[i]&(1ll<<pos))==0;
				if(!isOff) ret = (ret + go(pos-1, newState^(1<<i))) % MOD;
			}	
			else if(code==1) ret = (ret + go(pos-1, newState)) % MOD;
		}
		return cache = ret;
	}
	int countSequences(vector<long long> R){
		memset(dp,-1,sizeof(dp));
		N = R.size();
		for(int i = 0; i < N; i++) A[i] = R[i];
		return go(60,0);
	}
};