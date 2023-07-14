#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Luhn algorithm is used to validate credit card numbers. Credit card numbers has 16 digits.There are three steps to determine if card 
numbers is valid.
1) Calculate sum of numbers that has odd index.
2) Multiply digits at even indexes by 2 and sum. If result greater than 9, calculate sum of the inividual digits.
3) If the sum of step 1 + step 2 divided by 10, number is valid. */
 


int main(){
    int number[16],i;
    int sum_odd=0 , sum_even=0 , temp;
    printf("enter a number has 16 digits=\n");
    for(i=0;i<16;i++){ 
       scanf("%1d",&number[i]);
       printf("%d-",number[i]);
    }
    // dizinin çift indexe sahip elemanlarını toplar
    for(i=0;i<16;i++){
        if((i%2)==1){
            sum_even= sum_even + number[i];
        }
        
    }
    printf("\n %d",sum_even);

    // dizinin tek indexe sahip elemanlarıyla ilgili işlemi yapar

    for(i=0;i<16;i++){
        if((i%2)==0){
            temp=(number[i]*2);
            if(temp<10){
                sum_odd+=temp;
            }
            else if(temp>=10){
                    while(temp>0){
                sum_odd+=(temp%10);
                temp/=10;}
            }
        }
    }
    printf("\n%d",sum_odd);

    if(((sum_odd+sum_even)%10==0)){
        printf("\n your credit number is valid");
    }
    else printf("your crredit number isn't valid");

}

