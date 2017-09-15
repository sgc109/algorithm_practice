#include <bits/stdc++.h>
using namespace std;

int T, N;
int vis[13];
int used[13];
int adj[13][13];
int tadj[13][13];

bool move(int from, int to){
    if(abs(from - to) == 6){
        int mid = min(from, to) + 3;
        if(vis[mid] == 0) return false;
        tadj[from][mid] = tadj[mid][from] = tadj[mid][to] = tadj[to][mid] = 1;
    }
    else if(abs(from - to) == 2 && ((from % 3 == 1 && to % 3 == 0) || (from % 3 == 0 && to % 3 == 1))){
        int mid = min(from, to) + 1;
        if(vis[mid] == 0) return false;
        tadj[from][mid] = tadj[mid][from] = tadj[mid][to] = tadj[to][mid] = 1;
    }
    else if(from + to == 10){
        int mid = min(from, to) + (max(from, to) - min(from, to)) / 2;
        if(vis[mid] == 0) return false;
        tadj[from][mid] = tadj[mid][from] = tadj[mid][to] = tadj[to][mid] = 1;
    }
    else {
        tadj[from][to] = tadj[to][from] = 1;
    }
    return true;
}

void in(int from, int to){
    if(abs(from - to) == 6){
        int mid = min(from, to) + 3;
        adj[from][mid] = adj[mid][from] = adj[mid][to] = adj[to][mid] = 1;
        used[mid] = 1;
    }
    else if(abs(from - to) == 2 && ((from % 3 == 1 && to % 3 == 0) || (from % 3 == 0 && to % 3 == 1))){
        int mid = min(from, to) + 1;
        adj[from][mid] = adj[mid][from] = adj[mid][to] = adj[to][mid] = 1;
        used[mid] = 1;
    }
    else if(from + to == 10){
        int mid = min(from, to) + (max(from, to) - min(from, to)) / 2;
        adj[from][mid] = adj[mid][from] = adj[mid][to] = adj[to][mid] = 1;
        used[mid] = 1;
    }
    else {
        adj[from][to] = adj[to][from] = 1;
    }
    used[from] = used[to] = 1;
}
int main(){
    cin >> T;
    while(T--){
        memset(used,0,sizeof(used));
        memset(adj,0,sizeof(adj));
        cin >> N;
        for(int i = 0 ; i < N; i++){
            int a, b;
            cin >> a >> b;
            in(a, b);
        }
        vector<int> v;
        for(int i = 1; i <= 9; i++) if(used[i]) v.push_back(i);
        int ok = 0;
        do{
            int poss = 1;
            memset(vis,0,sizeof(vis));
            memset(tadj,0,sizeof(tadj));
            for(int i = 0; i < (int)v.size() - 1; i++){
                int from = v[i];
                int to = v[i + 1];
                vis[from] = 1;
                bool ret = move(from, to);
                if(!ret) {
                    poss = 0;
                    break;
                }
            }
            for(int i = 1; i <= 9; i++){
                for(int j = i + 1; j <= 9; j++){
                    if(adj[i][j] != tadj[i][j]) {
                        poss = 0;
                    }
                }
            }
            if(poss){
                ok = 1;
                for(int i = 0 ; i < (int)v.size(); i++){
                    cout << v[i] << ' ';
                }
                cout << '\n';
                break;
            }
        }while(next_permutation(v.begin(), v.end()));
        if(!ok) cout << "IMPOSSIBLE\n";
    }
    return 0;
}
