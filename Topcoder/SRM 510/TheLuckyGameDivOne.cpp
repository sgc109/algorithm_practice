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
    string S,E;
    int dp[12][2][2];
    long long len1, len2;
    string upLimit, downLimit;
    int cntLuckyNum(int pos, int upOk, int downOk){

    }
    vii findMaxRngs(long long s, long long e, long long len){
        vii ret;
        for(long long i = 4; i <= 444444444 && i <= e; i=i*10+4){
            long long l = i, r = i + len - 1;
            if(l <= s) l += (s-l), r += (s-l);
            if(e <= r) l -= (r-e), r -= (r-e);
            ret.pb(findMinRng(l,r));
        }
        for(long long i = 7; i <= 777777777 && i <= e; i=i*10+7){
            long long l = i - len + 1, r = i;
            if(l <= s) l += (s-l), r += (s-l);
            if(e <= r) l -= (r-e), r -= (r-e);
            ret.pb(findMinRng(l,r));
        }
        return ret;
    }
    void findMinRng(long long s, long long e, long long len){
        ostringstream os;
        
    }
    int find(long long a, long long b, long long jLen, long long bLen) {
        len1 = jLen, len2 = bLen;
        vi range1 = findMaxRng(a,b);
        FOR(i,sz(range1)){
            pii p = range1[i];
            findMinRng(p.first, p.second);
        }
        return 0;
    }
};

// CUT begin
ifstream data("TheLuckyGameDivOne.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(long long a, long long b, long long jLen, long long bLen, int __expected) {
    time_t startClock = clock();
    TheLuckyGameDivOne *instance = new TheLuckyGameDivOne();
    int __result = instance->find(a, b, jLen, bLen);
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
        long long a;
        from_stream(a);
        long long b;
        from_stream(b);
        long long jLen;
        from_stream(jLen);
        long long bLen;
        from_stream(bLen);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, b, jLen, bLen, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1489321477;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TheLuckyGameDivOne (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
