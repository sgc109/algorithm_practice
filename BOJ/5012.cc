// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
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

ll ret;
int A[100001],t1[100001],t2[100001],N;
void update(int *t, int p, int v){
    for(;p<=N;p+=-p&p) t[p]+=v;
}
ll query(int *t, int p){
    for(ret=0;p>0;p-=p&-p) ret+=t[p];
    return ret;
}
int main() {
    inp1(N);
    FOR(i,N) {
        inp1(A[i]);
        update(t2,A[i],1);
    }
    ll ans=0;
    for(int i=0;i<N;update(t1,A[i],1),update(t2,A[i],-1),i++) ans+=(query(t1,N)-query(t1,A[i]))*query(t2,A[i]-1);
    printf("%lld",ans);
    return 0;
}
