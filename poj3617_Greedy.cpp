#include<cstdio>
#include<iostream>
using namespace std;

int N;
char s[2010];

void solve(){
  int a=0;
  int b=N-1;
  int counter=0;
  while(a<=b){
    bool left = false;
    for(int i=0;a+i<=b;i++){
      if(s[a+i]<s[b-i]){
        left=true;
        break;
      }
      else if(s[a+i]>s[b-i]){
        left=false;
        break;
      }
    }

    if(left) putchar(s[a++]);
    else putchar(s[b--]);
    counter++;
    if(counter==80){
      putchar('\n');
      counter=0;
    }
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    cin>>s[i];
  }
  solve();
}
