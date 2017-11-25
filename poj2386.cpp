#include<cstdio>
using namespace std;
#define Max_N 101
char map[Max_N][Max_N];
int memo[Max_N][Max_N];
int N,M;
int row[8] = {-1,1,0,0,-1,-1,1,1}; //up,down,left,right,up-left,up-right,down-left,down-right
int col[8] = {0,0,-1,1,-1,1,-1,1};

void dfs(int n,int m){
  int pointer_row, pointer_col;
  //printf("We are in (%d,%d) now\n",n,m);
  for(int i=0;i<8;i++){
    pointer_row = n+row[i];
    pointer_col = m+col[i];
    //printf("We are checking (%d,%d) now\n",pointer_row,pointer_col);
    if((pointer_row>=0)&&(pointer_row<N)&&(pointer_col>=0)&&(pointer_col<M)){
      if(memo[pointer_row][pointer_col]!=1){
        memo[pointer_row][pointer_col]=1;
        if(map[pointer_row][pointer_col]=='W'){
          dfs(pointer_row,pointer_col);
        }
      }
    }
  }
}

int solve(){
  int result = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(memo[i][j]!=1 && map[i][j]=='W'){
        //printf("We found a water at (%d,%d)\n",i,j);
        result++;
        memo[i][j]=1;
        dfs(i,j);
      }
    }
  }
  return result;
}

int main(){
  char tmp[Max_N];
  scanf("%d%d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%s",tmp);
    for(int j=0;j<M;j++){
      map[i][j]=tmp[j];
    }
  }
  //printf("map[0][0]=%c\n",map[0][0]);
  printf("%d\n",solve());
  return 0;
}
