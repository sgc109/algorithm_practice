#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[5001][5001];
map<char,int> m;
char s1[5001],s2[5001];
int first1[26],first2[26],last1[26],last2[26];
int len1,len2;
int go(int pos1,int pos2){
    int &ans=dp[pos1][pos2];
    if(ans!=-1)return ans;
    if(pos1==len1-1 && pos2==len2-1)return 0;
    ans=0;
    int a=1e9,b=1e9;
    if(pos1+1!=len1){
        int c=s1[pos1+1]-'A';
        if(first1[c]==pos1+1 && first2[c]>pos2&&m[s1[pos1+1]]>1){
            a=go(pos1+1,pos2)-(pos1+1+pos2);
        }
        else if(last1[c]==pos1+1 && last2[c]<=pos2 && m[s1[pos1+1]]>1){
            a=go(pos1+1,pos2)+(pos1+1+pos2);
        }
        else{
            a=go(pos1+1,pos2);
        }
    }
    if(pos2+1!=len2){
        int c=s2[pos2+1]-'A';
        
        if(first2[c]==pos2+1 && first1[c]>pos1 && m[s2[pos2+1]]>1){
            b=go(pos1,pos2+1)-(pos1+1+pos2);
        }
        else if(last2[c]==pos2+1 && last1[c]<=pos1 && m[s2[pos2+1]]>1){
            b=go(pos1,pos2+1)+(pos1+1+pos2);
        }
        else{
            b=go(pos1,pos2+1);
        }
        
    }
    //cout<<pos1<<' '<<pos2<<min(a,b)<<endl;
    ans=min(a,b);
    return ans;
}
int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        m.clear();
        memset(dp,-1,sizeof(dp));
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        s1[0]='.';
        s2[0]='.';
        len1=strlen(s1);
        len2=strlen(s2);
        for(int i=0;i<26;i++)first1[i]=1e9,first2[i]=1e9,last1[i]=-1e9,last2[i]=-1e9;
        for(int i=1;i<len1;i++){
            m[s1[i]]++;
            if(first1[s1[i]-'A']==1e9)first1[s1[i]-'A']=i,last1[s1[i]-'A']=i;
            else last1[s1[i]-'A']=i;
        }
        for(int i=1;i<len2;i++){
            if(first2[s2[i]-'A']==1e9)first2[s2[i]-'A']=i,last2[s2[i]-'A']=i;
            else last2[s2[i]-'A']=i;
            m[s2[i]]++;
        }
        cout<<go(0,0)<<"\n";
        
    }
    
    return 0;
}