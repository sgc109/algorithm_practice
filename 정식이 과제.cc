#include <stdio.h>
#include <string.h>

int alphaCnt[26];
char buf[1000000];
bool isLower(char c){ return 'a'<=c&&c<='z';}
bool isUpper(char c){ return 'A'<=c&&c<='Z';}
int main() {
	FILE *fp = fopen("Kennedy.txt","r");
	while(fgets(buf,sizeof(buf),fp)){
		int len = strlen(buf);
		for(int i = 0; i < len; i++){
			if(isLower(buf[i])) alphaCnt[buf[i]-'a']++;
			else if(isUpper(buf[i])) alphaCnt[buf[i]-'A']++;
		}
	}
	int cnt=0;
	for(int i = 0; i < 26; i++) cnt+=alphaCnt[i];
	while(1){
		int maxI = -1;
		int maxCnt = -1;
		for(int i = 0; i < 26; i++){
			if(maxCnt < alphaCnt[i]) {
				maxCnt = alphaCnt[i];
				maxI = i;
			}
		}
		if(!maxCnt) break;
		printf("%c %.2lf%%\n",maxI+'a',(double)maxCnt/cnt*100);
		alphaCnt[maxI] = 0;
	}
	return 0;
}