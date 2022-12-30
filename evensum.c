#include<stdio.h>
#include<math.h>

int evensum(int n);

int main(void){
    int n;
    n = 10;
    printf("The sum of the first %d even numbers is %d\n", n, evensum(n));
    return 0;
}

int evensum(int n){
    int even;
    if(n == 0){
        return 0;
    }
    else{
        even = ((n - 1) * 2);
        return(evensum(n-1)+even);
    }
}