#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int MAXN = 1 << 5;
char S[MAXN];
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN]={0,};
bool sufCmp(int i, int j)
{
    return pos[i]!=pos[j] ? pos[i]<pos[j] : pos[i+gap] < pos[j+gap];
}
void buildSA()
{
    N = strlen(S);
    pos[N]=-1;
    for(int i=0;i<N;i++) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2)
    {
        sort(sa, sa + N, sufCmp);
        for(int i=0;i<N-1;i++) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        for(int i=0;i<N;i++) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}
void buildLCP()
{
    for (int i = 0, k = 0; i < N; ++i){
        if (pos[i] != N - 1)
        {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
                ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
    }
}
void print(){
    for(int i=0;i<N;i++){
        for(int j=sa[i];j<N;j++){
            printf("%c",S[j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%s",S);
    buildSA();
    print();
    buildLCP();
    return 0;
}