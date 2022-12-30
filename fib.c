#include<stdio.h>
#include<math.h>

int fibonacci(int n);

int main(void){
    int n;
    n = 10;
    printf("The %dth fibonacci sequence is %d\n", n, fibonacci(n));
    return 0;
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return(fibonacci(n-1) + fibonacci(n-2));
    }
    
}