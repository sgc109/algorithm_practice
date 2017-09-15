#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class NewItemShop {
public:
    int S,N;
    int dp[25][25];
    pair<int,int> cust[25]; // 이 시간에 오는 손님 번호랑 가격
    vector<pair<int,int> > cases[25]; // i 번 손님이 올 수 있는 (시간,확률) 케이스들
    int timeCome[25]; // i 번 손님이 오는 시간
    int rest[25];
    double ans;
    int go(int t, int swords){
        if(t==24) return 0;
        int& cache = dp[t][swords];
        if(cache != -1) return cache;
        if(cust[t].first == -1 || timeCome[cust[t].first] == -1) return cache = go(t+1, swords);

        cache = 0;
        if(timeCome[cust[t].first] == t){
            cache = max(cache, go(t+1, swords));
            if(swords>0) cache = max(cache, cust[t].second + go(t+1, swords-1));
        }
        return cache;
    }
    void go2(int man, double prob){
        for(int i = 0 ; i < cases[man].size(); i++){
            timeCome[man] = cases[man][i].first;
            if(man < N-1) go2(man+1, prob*cases[man][i].second/100);
            else {
                memset(dp,-1,sizeof(dp));
                ans = max(ans, prob*go(0,S));
            }
        }
    }
    double getMaximum(int swords, vector<string> customers) {
        for(int i = 0 ; i < 24; i++) cust[i] = {-1,-1}; 
        S = swords;
        N = customers.size();
        for(int i = 0 ; i < N ; i++){
            stringstream ss1(customers[i]);
            int acc = 0;
            for(string s1;getline(ss1,s1,' ');){
                stringstream ss2(s1);
                vector<int> in;
                for(string s2; getline(ss2,s2,',');) in.push_back(stoi(s2));
                int t = in[0];
                int c = in[1];
                int p = in[2];
                acc += p;
                // printf("t:%d, c:%d, p:%d\n",t,c,p);
                cust[t] = {i,c};
                cases[i].push_back({t,p});
            }
            cases[i].push_back({-1,100-acc});
        }
        ans = 0.0;
        go2(0,1);

        return ans;
    }
};

// CUT begin
ifstream data("NewItemShop.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int swords, vector<string> customers, double __expected) {
    time_t startClock = clock();
    NewItemShop *instance = new NewItemShop();
    double __result = instance->getMaximum(swords, customers);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        int swords;
        from_stream(swords);
        vector<string> customers;
        from_stream(customers);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(swords, customers, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1494514198;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "NewItemShop (550 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
