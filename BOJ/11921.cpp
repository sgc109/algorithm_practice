#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    if(n > 500000) n = 500000;
    long long sum = 0;
    for(int i = 0 ; i < n; ++i) {
        int tmp;
        scanf("%d",&tmp);
        sum += tmp;
    }
    printf("%d\n%lld",n,sum);
    
    return 0;
}

