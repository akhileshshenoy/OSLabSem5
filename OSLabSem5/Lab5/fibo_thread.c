#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//int arr[100];

void* genfib(void* ary){
    int* arr = (int*)ary;
    int lim = arr[99];
    int k = 2;
    int flag = 0;
    for(int i=3; i<=lim; i++){
        arr[k] = arr[k-1] + arr[k-2];
        k++;
    }
    flag = 1;

    return (void*)flag;
}

int main(){
    pthread_t thread;
    int arr[100];
    arr[0] = 0;
    arr[1] = 1;
    //int n;
    printf("Enter length of fibo series:\n");
    scanf("%d", &arr[99]);
    pthread_create(&thread, 0, genfib, (void*)&arr);
    int flag;
    pthread_join(thread, (void**)&flag);
    printf("Fibo Series: \n");
    for(int i=0; i<arr[99]; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
