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

class TreeMovingDiv2 {
public:
    ll X[53];
    int G[53][53][53];
    int parent[53][53];
    ll dp[53][53][53];
    int dp2[53][53][53];
    int N,M;
    int visited[53];
    int dfs(int here, int dad, int pos){
        visited[here] = 1;
        FOR(there, N){
            if(!G[pos][here][there] || there == dad) continue;
            if(visited[there]) return 0;
            if(!dfs(there, here, pos)) return 0;
        }
        return 1;
    }
    void dfs2(int here, int dad, int pos){
        for(int there = 0 ; there < N; there++){
            if(!G[pos][here][there] || there==dad) continue;
            parent[pos][there] = here;
            dfs2(there, here, pos);
        }
    }
    int check(int pos, int prevU, int newU){
        int& cache = dp2[pos][prevU][newU];
        if(cache != -1) return cache;
        int prevV = parent[pos][prevU];
        int newV = parent[(pos+M-1)%M][newU];
        G[pos][prevU][prevV] = G[pos][prevV][prevU] = 0;
        int backup = G[pos][newV][newU];
        G[pos][newV][newU] = G[pos][newU][newV] = 1;
        memset(visited,0,sizeof(visited));
        int ret = dfs(0,-1, pos);
        G[pos][newV][newU] = G[pos][newU][newV] = backup;
        G[pos][prevU][prevV] = G[pos][prevV][prevU] = 1;
        FOR(i,N) if(visited[i]==0) ret = false;
        return cache = ret;
    }
    ll go(int pos, int u, int u0){
        ll& cache = dp[pos][u][u0];
        if(cache != -1) return cache;

        ll ret = 0;
        if(pos==M){
            if(check(0, u0, u)) return 1;
            return 0;
        }
        for(int i = 0; i < N; i++){
            int p = parent[pos][i];
            if(p == -1) continue;
            if(pos>0 && !check(pos, i, u)) continue;
            (ret += go(pos+1, i, pos?u0:i)) %= MOD;
        }
        return cache = ret;
    }
    void initGraph(vector<int>& roots, vector<int>& a, vector<int>& b, vector<int>& c){
        FOR(i,M) {
            X[0] = c[i];
            REP(k,1,N-2) X[k] = (a[i] * X[k - 1] + b[i]) % MOD;
            REP(j,0,N-2){
                int u = (roots[i] + j + 1) % N;
                int v = (roots[i] + (X[j] % (j+1))) % N;
                G[i][u][v] = G[i][v][u] = 1;
            }
        }
    }
    int count(int n, vector<int> roots, vector<int> a, vector<int> b, vector<int> c) {
        memset(G,0,sizeof(G));
        memset(X,0,sizeof(X));
        memset(parent,-1,sizeof(parent));
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        N = n;
        M = roots.size();
        initGraph(roots, a,b,c);
        for(int i = 0 ; i < M; i++) 
            dfs2(0,-1,i);

        return go(0,0,0);
    }
};

// CUT begin
ifstream data("TreeMovingDiv2.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, vector<int> roots, vector<int> a, vector<int> b, vector<int> c, int __expected) {
    time_t startClock = clock();
    TreeMovingDiv2 *instance = new TreeMovingDiv2();
    int __result = instance->count(n, roots, a, b, c);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int n;
        from_stream(n);
        vector<int> roots;
        from_stream(roots);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        vector<int> c;
        from_stream(c);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, roots, a, b, c, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1490836629;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TreeMovingDiv2 (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
