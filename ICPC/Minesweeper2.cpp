//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1130

#include <iostream>
#include <stdio.h>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)

  struct Field {
    int n,m;
    char matriz [105][105];
    
  };
int main () {
  Field f;
  
  int a,b,t;
  t=0;
  
  cin>>a>>b;
  
  while ((a!=0)&&(b!=0)){
    f.n=a;
    f.m=b;
    
    forn (i,a){
      forn (j,b){
        //matriz[f][i][j]=getchar(); 
        cin>>f.matriz[i][j];
      }
      getchar();
    }
    
    
   
    forn (i,f.n){
      forn (j,f.m){
        if (f.matriz[i][j]=='.') f.matriz[i][j]='0';
      }
    } 
  
  
  
    forn (i,f.n){
      forn (j,f.m){
        if (f.matriz[i][j]=='*'){
          if (i!=f.n-1){
            if (f.matriz[i+1][j]!='*') f.matriz[i+1][j]+=1;
            if ((j!=f.m-1)&&(f.matriz[i+1][j+1]!='*')) f.matriz[i+1][j+1]+=1;
            if ((j!=0)&&(f.matriz[i+1][j-1]!='*')) f.matriz[i+1][j-1]+=1;
          }
          if (i!=0){
            if (f.matriz[i-1][j]!='*') f.matriz[i-1][j]+=1;
            if ((j!=f.m-1)&&(f.matriz[i-1][j+1]!='*')) f.matriz[i-1][j+1]+=1;
            if ((j!=0)&&(f.matriz[i-1][j-1]!='*')) f.matriz[i-1][j-1]+=1;
          }
          if (j!=f.m-1){
            if (f.matriz[i][j+1]!='*') f.matriz[i][j+1]+=1;
          }
          if (j!=0){
            if (f.matriz[i][j-1]!='*') f.matriz[i][j-1]+=1;
          }
        }
      }
    }
  
    
    t++;
    
    cout<< "Field #"<<t<<":"<<endl;
    forn (i,f.n){
      forn (j,f.m){
        cout<<f.matriz[i][j];
      }
      cout<<endl;
    }
    cin>>a>>b;    
    if((a!=0)&&(b!=0)) cout<<endl;
    
    
    
  }
  
  
  
  return 0;
}