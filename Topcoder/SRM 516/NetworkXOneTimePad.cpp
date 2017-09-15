#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <map>

using namespace std;

class NetworkXOneTimePad {
    int N;
    int len;
    vector<string> ciphers, plains;
    map<string, int> um;
public:
    int go(string key){
        int pos = key.size();
        if(pos == len) {
            return 1;
        }
        int ret = 0;
        bool imposs = false;
        for(int i = 0 ; i < N; i++){
            string tmpS = "";
            for(int j = 0 ; j < key.size(); j++){
                if(ciphers[i][j] == key[j]) tmpS += "0";
                else tmpS += "1";
            }
            if(um[tmpS + (ciphers[i][pos] == '0' ? "0" : "1")] == 0) {
                imposs = true;
                break;
            }
        }
        if(!imposs) ret += go(key + "0");
        
        imposs = false;
        for(int i = 0 ; i < N; i++){
            string tmpS = "";
            for(int j = 0 ; j < key.size(); j++){
                if(ciphers[i][j] == key[j]) tmpS += "0";
                else tmpS += "1";
            }
            if(um[tmpS + (ciphers[i][pos] == '1' ? "0" : "1")] == 0) {
                imposs = true;
                break;
            }
        }
        if(!imposs) ret += go(key + "1");
        
        return ret;
    }
    int crack(vector<string> plaintexts, vector<string> ciphertexts) {
        ciphers = ciphertexts;
        plains = plaintexts;
        N = ciphertexts.size();
        len = ciphertexts[0].size();
        for(int i = 0 ; i < plaintexts.size(); i++){
            string tmpS = "";
            for(int j = 0 ; j < len; j++){
                tmpS += plaintexts[i][j];
                um[tmpS] = 1;
            }
        }
        return go("");
    }
};

// CUT begin
ifstream data("NetworkXOneTimePad.sample");

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

bool do_test(vector<string> plaintexts, vector<string> ciphertexts, int __expected) {
    time_t startClock = clock();
    NetworkXOneTimePad *instance = new NetworkXOneTimePad();
    int __result = instance->crack(plaintexts, ciphertexts);
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
        vector<string> plaintexts;
        from_stream(plaintexts);
        vector<string> ciphertexts;
        from_stream(ciphertexts);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(plaintexts, ciphertexts, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1492227386;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "NetworkXOneTimePad (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
