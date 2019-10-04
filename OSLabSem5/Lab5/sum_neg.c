#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int arr[100];

void* sum_neg(void* param){
    int n = (int) param;
    int sum = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > 0)
            sum+=arr[i];
    }
    return (void*)sum;
}

int main(){
    pthread_t thread;
    int n;
    printf("Enter number of elems: \n");
    scanf("%d", &n);
    printf("Enter elems: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    pthread_create(&thread, 0, &sum_neg, (void*)n);
    int sum;
    pthread_join(thread, (void**)&sum);

    printf("Sum of non-neg: %d\n", sum);
    exit(0);
}