#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int arr[100];

void* getSum_even(void* params){
    int n = (int)params;
    int even_sum = 0;

    for(int i = 0; i<n; i++){
        if(arr[i]%2 == 0)
            even_sum+=arr[i];
    }

    return (void*)even_sum;
}

void* getSum_odd(void* params){
    int n = (int)params;
    int odd_sum = 0;

    for(int i = 0; i<n; i++){
        if(arr[i]%2 != 0)
            odd_sum+=arr[i];
    }

    return (void*)odd_sum;
}

int main(){
    pthread_t thread1, thread2;
    int n;
    printf("Enter number of elems: \n");
    scanf("%d", &n);
    printf("Enter the elems: \n");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int even_sum, odd_sum;
    pthread_create(&thread1, 0, getSum_even, (void*)n);
    pthread_create(&thread2, 0, getSum_odd, (void*)n);

    pthread_join(thread1, (void**)&even_sum);
    pthread_join(thread2, (void**)&odd_sum);

    printf("The sum of odd nums = %d\n", odd_sum);
    printf("The sum of even nums = %d\n", even_sum);

    exit(0);
}