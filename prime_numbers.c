#include<stdio.h>
int main(){
    int num, flag = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    for(int i = 2; i < num - 1; i++){
        if(num % i != 0){
            continue;
        }
        else{
            flag = 1;
            printf("The given number is not a prime number. ");
            break;
        }
    }
    if(flag == 0){
        printf("The given number is a prime number. ");
    }
    return 0;
}