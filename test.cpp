#include <stdio.h> 
#include <memory.h> 
#include <time.h> 
#define KB 65536 // 256KB 
#define MB 262144 // 1MB 
 
int main(){ 
 
    int *arr; 
    clock_t t; 
    double time; 
    int i, j; 
    time = 0; 
 
    for(i=0;i<1000;i++){ 
        arr = new int[KB]; 
        t = clock(); 
        memset(arr, 100, KB*4); 
        time+=clock()-t; 
        delete []arr; 
    } 
 
    printf("memset으로 256KB 메모리를 100으로 초기화 : %.3fms(밀리초)\n", time/1000); 
 
    time = 0; 
    for(i=0;i<1000;i++){ 
        arr = new int[KB]; 
        t = clock(); 
        for(j = 0 ; j<KB;j++) 
            arr[i] = 100; 
        time+=clock()-t; 
        delete []arr; 
    } 
 
    printf("65536번 반복해서 256KB 메모리를 100으로 초기화 : %.3fms(밀리초)\n", time/1000); 
 
    time=0; 
    for(i=0;i<1000;i++){ 
        arr = new int[MB]; 
        t = clock(); 
        memset(arr, 100, MB*4); 
        time+=clock()-t; 
        delete []arr; 
    } 
 
    printf("memset으로 1MB 메모리를 100으로 초기화 : %.3fms(밀리초)\n", time/1000); 
 
    time = 0; 
    for(i=0;i<1000;i++){ 
        arr = new int[MB]; 
        t = clock(); 
        for(j = 0 ; j< MB;j++) 
            arr[j] = 100; 
        time+=clock()-t; 
        delete []arr; 
    } 
 
    printf("262144번 반복해서 1MB 메모리를 100으로 초기화 : %.3fms(밀리초)\n", time/1000); 
}