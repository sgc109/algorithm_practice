#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
char str[10][100];
int cnt;
void go(int pos, vector<int> v){
	if(pos == N){
		do{
			char tmp[1000] = "";
			for(int i = 0 ; i < (int)v.size(); i++){
				strcat(tmp, str[v[i]]);
			}
			// FILE *fp;
			// char buf[100] = "";
			// sprintf(buf, "output%d", cnt);
			// fp = fopen(buf,"wb");
			cnt++;
			// int len = strlen(tmp);
			// fwrite(tmp, sizeof(char), len, fp);
			// fclose(fp);
		} while(next_permutation(v.begin(), v.end()));
		return;
	}
	go(pos+1, v);
	v.push_back(pos);
	go(pos+1, v);
}
int main() {
	int i;
	for(i = 0 ; ~scanf("%s", str[i]); i++);
	N = i;
	go(0, vector<int>());
	cout << cnt;
	return 0;
}