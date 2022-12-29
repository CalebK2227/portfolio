#include<stdio.h>

//returns the product(5,10) = 5 * 6 * 7 * 8 * 9 * 10;

int product(int a, int b) 
{
    int mid;
    if (a == b) 
       return a;
    else {
      mid = (a + b) / 2;
      return product(a, mid) * product(mid + 1, b);
   }   
}

int main() {

	int p;
	p = product(5,10);
	printf("product is %d\n", p);

	return 0;
	
}
