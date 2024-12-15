#include<stdio.h>
int main(){
    int num, rev = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    while(num > 0){
        rev = rev * 10;
        rev = rev + (num % 10);
        num = num / 10;
    }
    printf("%d", rev);
    return 0;
}