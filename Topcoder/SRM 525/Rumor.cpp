#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class Rumor {
public:
    int N;
    int got[17][2];
    int gave[17][2];
    int tgot[17][2];
    int tgave[17][2];
    int getMinimum(string knowledge, vector<string> graph) {
        N = (int)knowledge.size();
        int ans = inf;
        for(int mask = 0 ; mask < (1<<N); mask++){
            memset(got,0,sizeof(got));
            memset(gave,0,sizeof(gave));
            for(int i = 0 ; i < N; i++) if(knowledge[i] == 'Y') got[i][0] = got[i][1] = 1; 
            int i;
            for(i = 0 ; i < N+2; i++){
                int ok = 1;
                for(int j = 0 ; j < N; j++) if(!got[j][0] || !got[j][1]) ok = 0;
                if(ok) break;
                for(int j = 0 ; j < N; j++){
                    for(int k = 0 ; k < 2; k++){
                        tgave[j][k] = gave[j][k];
                        tgot[j][k] = got[j][k];
                    }
                }

                for(int j = 0 ; j < N; j++){
                    int o = (mask & (1<<j)) != 0;
                    int cur = 0;
                    if(gave[j][o]) cur = !o;
                    else cur = o;
                    if(!got[j][cur] || gave[j][cur]) continue;
                    for(int k = 0 ; k < N; k++){
                        if(graph[j][k] == 'N') continue;
                        tgot[k][cur] = 1;
                    }
                    tgave[j][cur] = 1;
                }

                for(int j = 0 ; j < N; j++){
                    for(int k = 0 ; k < 2; k++){
                        gave[j][k] = tgave[j][k];
                        got[j][k] = tgot[j][k];
                    }
                }
            }
            int ok = 1;
            for(int j = 0 ; j < N; j++) if(!got[j][0] || !got[j][1]) ok = 0;
            if(!ok) continue;
            ans = min(ans, i);
        }
        if(ans == inf) ans = -1;
        return ans;
    }
};

// CUT begin
ifstream data("Rumor.sample");

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

bool do_test(string knowledge, vector<string> graph, int __expected) {
    time_t startClock = clock();
    Rumor *instance = new Rumor();
    int __result = instance->getMinimum(knowledge, graph);
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
        string knowledge;
        from_stream(knowledge);
        vector<string> graph;
        from_stream(graph);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(knowledge, graph, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1499161584;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 525 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "Rumor (525 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
