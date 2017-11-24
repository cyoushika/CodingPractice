#include<cstdio>
#include<cmath>
#define Max 1000001

int max(int a,int b){
  if(a>=b)
  return a;
  else
  return b;
}

int min(int a,int b){
  if(a>=b)
  return b;
  else
  return a;
}

void solve(int x[],int L,int n){
  int minT = 0;
  for(int i=0;i<n;i++){
    minT = max(minT,min(x[i],L-x[i]));
  }
  int maxT = 0;
  for(int i=0;i<n;i++){
    maxT = max(maxT,max(x[i],L-x[i]));
  }
  printf("%d %d\n",minT,maxT);
}

int main(){
   int T;
   int L;
   int n;
   int a[Max] = {0};
   scanf("%d",&T);

   while(T>0){

     T--;
     scanf("%d%d",&L,&n);
     for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
     }
     solve(a,L,n);
   }


  return 0;
}
