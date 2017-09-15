#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,pair<int,int> > piii;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class NewItemShop {
public:
    int S,N;
    double dp[25][25][1<<12];
    piii comingMan[25]; // i 시간에 오는 사람의 (돈,확률) 정보
    int multiComingCnt;
    int multiIdx[25]; // i 번 사람의 bitmask 자릿수
    int accProb[25];
    vector<pair<int,int> > sorted[25];
    double go(int t, int sword, int came){
        if(t == 24 || !sword) return 0.0;
        double& cache = dp[t][sword][came];
        if(cache != -1.0) return cache;
        cache = 0;
        int man = comingMan[t].first;
        int cost = comingMan[t].second.first;
        int p = comingMan[t].second.second;
        if(man == -1) cache = go(t+1, sword, came);
        else {
            int pos = multiIdx[man];
            if(pos == -1 || !(came&(1<<pos))){
                double tot = 100.0 - accProb[t];
                int nextcame = came;
                if(pos != -1) nextcame|=(1<<pos);
                cache = max(cache, (tot-p)/tot*go(t+1,sword,came));
                cache += p/tot*max(go(t+1,sword,nextcame), go(t+1,sword-1,nextcame)+cost);
            }
            else cache = go(t+1,sword,came);
        }
        return cache;
    }
    double getMaximum(int swords, vector<string> customers) {
        memset(multiIdx,-1,sizeof(multiIdx));
        for(int i = 0 ; i < 25; i++) comingMan[i] = {-1,{-1,-1}};
        for(int i = 0 ; i < 25; i++) for(int j = 0 ; j < 25; j++) for(int k = 0 ; k < (1<<12); k++) dp[i][j][k] = -1.0;
        S = swords;
        N = customers.size();
        for(int i = 0 ; i < N; i++){
            stringstream ss1(customers[i]);
            int j=0;
            int acc = 0;
            for(string str1; getline(ss1,str1,' ');j++){
                stringstream ss2(str1);
                vector<int> in;
                for(string str2; getline(ss2,str2,',');) in.push_back(stoi(str2));
                int t = in[0];
                int c = in[1];
                int p = in[2];
                comingMan[t] = {i,{c,p}};
                accProb[t] = acc;
                acc += p;
            }
            if(j>1) multiIdx[i] = multiComingCnt++;
        }
        return go(0,swords,0);
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
