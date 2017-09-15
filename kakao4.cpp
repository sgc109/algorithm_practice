#include <map>
#include <iostream>
using namespace std;
typedef long long ll;
struct node{
    int n1,n2,n3;
    bool operator<(const node& rhs) const{
        if(n1 != rhs.n1) return n1 < rhs.n1;
        if(n2 != rhs.n2) return n2 < rhs.n2;
        return n3 < rhs.n3;
    }
};
map<node, int> mp;
ll pow3[33];
int go(int cnt3, int cnt1, int num){
    if(2 * cnt3 < cnt1) return 0;
    if(num == 1) return !cnt3 && !cnt1;
    if(pow3[cnt3] > (ll)num) return 0;
    node nd = node{cnt3, cnt1, num};
    auto it = mp.find(nd);
    if(it != mp.end()) return (*it).second;
    int ret = 0;
    if(cnt1 == 0) ret += go(cnt3 + 1, cnt1 + 1, num - 1);
    else ret += go(cnt3, cnt1 - 1, num - 1);
    if(cnt3 > 0 && num % 3 == 0) ret += go(cnt3 - 1, cnt1, num / 3); 
    mp[nd] = ret;
    return  ret;
}

int solution(int n) {
    pow3[0] = 1;
    for(int i = 1; i < 33; i++) pow3[i] = pow3[i - 1] * 3;
    int answer = go(0, 0, n);
    return answer;
}

int main(){
    cout << solution(7);
    return 0;
}