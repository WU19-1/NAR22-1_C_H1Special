#include<stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    getchar();

    int arr[100000] = {};
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    getchar();

    int last = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            arr[last++] = arr[i];
        }
    }

    for(int i = last; i < n; i++){
        arr[i] = 0;
    }

    printf("%d", arr[0]);
    for(int i = 1 ; i < n ; i++){
        printf(" %d", arr[i]);
    }
    puts("");

    return 0;
}