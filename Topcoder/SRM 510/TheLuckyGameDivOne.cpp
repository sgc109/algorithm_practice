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

class TheLuckyGameDivOne {
public:
    ll A,B,JLen,BLen;
    vector<ll> luckyNum;
    void go(ll here){
        if(here>B) return;
        if(A <= here && here <= B) luckyNum.pb(here);
        go(here*10+4);
        go(here*10+7);
    }
    int cntLucky(ll s, ll e){
        return lower_bound(all(luckyNum),e+1) - lower_bound(all(luckyNum),s);
    }
    int findMinCnt(ll L, ll bLen) {
        ll s = L - bLen + 1;
        if(s < A || s + JLen - 1 > B) return 0;
        int bs = lower_bound(all(luckyNum),s) - luckyNum.begin();
        int ret = INF;
        for(int i = bs; i < sz(luckyNum) && 1+luckyNum[i]+bLen-1 <= s+JLen-1; i++){
            ret = min(ret, cntLucky(1+luckyNum[i],1+luckyNum[i]+bLen-1));
        }
        ret = min(ret, cntLucky(s,s+bLen-1));
        return ret;
    }
    int find(long long a, long long b, long long jLen, long long bLen) {
        A = a, B = b, JLen = jLen, BLen = bLen;
        int ans = 0;
        go(0);
        sort(all(luckyNum));
        for(auto L : luckyNum){
            ans = max(ans,findMinCnt(L, bLen));
        }
        ans = max(ans,findMinCnt(a + bLen - 1, bLen));
        return ans;
    }
};