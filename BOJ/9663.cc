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

int n;
int col[14],row[14],da1[27],da2[27];
ll solve(int curI){
    if(curI==n) return 1;
    ll ret=0;
    FOR(curJ,n){
        int leftupI = curI - min(curI,curJ), leftupJ = curJ - min(curI,curJ);
        int rightupI = curI - min(curI,n-curJ-1), rightupJ = curJ + min(curI,n-curJ-1);
        int rowNum = curI;
        int colNum = curJ;
        int da1Num = (leftupJ==0?n-leftupI-1:n-1+leftupJ);
        int da2Num = (rightupI==0?rightupJ:n-1+rightupI);
        if(!col[colNum]&&!row[rowNum]&&!da1[da1Num]&&!da2[da2Num]) {
            col[colNum] = 1;
            row[rowNum] = 1;
            da1[da1Num] = 1;
            da2[da2Num] = 1;
            ret+=solve(curI+1);
            col[colNum] = 0;
            row[rowNum] = 0;
            da1[da1Num] = 0;
            da2[da2Num] = 0;
        }
    }
    return ret;
}
int main() {
    inp1(n);
    cout << solve(0);
	return 0;
}
