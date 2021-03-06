#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
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
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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

ll pSum[10003];
ll A[10003];
int N;
ll dp[10003];
ll go(int pos, ll sum){
    if(pos==N) return dp[pos]=1;
    ll& cache = dp[pos];
    if(cache != -1) return cache;
    cache=0;
    for(int i = pos+1; i <= N; i++){
        if(pSum[i]-pSum[pos]==sum){
            cache+=go(i,sum);
            cache%=MOD;
        }
    }
    return cache;
}
int main() {
    inp1(N);
    FOR(i,N) scanf("%lld",A+i), pSum[i+1] = pSum[i] + A[i];
    
    ll ans = 0;
    vector<long long > valid;
    for(int i=1;i<=N;i++){
        if(pSum[i]!=0 && pSum[N]%pSum[i]==0)valid.push_back(pSum[i]);
    }
    sort(valid.begin(),valid.end());
    valid.erase(unique(valid.begin(),valid.end()),valid.end());
    if(pSum[N]==0)valid.clear(),valid.push_back(0);
    
    for(int i=0;i<valid.size();i++){
        memset(dp,-1,sizeof(dp));
        ans=(ans%MOD+go(0,valid[i])%MOD)%MOD;
    }
    printf("%lld",(ans-1+MOD)%MOD);
    return 0;
}