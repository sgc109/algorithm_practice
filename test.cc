#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <utility>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
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
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

bool cmp(const string& lhs, const string& rhs){
    return sz(lhs) < sz(rhs);
}

class TheLotteryBothDivs{
public:
    double find(vector<string> goodSuffixes){
        sort(all(goodSuffixes),cmp);
        vector<string> vs;
        for(auto s : goodSuffixes){
            bool found=false;
            for(auto ss : vs){
                FOR(i,sz(ss)){
                    if(s[sz(s)-i-1]!=ss[sz(ss)-i-1]) break;
                    if(i==sz(ss)-1) found=true;
                }
            }
            if(found) continue;
            vs.pb(s);
        }
        int memo[12];
        memset(memo,0,sizeof(memo));
        for(auto s : vs) memo[sz(s)]++;
            double b = 0.1;
        double ret=0;
        for(int i = 1; i <= 10; i++,b/=10){
            ret+=b*memo[i];
        }
        return ret;
    }
};
int main() {
    TheLotteryBothDivs test;
    printf("%.10lf",test.find({"47", "58", "4747", "502"}));
    return 0;
}
