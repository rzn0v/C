#include<stdio.h>
int main(){
    int arr[] = {5, 10, 2, 4, 25, 34, 15};
    int length = sizeof(arr)/ sizeof(arr[0]);
    int max = arr[0];

    for(int i = 0; i < length; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("Max: %d", max);
    return 0;
}