#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

map<long long,int> mp;
int cnt;
int string2int(string& str){
	int ret = 0;
	for(int i = 0 ; i < str.size(); i++){
		ret = ret * 10 + str[i] - '0';
	}
	return ret;
}

void go(string str, int depth){
	int st = 0;
	int sec = 0;
	int i;
	for(i = 0 ; i < str.size(); i++){
		if(str[i] == '[') st++;
		else if(str[i] == ']') st--;
		if(!sec && st == 1) sec = 1;
		else if(sec && st == 1 && str[i] == ',') break; 
	}
	if(i == str.size()){
		long long num = (long long)string2int(str);
		mp[num<<depth]++;
		cnt++;
		return;
	}
	go(str.substr(1, i - 1), depth+1);
	go(str.substr(i+1, str.size() - 2 - i), depth+1);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		mp.clear();
		string str;
		cin >> str;
		cnt = 0;	
		go(str, 0);
		int ans = INF;
		for(auto it = mp.begin(); it != mp.end(); it++){
			ans = min(ans, cnt - (*it).second);
		}
		printf("%d\n",ans);
	}

	return 0;
}
