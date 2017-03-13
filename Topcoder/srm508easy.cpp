/*
https://community.topcoder.com/stat?c=problem_statement&pm=11434

이 문제는 수학적 지식이 필요하다. 우선 문제에서 칸들이 K개가 있을 때 K의 약수이면서 소수인 수로 나눌 수가 있다고 했는데
이것은 바로 매 회에 소인수로 한번 나눌 수 있다는 것을 의미한다. 그렇기 때문에 소인수 분해를 했을 때 소인수들의 지수 들을 모두 더한 값이
최대한으로 나눌 수 있는 횟수인 것 이다. 그렇다면 우리가 특정 칸을 가져가기 위한 최소 횟수가 있다고 치면 그 최적해는
몇번은 나눌것이고 몇번은 옆으로 이동시킬 것이다. 우선 나누는 행위를 먼저 보면 각각의 소인수 마다 나누는 횟수가 있을 거고 그 횟수는 0일 수도 있을것이다.
그렇다면 각각의 소인수에 대하여 나누는 횟수들의 모든 조합에 대한 경우들을 모두 보면서
우리가 고르려고하는 놈이 맨 왼쪽 칸으로 부터 몇 만큼 떨어져 있는지 봐서 그중 최소 값이 답이 될것이다.
물론 맨 왼쪽 칸으로 부터 떨어진 거리는 min(좌측으로 갔을때 거리, 우측으로 갔을대 거리) 일 것이다.
중요한것 중의 하나는 나누고 옆으로 옮기고 나누고 옆으로 옮기고 하나, 아니면 한번에 나누고 한번에 옮기나 결국 최적해는 같다는 것을 깨닫는것같다.

그리고 또 한가지 중요한것은 소인수 분해인데 2~현재수 를 돌면서 나눠질때마다 map에 나누는수를 인덱스로 하는곳의 값을 1 증가시키고 현재수를 나눈수로
나눠주는 식으로 반복해주면 소수가 아닌수로는 나눌 수가 없는게 그 소수가 아닌수보다 그의 소인수가 더 작기때문에 가기도 전에 그 수로 나눠버리고
다시 2부터 돌기 때문이다. 이걸 현재수가 1이 될때 까지 반복하면 되는데
우선 소인수 분해의 시간복잡도는 각각의 소인수들에 대하여 소인수*지수 를 모두 더한만큼 돌게되는데 N이 최대 100만이기 때문에 얼마 안걸릴 것이다.
그리고 재귀 함수의 시간복잡도도 소인수 분해의 시간복잡도와 같을 것이다.
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
	void go(int cnt, int pos, int mult){
		if(pos==size) {
			int chunkSize = n/mult;
			int objPos = (m-1)%chunkSize;
			ans=min(ans,cnt + min(objPos,chunkSize-objPos));
			return;
		}
		int gob = 1;
		REP(i, 0, cnts[pos].second){
			go(cnt+i,pos+1,mult*gob);
			gob *= cnts[pos].first;
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
		go(0,0,1);
		return ans;
	}
};