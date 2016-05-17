#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)

//typedef pair <int,int> punto;



int main () {

  int x,y,x0,y0,size,temp,h;
  char s[100010];
  int te[100010];
  //punto prevs[100010];
  int prevs[505][505];
  forn (i,505){
    forn (j, 505) prevs[i][j]=0;
  }
  char a;
  size=0;
  temp=0;

  cin>>x>>y>>x0>>y0;

  while (cin>>a){
    s[size]=a;
    size++;
  }
//  te[0]=1;
  //forn (i,size) cout<<s[i];

  forn (i,size){
    h=0;
    if (prevs[x0][y0]==0){
      te[i]=1;
      temp++;
      h=1;

      prevs[x0][y0]=1;
    }

    if ((s[i]=='U')&&(x0!=1)) x0-=1;
    else if ((s[i]=='D')&&(x0!=x)) x0+=1;
    else if ((s[i]=='R')&&(y0!=y)) y0+=1;
    else if ((s[i]=='L')&&(y0!=1)) y0-=1;
    //cout<<x0<<" "<<y0<<endl;




    //cout<<temp<<endl;

  }

  te[size]=x*y-temp;
  //if (h==1) te[size]-=1;


  forn(i,size+1) cout<<te[i]<<" ";
  cout<<endl;


  return 0;
}
