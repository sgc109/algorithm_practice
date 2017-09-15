/*
https://community.topcoder.com/stat?c=problem_statement&pm=11342

처음에 이 문제가 해석이 너무안돼서 방치해 놓다가 결국 날잡고 스스로 풀었다.
확률에 대한 이해와 숨겨진 규칙의 발견이 요구되는 문제라고 생각한다.
우선 가장 중요한 규칙을 발견해야하는데
맨 처음에 definite decisions 를 바탕으로 다른사람에게 선택된 수를 각각의 사람마다 세어보면
한 명에게도 선택되지 않은 사람은 0, 한 명에게 선택된 사람은 1, ... 이런식으로 가게되는데
선택된 횟수가 모두 0 또는 1이라면 다음번 round 에도 모두가 vulerable 해진다. 왜냐하면
definite decisions 에 포함 되지않은 나머지 사람들에 대해서는 현재 가장 적게 뽑힌 사람들을 랜덤하게 뽑게되는데
그러면 결과적으로 모두 한번씩 뽑히게 되기 때문이다. 그렇기 때문에 저 경우는 return 0.0으로 우선 예외처리를 해준다.

그럼 선택된 횟수가 2이상인 사람이 한명이상 있는 경우를 생각해보자. 이 경우에는 가장 많이 선택된 횟수를 maxCnt 라고했을 때
첫번째 round 에 vulerable 한 사람은 선택된 횟수가 maxCnt 인 사람들이다. 예제를 하나정해서 simulation 해보면 금방 알아챌수있다.
그 다음에는 현재 vulerable 한 사람들 수 * maxCnt 만큼은 일단 이미 선택이 된것이고 나머지, 즉 (N - 저 앞의 수) 만큼의 사람들은
현재 vulerable 한 사람들 중에 현재 가장 득표가 적은사람부터 선택하는데 그러면 차례대로 한표씩 증가하는게 반복되다가 중간에 끊길것이다.
그럼 그 끊기기 전에 표를 받은 사람 수 만큼이 다음 round 의 vulerable 한 사람들의 수 이다. 그런데 여기서 누가 vulerable
할지는 그때 그때 다른데 중요한건 모든 사람들이 득표수가 같을 때 동일한 확률로 아무나 랜덤하게 선택해서 한표를 주기 때문에 
현재 vulerable 한 사람들중 그 누구도 다음번에 vulerable 해질 수 있고 그 확률은 같다는 말이다.
그렇기 때문에 맨 첫번째 라운드에 vulerable 했던 사람들은 모두 질 수가 있고
매 round 마다 모두 같은 확률로 다음 round에도 vulerable 해질 수 있기 때문에 결과적으로 질 확률도 동일한것이다.
그렇기때문에 1/(1 round에 vulerable 한 사람의수) 가 답이된다.
단, 한가지 예외처리를 해주어야 하는데
round 중간에 어떤 경우에도 모든 사람의 득표수가 같은 경우가 생길 수가 있다. 이럴 때는 전 round 에 vulerable 했던 사람들이
또 그대로 vulerable 해지기 때문에 무한히 반복하게 된다. 그렇기 때문에 이때만 return 0.0로 예외처리를 해주면 된다.

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

class MafiaGame{
public:
	int chosenCnt[503];
	double probabilityToLose(int N, vector <int> decisions){
		memset(chosenCnt,0,sizeof(chosenCnt));
		FOR(i,sz(decisions)) chosenCnt[decisions[i]]++;
		int maxCnt=-1;
		FOR(i,N) maxCnt=max(maxCnt,chosenCnt[i]);
		if(maxCnt<=1) return 0.0;
		int initManCnt=0;
		FOR(i,N) if(chosenCnt[i]==maxCnt) initManCnt++;
		int next=0;
		for(int restMan = initManCnt; restMan>1; restMan = next){
			next = (N-maxCnt*restMan)%restMan;
			if(!next) return 0.0;
		}
		return 1.0/initManCnt;
	}
};