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

class AdjacentSwaps {
public:
    ll nCr[53][53];
    ll dp[53][53];
    int N;
    vi P;
    ll go(int s, int e) {
        if (s == e) return 1;
        ll& cache = dp[s][e];
        if (cache != -1) return cache;
        cache = 0;

        vi se;
        REP(i, s, e) se.pb(P[i]);
        sort(all(se));

        REP(k, s, e - 1) {
            vi sorted;
            sorted.assign(P.begin() + s, P.begin()+ s + k - s + 1);
            sort(all(sorted));
            vi seSorted = se;
            swap(seSorted[k-s], seSorted[k-s + 1]);
            
            vi leftSorted;
            leftSorted.assign(seSorted.begin(), seSorted.begin() + k - s + 1);
            
            if (sorted != leftSorted) continue;

            cache = (cache + go(s, k) * go(k + 1, e) % MOD * nCr[e - s - 1][k - s]) % MOD;
        }

        return cache;
    }
    int theCount(vector<int> p) {
        N = sz(p);
        memset(dp, -1, sizeof(dp));
        memset(nCr, 0, sizeof(nCr));
        P = p;
        FOR(i, 53) nCr[i][0] = 1;
        REP(i, 1, 52) REP(j, 1, 52) nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;

        int ret = (int)go(0, N - 1);
        return ret;
    }
};

// CUT begin
ifstream data("AdjacentSwaps.sample");

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

bool do_test(vector<int> p, int __expected) {
    time_t startClock = clock();
    AdjacentSwaps *instance = new AdjacentSwaps();
    int __result = instance->theCount(p);
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
        vector<int> p;
        from_stream(p);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(p, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1493268644;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "AdjacentSwaps (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
