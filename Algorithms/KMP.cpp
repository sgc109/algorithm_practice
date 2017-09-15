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

vector<int> pi;
vector<int> ans;

vector<int> calcPrefixTable(char P[]) {
    int len = strlen(P);
    vector<int> ret = vector<int>(len,0);
    
    int begin = 1, match = 0;
    while(begin < len) {
        if(P[begin + match] == P[match]) {
            ++match;
            ret[begin + match - 1] = match;
        }
        else {
            if(match == 0) {
                ++begin;
            }
            else {
                begin += (match - ret[match - 1]);
                match = ret[match -1];                
            }
        }
    }
    
    return ret;
}

vector<int> KMP(char S[], char P[]) {
    vector<int> ret;
    
    pi = calcPrefixTable(P);
    int lenS = strlen(S);
    int lenP = strlen(P);
    
    int pos = 0, i = 0;
    while()
    
    return ret;
}

int main() {
    char S[1000002];
    char P[1000002];
    
    scanf("%s %s",S,P);
    ans = KMP(S,P);
    
    return 0;
}