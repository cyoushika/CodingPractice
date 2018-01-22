#include<cstdio>
#include<queue>
using namespace std;
typedef long long int llt;

int main(){

    llt N,L;
    scanf("%lld",&N);
    priority_queue<llt,vector<llt>,greater<llt> > PQ;
    for(int i=0;i<N;i++){
      int L;
      scanf("%d",&L);
      PQ.push(L);
    }

    llt sum = 0;
    while(PQ.size()>1){
      llt tmp = PQ.top();
      PQ.pop();
      tmp += PQ.top();
      PQ.pop();
      sum+=tmp;
      PQ.push(tmp);
    }
    printf("%lld\n",sum);
  return 0;
}
