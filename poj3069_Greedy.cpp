#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int N,R;
int arr[1001];

void solve(){
  sort(arr,arr+N);
  int head = 0;
  int res = 0;
  while(head<N){
    int s = arr[head++];
    while(head<N && arr[head] <= s + R) head++;
    int p = arr[head-1];
    while(head<N && arr[head] <= p + R) head++;
    res++;
  }
  printf("%d\n",res);
}

int main(){
  while(true){
    scanf("%d%d",&R,&N);
    if(R==-1&&N==-1){
      break;
    }
    for(int i=0;i<N;i++){
      cin>>arr[i];
    }
    solve();
  }
  return 0;
}
