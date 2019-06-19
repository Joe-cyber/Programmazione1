#include <stdio.h>
void trova_due_max(const int *, int, int *, int *);
int main(void)
{
 int a[7]={13,14,2,3,5,23,30}, max1, max2;
 trova_due_max (a, 7, max1, max2);
 printf("%d, %d", max1, max2);

return 0;
}


void trova_due_max(const int a*, int l, int x*, int y*)
{
     
if(a[0]>a[1])
{ x=&a[0];
  y=&a{1};
}
else 
{ x=&a[1];
  y=&a[0];
}

int *p=a[2];

if(a[0]>a{1])
*max1=a[0];
*max2=a[1];
else {
*max1=a{1};
*max2=a[0];
}

