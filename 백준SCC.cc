#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<int> a[10001];
bool c[10001];
int low[10001];
int num[10001];
int cnt = 0;
stack<int> s;
vector<vector<int>> ans;
void dfs(int x) {
    c[x] = true;
    s.push(x);
    num[x] = ++cnt;
    low[x] = cnt;
    for (int i=0; i<a[x].size(); i++) {
        int y = a[x][i];
        if (num[y] == 0) {
            dfs(y);
            low[x] = min(low[x], low[y]);
        } else if (c[y] == true) {
            low[x] = min(low[x], num[y]);
        }
    }
    if (low[x] == num[x]) {
        vector<int> scc;
        while (!s.empty()) {
            int y = s.top();
            scc.push_back(y);
            c[y] = false;
            s.pop();
            if (x == y) {
                break;
            }
        }
        sort(scc.begin(),scc.end());
        ans.push_back(scc);
    }
}