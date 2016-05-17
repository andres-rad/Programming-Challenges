#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int main () {

  int h,w,q;

  char mat[505][505];
  int matr[505][505]={0};
  int matc[505][505]={0};
  int que [100005] [4];

  cin>>h>>w;

  forn (i,h){
    forn (j,w){
      //matriz[f][i][j]=getchar();
      cin>>mat[i][j];
      //cout<<mat[i][j];
    }
    //getchar();
    //cout<<endl;
  }

  cin>>q;
  forn (i,q) {
    forn (j,4){
      cin>>que [i][j];
    }
  }

  forn (j, h+1){
    forn (p,w+1){
      if (mat[j][p]=='.'&&mat[j+1][p]=='.') matr[j+1][p]=matr[j][p]+1;
      else matr[j+1][p]=matr[j][p];
      if (mat[j][p]=='.'&&mat[j][p+1]=='.') matc[j][p+1]=matc[j][p]+1;
      else matc[j][p+1]=matc[j][p];
      //cout<<matc[j][p];

    }
    //cout<<endl;
  }

  forn (i,q){

    int cnt=0;
    for (int j=que[i][0]-1;j<=que[i][2]-1;j++){
      cnt+=matc[j][que[i][3]-1]-matc[j][que[i][1]-1];
    }
    for (int j=que[i][1]-1;j<=que[i][3]-1;j++){
      cnt+=matr[que[i][2]-1][j]-matr[que[i][0]-1][j];
    }
    cout<<cnt<<endl;
  }





/*
  forn (i,q){
    int t=0;

    for (int j=que[i][0];j<que[i][2];j++){

      for (int p=que[i][1];p<que[i][3];p++){

        if (matr[j][p]==1) t++;
        else if (matr[j][p]==0){
          if (mat[j][p]=='.'&&mat[j+1][p]=='.') {
            t++;
            matr[j][p]=1;}
          else matr[j][p]=2;
        }

        if (matc[j][p]==1) t++;
        else if (matc[j][p]==0){
          if (mat[j][p]=='.'&&mat[j][p+1]=='.') {
            t++;
            matc[j][p]=1;}
          else matc[j][p]=2;

        }


        //cout<<j<<"  "<<p<<endl;

      }
    }

    for (int j=que[i][0];j<que[i][2];j++){
      if (mat[j][que[i][3]]=='.'&&mat[j+1][que[i][3]]=='.') {t++;}

    }

    for (int p=que[i][1];p<que[i][3];p++){

      if (mat[que[i][2]][p]=='.'&&mat[que[i][2]][p+1]=='.') {t++;}
    }

    cout<<t<<endl;
  }
*/
  return 0;

}
