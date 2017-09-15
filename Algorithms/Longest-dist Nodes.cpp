#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)
#define LONG long long
#define INF 987654321

using namespace std;

struct Node{
    int num;
  vector<Node *> childs;    
    int r;
    bool operator>(const Node *node) {
        return r > node->r;
    }
    bool operator==(const Node *node) {
        return r == node->r;
    }
    bool operator<(const Node *node) {
        return r < node->r;
    }
};

int n;
int x[100], y[100], r[100];
int longest = 0;
vector<Node *> castles;

int sqr(int x) {
    return x*x;
}

int sqrdist(int a, int b) {
    return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

bool enclose(int a, int b) {
    return r[a] > r[b] && sqrdist(a, b) < sqr(r[a] - r[b]);
}

bool isChild(int parent, int child) {
    if(!enclose(parent, child)) return false;
    
    FOR(i,n) {
        if(i != parent && i != child && enclose(parent, i) && enclose(i, child)) 
            return false;
    }
    
    return true;
}

Node *makeTreeSlow(int root){
    Node *ret = new Node();
    FOR(i,n) {
        if(isChild(root,i)) ret->childs.push_back(makeTreeSlow(i)) ;
    }
    
    return ret;
}

Node *makeTreeFast() {
    castles.clear();
    FOR(i,n) {
        Node *castle = new Node();
        castle->r = r[i];
        castle->num = i;
        castles.push_back(castle);
    }
    sort(castles.begin(), castles.end());
    FOR(i,n) {
        REP(j,i+1,n) {
            if(enclose(castles[j]->num, castles[i]->num)) {
                castles[j]->childs.push_back(castles[i]);
                break;
            }
        }
    }
    return castles.back();
}

int height(Node *root) { //트리의 높이를 구하는 함수 코드에서 잎-잎의 최대거리를 갱신하는 코드만 추가한것임
    vector<int> heights;
    FOR(i, root->childs.size()) {
        heights.push_back(height(root->childs[i]));
    }
    
    if(heights.size() == 0) return 0;
    
    sort(heights.begin(), heights.end());
    
    if(heights.size() >= 2) {
        longest = max(longest, heights[heights.size()-1] + heights[heights.size()-2] + 2);
    }
    
    return heights.back() + 1;
}

int solve(Node *root) {
    longest = 0;
    int h = height(root);
    return max(longest, h);
}

int main() {
    int T;
    scanf("%d",&T);
    FOR(t,T){
        scanf("%d",&n);
        FOR(i,n) {
            scanf("%d%d%d",&x[i],&y[i],&r[i]);
        }
        Node *root = makeTreeFast();
        printf("%d\n",solve(root));        
    }
    
    return 0;
}