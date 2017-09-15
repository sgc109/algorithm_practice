#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+9;

class RequiredSubstrings {
public:
    int solve(vector<string>, int, int);
};

int cnt;
struct Node {
    int id;
    Node *next[26];
    Node *fail;
    vector<int> end;
    Node() {
        id = cnt++;
        memset(next, 0, sizeof(next));
        fail = 0;
    }
};
typedef Node *pNode;
pNode start;
long long dp[53][303][1<<6];
int C, L;
void push(pNode cur, string s, int pos, int id) {
    if (pos == s.size()) {
        cur->end.push_back(id);
        return;
    }
    auto& next = cur->next[s[pos] - 'a'];
    if (!next) {
        next = new Node;
    }
    push(next, s, pos + 1, id);
}

long long go(int pos, pNode cur, int include){
    for(auto e : cur->end) include |= (1<<e);
    if(pos == L) {
        int c = 0;
        for(;include;include>>=1) {
            if(include&1) c++;
        }
        return c == C;
    }
    long long& cache = dp[pos][cur->id][include];
    if(cache != -1) return cache;
    cache = 0;
    for(int i = 0 ; i < 26; i++){
        pNode now = cur;
        if (now->next[i]) now = now->next[i];
        else{
            while (now != start) {
                if (now->fail->next[i]) {
                    now = now->fail->next[i];
                    break;
                }
                now = now->fail;
            }
        }
        cache = (cache + go(pos+1, now, include)) % MOD;
    }
    return cache;
}

void initFailFunc(){
    queue<pNode> q;
    q.push(start);
    start->fail = start;
    while (!q.empty()) {
        pNode par = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            pNode& child = par->next[i];
            if (!child) continue;
            if (par == start) child->fail = par;
            else {
                pNode cur = par;
                while (cur != start) {
                    if (cur->fail->next[i]) {
                        child->fail = cur->fail->next[i];
                        break;
                    }
                    cur = cur->fail;
                }
                if (child->fail == 0) child->fail = start;
            }
            child->end.insert(child->end.end(), child->fail->end.begin(), child->fail->end.end());
            q.push(child);
        }
    }
}
int RequiredSubstrings::solve(vector<string> words, int c, int l) {
    memset(dp, -1, sizeof(dp));
    C = c, L = l;
    cnt = 0;
    start = new Node;
    for(int i = 0 ; i < words.size(); i++) push(start, words[i], 0, i);

    initFailFunc();
    return go(0, start, 0);
}

// CUT begin
ifstream data("RequiredSubstrings.sample");

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

bool do_test(vector<string> words, int C, int L, int __expected) {
    time_t startClock = clock();
    RequiredSubstrings *instance = new RequiredSubstrings();
    int __result = instance->solve(words, C, L);
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
        vector<string> words;
        from_stream(words);
        int C;
        from_stream(C);
        int L;
        from_stream(L);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
        continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(words, C, L, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1493803798;
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
        cout << "RequiredSubstrings (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
