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

class SPartition {
public:
    map<pair<string, string>, long long > mp1, mp2;
    long long getCount(string s) {
        long long ans = 0;
        int N = s.size();
        string L = s.substr(0, N/2);
        string R = s.substr(N/2, N/2);
        
        for(int i = 0 ; i < (1<<(N/2)); i++){
            string l, r;
            for(int j = 0 ; j < N/2; j++){
                if(i & (1<<j)) l += L[j];
                else r += L[j];
            }
            if(l.size() == r.size()) {
                if(l != r) continue;
                mp1[make_pair("","")]++;
            }
            else if(l.size() < r.size()){
                if(l != r.substr(0, l.size())) continue;
                mp1[make_pair("", r.substr(l.size(), r.size() - l.size()))]++;
            }
            else{
                if(l.substr(0, r.size()) != r) continue;
                mp1[make_pair(l.substr(r.size(), l.size() - r.size()), "")]++;
            }
        }

        for(int i = 0 ; i < (1<<N/2); i++){
            string l, r;
            for(int j = 0 ; j < N/2; j++){
                if(i & (1<<j)) l += R[j];
                else r += R[j];
            }
            if(l.size() == r.size()) {
                if(l != r) continue;
                mp2[make_pair("","")]++;
            }
            else if(l.size() < r.size()){
                if(l != r.substr(r.size()-l.size(), l.size())) continue;
                mp2[make_pair("", r.substr(0, r.size() - l.size()))]++;
            }
            else{
                if(l.substr(l.size()-r.size(), r.size()) != r) continue;
                mp2[make_pair(l.substr(0, l.size() - r.size()), "")]++;
            }       
        }

        for(auto it = mp1.begin(); it != mp1.end(); it++){
            auto p = (*it).first;
            long long cnt1 = (*it).second;
            if(cnt1 == 0) continue;
            p = {p.second, p.first};
            long long cnt2 = mp2[p];
            ans += cnt1 * cnt2;
        }
        return ans;
    }
};

// CUT begin
ifstream data("SPartition.sample");

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

bool do_test(string s, long long __expected) {
    time_t startClock = clock();
    SPartition *instance = new SPartition();
    long long __result = instance->getCount(s);
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
        string s;
        from_stream(s);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1493740655;
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
        cout << "SPartition (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
