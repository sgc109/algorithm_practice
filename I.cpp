#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int N, M;
ll q, p;
string S[253];
ll sum[253][253];
int vis[253][253];
bool inRange(int i, int j){
    return 0 <= i && i < N && 0 <= j && j < M;
}
int main(){
    cin >> N >> M >> q >> p;
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(S[i][j] == '.' || S[i][j] == '*') continue;
            ll cst = (S[i][j] - 'A' + 1) * q;
            queue<pair<pair<int,int>,ll> > q;
            q.push({{i, j}, cst});
            vector<pair<int,int> > back;
            vis[i][j] = 1;
            while(!q.empty()){
                auto p = q.front();
                int ci = p.first.first;
                int cj = p.first.second;
                back.pb({ci, cj});
                ll cst = p.second;
                q.pop();
                sum[ci][cj] += cst;
                if(cst / 2 == 0) continue;
                for(int k = 0; k < 4; k++){
                    int ni = ci + "2110"[k] - '1';
                    int nj = cj + "1201"[k] - '1';
                    if(!inRange(ni, nj) || S[ni][nj] == '*' || vis[ni][nj]) continue;
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, cst / 2});
                }
            }
            for(auto p : back) vis[p.first][p.second] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(sum[i][j] > p) ans++;
        }
    }
    cout << ans;
}
