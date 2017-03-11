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

int n,m,k;
int fridge[1000003];
int store[1000003];
int cntFridge[10000003];
int cntStore[10000003];
int cntAns[10000003];
int drinkSchedule[10000003];
int maxD;
void NO(){
	printf("-1");
	exit(0);
}
int main() {
	inp3(n,m,k);
	FOR(i,n){
		inp1(fridge[i]);
		cntFridge[fridge[i]]++;
		maxD = max(maxD, fridge[i]);
	}
	FOR(i,m) {
		inp1(store[i]);
		cntStore[store[i]]++;
		maxD = max(maxD, store[i]);
	}
	int day=maxD;
	for(int i = maxD; i>=0; i--){
		day=min(day,i);
		while(cntFridge[i] && day>=0){
			int need = k-drinkSchedule[day];
			if(cntFridge[i] >= need) {
				cntFridge[i]-=need;
				drinkSchedule[day]+=need;
				day--;
			}
			else {
				drinkSchedule[day]+=cntFridge[i];
				cntFridge[i]=0;
			}
		}
		if(cntFridge[i]>0) NO();
	}
	int ans=0;
	day = maxD;
	for(int i = maxD; i>=0; i--){
		day=min(day,i);
		while(cntStore[i] && day>=0){
			int need = k-drinkSchedule[day];
			if(cntStore[i] >= need) {
				cntStore[i]-=need;
				drinkSchedule[day]+=need;
				day--;
				ans+=need;
				cntAns[i]+=need;
			}
			else {
				drinkSchedule[day]+=cntStore[i];
				ans+=cntStore[i];
				cntAns[i]+=cntStore[i];
				cntStore[i]=0;
			}
		}
	}
	printf("%d\n",ans);
	FOR(i,m){
		if(cntAns[store[i]]) printf("%d ",1+i), cntAns[store[i]]--;
	}
	return 0;
}
