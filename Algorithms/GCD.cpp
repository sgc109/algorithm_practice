#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<queue>

#define REP(i,a,b) for(int i=a;i<b;++i)
#define FOR(i,n) REP(i,0,n)

using namespace std;

int gcd(int a, int b) {
    while(a&&b) (a>b) ? a%=b : b%=a;
    return a+b;
}

int main() {
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b); 
    
    return 0;
}