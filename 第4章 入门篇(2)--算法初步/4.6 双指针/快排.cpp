#include<stdio.h>

int a[100010];

int Partition(int a[], int left, int right)
{
    int temp = a[left];
    while(left<right)
    {
        while(left<right&&a[right]>temp) right--;
        a[left] = a[right];
        while(left<right&&a[left]<=temp) left++;
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
}

void quickSort(int a[], int left, int right)
{
    if(left<right)
    {
        int pos = Partition(a, left, right);
        quickSort(a,left, pos-1);
        quickSort(a,pos+1, right);
    }
}

int main()
{
   // int n;
   // scanf("%d",&n);
    //while(scanf("%d",&n);)
 
      int m;
      scanf("%d",&m);
      
      for(int i=0; i<m; i++)
            scanf("%d",&a[i]);
      quickSort(a, 0, m-1);
      for(int i=0; i<m; i++)
            printf("%d\n",a[i]);
 
 
   return 0;
}