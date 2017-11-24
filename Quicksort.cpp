#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int a[10] = {10,9,8,7,6,5,4,3,2,1};

int compareMyType(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

int main(){
  qsort(a,10,sizeof(int),compareMyType);
  for(int i=0;i<10;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
// void qsort(int l,int r,int a[]){
//   int i = l;
//   int j = r;
//   int w = (l+r)/2;
//   while(i<=j){
//     while(a[i]<a[w]) i++;
//     while(a[j]>a[w]) j--;
//     if(i<=j){
//       int tmp = a[i];
//       a[i] = a[j];
//       a[j] = tmp;
//       i++;
//       j--;
//     }
//   }
//   if(l<j) qsort(l,j,a);
//   if(i<r) qsort(i,r,a);
// }
//
// int main(){
//   int n;
//   int a[100] = {0};
//   scanf("%d",&n);
//   //printf("n=%d\n",n);
//   int p = 0;
//   while(true){
//     scanf("%d",&a[p]);
//     p++;
//     //printf("p=%d\n",p);
//     if(p==n)
//     {
//       //printf("Break!\n");
//       break;
//     }
//   }
//   //printf("we came here");
//
//   qsort(0,n-1,a);
//   bool flag = true;
//   int i = n-3;
//   int j = n-2;
//   int m = n-1;
//   for(;i>=0;)
//   {
//     if(a[i]+a[j]>a[m])
//     {
//       printf("%d\n",a[i]+a[j]+a[m]);
//       flag = false;
//       break;
//     }
//     i--;
//     j--;
//     m--;
//   }
//   if(flag){
//     printf("0\n");
//   }
//   return 0;
// }
