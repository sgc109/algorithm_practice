#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
 
#pragma warning(disable:4996)
using namespace std;
 
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;
 
int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;
 
int in[100050][2];
int r[100050];
int N, R, D;
int root(int x) {
    return (x == r[x]) ? x : (r[x] = root(r[x]));
}
void merge(int a, int b) {
    if (root(a) != root(b)) r[root(a)] = root(b);
}
set <pii> Sx;
vector <pair<pii, pii>> V;
void spush(pii u) {
    auto it = Sx.lower_bound(u);
    if (it != Sx.end() && it->first - u.first <= R + D) merge(it->second, u.second);
 
    if (it != Sx.begin()) {
        it--;
        if (u.first - it->first <= R + D) merge(it->second, u.second);
    }
    Sx.insert(u);
}
 
int main() {
//  freopen("input.txt", "r", stdin);
    int i;
    scanf("%d %d", &N, &R);
    for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);
    scanf("%d", &D);
 
    for (i = 1; i <= N; i++) r[i] = i;
    for (i = 1; i <= N; i++) {
        V.push_back(mp(pii(in[i][0], 0), pii(in[i][1], i)));
        V.push_back(mp(pii(in[i][0] + R, 1), pii(in[i][1], i)));
    }
    sort(V.begin(), V.end());
    for (auto it : V) {
        if (it.first.second == 0) spush(it.second);
        else Sx.erase(it.second);
    }
 
    V.clear();
    for (i = 1; i <= N; i++) {
        V.push_back(mp(pii(in[i][1], 0), pii(in[i][0], i)));
        V.push_back(mp(pii(in[i][1] + R, 1), pii(in[i][0], i)));
    }
    sort(V.begin(), V.end());
    for (auto it : V) {
        if (it.first.second == 0) spush(it.second);
        else Sx.erase(it.second);
    }
 
    int p = 0;
    for (i = 1; i <= N; i++) if (in[i][0] == 0 && in[i][1] == 0) p = i;
    assert(p);
 
    int ans = 0;
    for (i = 1; i <= N; i++) if (root(i) == root(p)) ans = max(ans, in[i][0] + in[i][1] + 2 * R);
    printf("%d\n", ans);
    return 0;
}
