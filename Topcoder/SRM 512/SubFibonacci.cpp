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

class SubFibonacci {
public:
    int N;
    ll fibo[100];
    int arr[53];
    unordered_set<int> us;
    int solve(int s, int e){
        if(e - s + 1 <= 2) return e - s + 1;
        int ret = 0;
        for(int i = s; i < e; i++){
            int A = arr[i];
            for(int j = i + 1; j <= e; j++){
                int C = arr[j];
                for(int D = 0; fibo[D+1] <= 1e9; D++){
                    int cnt = 2;
                    ll upper = C - fibo[D] * A;
                    ll lower = fibo[D+1];
                    if(upper < 0 || upper%lower) continue;
                    int B = upper/lower;
                    if(A >= B) continue;
                    int cur = B;
                    int prv = A;
                    while(cur < C){
                        // printf("A:%d, B:%d, ~~ D:%d ~~ C:%d\n",A,B,D,C);
                        if(us.count(cur)) cnt++;
                        int tmp = cur;
                        cur = cur + prv;
                        prv = tmp;
                    }
                    ret = max(ret, cnt);
                }
            }
        }
        return ret;
    }
    void initFibo(){
        fibo[0] = fibo[1] = 1;
        for(int i = 2; fibo[i-1] <= 1e9; i++) fibo[i] = fibo[i-2] + fibo[i-1];
    }
    int maxElements(vector<int> S) {
        sort(all(S));
        N = S.size();
        FOR(i,N) arr[i] = S[i], us.insert(S[i]);;
        initFibo();
        int ans = 0;
        for(int i = 0; i < N; i++){
            // if(ans < solve(0,i) + solve(i+1, N-1)) printf("i:%d, updated:%d\n",i,solve(0,i) + solve(i+1, N-1));
            ans = max(ans, solve(0, i) + solve(i+1, N-1));
        }
        return ans;
    }
};

// CUT begin
ifstream data("SubFibonacci.sample");

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

bool do_test(vector<int> S, int __expected) {
    time_t startClock = clock();
    SubFibonacci *instance = new SubFibonacci();
    int __result = instance->maxElements(S);
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
        vector<int> S;
        from_stream(S);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1490530430;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 512 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SubFibonacci (512 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
