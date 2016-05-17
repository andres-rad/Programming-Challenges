//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1130

//Esta versión usa arrays y es mas chota que la Minesweeper2.cpp

#include <iostream>
#include <stdio.h>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)

 /* struct Field {
    int n,m;
    char matriz [105][105];
    
  };*/
int main () {
  

  
  //Field fields[100010];
  int n[100010];
  int m[100010];
  char matriz[500][101][101];
  
  int a,b,f;
  f=0;
  
  cin>>a>>b;
  
  while ((a!=0)&&(b!=0)){
    n[f]=a;
    m[f]=b;
    
    forn (i,a){
      forn (j,b){
        //matriz[f][i][j]=getchar(); 
        cin>>matriz[f][i][j];
      }
      getchar();
    }
    
    f++;
    cin>>a>>b;
    
  }
  
  forn (h,f){
    forn (i,n[h]){
      forn (j,m[h]){
        if (matriz[h][i][j]=='.') matriz[h][i][j]='0';
      }
    } 
  }
  
  forn (h,f){
    forn (i,n[h]){
      forn (j,m[h]){
        if (matriz[h][i][j]=='*'){
          if (i!=n[h]-1){
            if (matriz[h][i+1][j]!='*') matriz[h][i+1][j]+=1;
            if ((j!=m[h]-1)&&(matriz[h][i+1][j+1]!='*')) matriz[h][i+1][j+1]+=1;
            if ((j!=0)&&(matriz[h][i+1][j-1]!='*')) matriz[h][i+1][j-1]+=1;
          }
          if (i!=0){
            if (matriz[h][i-1][j]!='*') matriz[h][i-1][j]+=1;
            if ((j!=m[h]-1)&&(matriz[h][i-1][j+1]!='*')) matriz[h][i-1][j+1]+=1;
            if ((j!=0)&&(matriz[h][i-1][j-1]!='*')) matriz[h][i-1][j-1]+=1;
          }
          if (j!=m[h]-1){
            if (matriz[h][i][j+1]!='*') matriz[h][i][j+1]+=1;
          }
          if (j!=0){
            if (matriz[h][i][j-1]!='*') matriz[h][i][j-1]+=1;
          }
        }
      }
    }
  }
  
  
  
  forn (h,f){
    cout<< "Field #"<<h+1<<":"<<endl;
    forn (i,n[h]){
      forn (j,m[h]){
        cout<<matriz[h][i][j];
      }
      cout<<endl;
    }
    if(h!=f-1) cout<<endl;
    
  }
  
  
  
  
  return 0;
}
