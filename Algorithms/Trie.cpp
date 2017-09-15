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
#define INF 0x3a3a3a3a

using namespace std;

struct TrieNode {
    TrieNode *child[10];
    int terminal;
    int first;
    TrieNode(int id) : first(id) {
        terminal = 0;
        FOR(i,10){
            child[i] = 0;
        }
    }
    TrieNode(){
        terminal = 0;
        FOR(i,10){
            child[i] = 0;
        }
    }
    
    ~TrieNode() {
        FOR(i,10)
            delete child[i];
    }
    
    int toInt(char c) {
        return c - '0';
    }
    
    bool insert(char *ch, int id) {
        if(terminal) return false;
        
        if(*ch == NULL) {
            terminal = 1;
            if(first != id) return false;
            return true;
        }
        int next = toInt(*ch);
        if(!child[next]) {
            child[next] = new TrieNode(id);
        }
        return child[next]->insert(ch+1, id);
    }
};

int main() {
    int T;
    scanf("%d",&T);
    FOR(t,T){
        int n;
        scanf("%d",&n);
        TrieNode trie;
        bool consis = true;
        FOR(i,n) {
            char s[12];
            scanf("%s",s);
            if(!trie.insert(s,i)) {
                consis = false;
            }
        }
        if(!consis) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    
    return 0;
}