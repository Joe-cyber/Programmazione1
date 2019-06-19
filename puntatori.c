#include <stdio.h>
#define l 10
int search(const int a[], int n, int key);

int main(void) 
{
 int a[l]={1,2,3,4,5,6,7,8,9,10}, key=5;
 if(search(a,l,key))
 printf("yes");
 else 
  printf("no");

return 0;
}

int search(const int a[], int n, int key)
{
	int i;
	for(i=0;i<n;i++)
        if(*(a+i)==key)
        return 1;
        return 0;
}
