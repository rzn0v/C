#include<stdio.h>
#include<math.h>
int main(){
    int num, sum = 0, length = 0, copy_of_num;
    printf("Enter the number: ");
    scanf("%d", &num);
    copy_of_num = num;
    while(copy_of_num > 0){
        copy_of_num = copy_of_num / 10;
        length++;
    }
    copy_of_num = num;

    while(copy_of_num > 0){
        sum = sum + pow((copy_of_num % 10),length);
        copy_of_num = copy_of_num / 10;
    }
    if(sum == num){
        printf("The given number is an armstrong number.");
    }
    else{
        printf("The given number is not an armstrong number.");
    }
    return 0;
}