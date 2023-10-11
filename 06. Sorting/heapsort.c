// heapsort
#include <stdio.h>
#include<stdlib.h>
void  create_heap (int  *, int  );
void   heap_sort (int *,  int );
void   rec_heap_sort (int *,  int );
void main( )
{   
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heap_sort(a,n);
    printf("\n Sorted List:\n");
    for(int i=0; i<n; i++)
       printf("%d\t", a[i]);
}
void  create_heap (int  *a, int  n)
{
   int  elt, i, f, s;
   for (i=1; i<n; i++)
   {
       elt= a[i];
       s=i;
       f=(s-1)/2;
       while (s>0 && a[f]<elt)
        {
            a[s]=a[f];
            s=f;
            f=(s-1)/2;   
        }  
      a[s]=elt;
   }
}
void   heap_sort (int *a,  int n)
{
     int i, temp;
     create_heap (a, n);
     for(i=n-1; i>0; i--)
     {
           temp=a[i];
           a[i]=a[0];
           a[0]=temp;
           create_heap(a, i);
      }
}
void  rec_heap_sort (int  *a, int  n) 
{
   int  t;
   if(n>1)
   {
      create_heap (a, n);
     t=a[n-1];
     a[n-1]=a[0];
     a[0]=t;
     rec_heap_sort (a, n-1);
   } 
}