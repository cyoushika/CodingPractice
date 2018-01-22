#include<cstdio>
#include<queue>
using namespace std;

#define Max_N 101
#define INF 100000000

char map[Max_N][Max_N];// Map
int memo[Max_N][Max_N];// Distance
int N,M;
int x[4] = {-1,1,0,0};//left,right,up,down
int y[4] = {0,0,1,-1};
int sx,sy,gx,gy;

typedef pair<int,int> P;

int bfs(){
  queue<P> que;
  que.push(P(sx,sy));
  while(que.size()){
    P p = que.front();
    que.pop();
    if(p.first == gx && p.second == gy)
      break;
    for(int i=0;i<4;i++){
      int pointer_x = p.first+x[i];
      int pointer_y = p.second+y[i];
      if(pointer_x>=0&&pointer_x<N&&pointer_y>=0&&pointer_y<N&&memo[pointer_x][pointer_y]==INF&&map[pointer_x][pointer_y]!='#'){
        que.push(P(pointer_x,pointer_y));
        memo[pointer_x][pointer_y]=memo[p.first][p.second]+1;
      }
    }
  }
  return memo[gx][gy];
}

void solve(){
  int result = bfs();
  printf("%d\n",result);
}

int main(){
  int i,j;
  char tmp[Max_N];
  scanf("%d%d",&N,&M);
  for(i=0;i<N;i++){
    scanf("%s",tmp);
    for(j=0;j<M;j++){
      map[i][j]=tmp[j];
      if(tmp[j]=='S'){
        memo[i][j]=0;
        sx=i;
        sy=j;
      }
      else if(tmp[j]=='G'){
        memo[i][j]=INF;
        gx=i;
        gy=j;
      }
      else{
        memo[i][j]=INF;
      }
    }
  }
  solve();

  // printf("\n");
  // for(i=0;i<N;i++){
  //   for(j=0;j<M;j++){
  //     printf("%c",map[i][j]);
  //   }
  //   printf("\n");
  // }
}
