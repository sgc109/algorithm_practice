#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>  
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;


int map[12][5002];
int cntCover[29];
int cover[29];
int stainStat[5002];
bool exist[8];
int cntStat;
int dp[5002][29][29];
pii stainPos[1002];
void dfs(int here){
    if(here>=8){
        int stat=0;
        int cnt=0;
        FOR(i,8){
            if(exist[i]){
                cnt++;
                stat |= (1<<(i+2));
                stat |= (1<<(i+1));
                stat |= (1<<i);
            }
        }
        cover[cntStat] = stat;
        cntCover[cntStat++] = cnt;
        return;
    }
    exist[here]=true;
    dfs(here+3);
    exist[here]=false;
    dfs(here+1);
}
int main() {
    dfs(0);
    cover[cntStat] = (1<<10)-1;
    cntCover[cntStat++] = 4;
    int T;
    inp1(T);
    FOR(t,T){
        memset(map,0,sizeof(map));
        memset(dp,0x3c,sizeof(dp));
        int m,n,c;
        inp3(m,n,c);
        FOR(i,c){
            int y,x;
            inp2(y,x);
            stainPos[i] = mp(x-1,y-1);
        }
        // 좌표압축
        sort(stainPos,stainPos+c);

        vi Xs;
        FOR(i,c){
            if(i==0 || stainPos[i-1].first != stainPos[i].first) Xs.pb(stainPos[i].first);
        }

        vi comp;
        FOR(i,Xs.size()){
            if(i==0)comp.pb(0);
            else {
                if(Xs[i]-Xs[i-1] <= 3) comp.pb(comp.back()+Xs[i]-Xs[i-1]);
                else comp.pb(comp.back()+3);
            }
        }

        FOR(i,c){
            stainPos[i].first = comp[lower_bound(Xs.begin(),Xs.end(),stainPos[i].first)-Xs.begin()];
        }

        int lastX = stainPos[c-1].first;

        FOR(i,c) {
            map[stainPos[i].second][stainPos[i].first] = 1;
        }

        bool existImposs = false;
        // 폭격 불가능한 지점이 있는지 확인
        FOR(i,c){
            int xx = stainPos[i].first;
            int yy = stainPos[i].second;
            for(int y = max(0,yy-2); y < min(m,yy+3); y++) {
                for(int x = max(0,xx-2); x < min(n,xx+3); x++) {
                    if(x==xx && y==yy) continue;
                    if(map[y][x]==1) goto hell;
                }
            }
            existImposs = true;
            break;
            hell:
            1;
        }
        if(existImposs) {
            printf("Case #%d\n-1\n",t+1);
            continue;
        }

        FOR(i,lastX+1){
            int stat=0;
            for(int j = m-1; j >= 0; j--){
                stat <<= 1;
                stat += map[j][i];
            }
            stainStat[i]=stat;
        }
        int ans=INF;
        FOR(i,lastX+1){
            FOR(j,29){
                int jStat = cover[j];
                FOR(k,29){
                    int kStat = cover[k];
                    FOR(l,29){
                        int covered = stainStat[i];
                        int lStat = cover[l];
                        if(i>=2) covered &= ~jStat;
                        if(i>=1) covered &= ~kStat;
                        covered &= ~lStat;
                        if(covered) continue;
                        dp[i][k][l] = min(dp[i][k][l],(i==0?0:dp[i-1][j][k])+cntCover[l]);
                        if(i==lastX) ans=min(ans,dp[i][k][l]);
                    }
                }
            }
        }
        printf("Case #%d\n%d\n",t+1,ans);
    }
    return 0;
}