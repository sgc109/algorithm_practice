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

string add(string a, string b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string ret;
    
    int pos = 0;
    int carry=0;
    while(pos < a.size() || pos < b.size()) {
        int sum = carry;
        if(pos < a.size()) sum += a[pos] - '0';
        if(pos < b.size()) sum += b[pos] - '0';
        carry = sum/10;
        sum %= 10;
        ret += sum+'0';
        ++pos;
    }
    if(carry) ret += "1";
    
    reverse(ret.begin(), ret.end());
    
    return ret;
}

int main() {
    setbuf(stdout,NULL);
    printf("%s",add("0","99").c_str());
    
    return 0;
}
