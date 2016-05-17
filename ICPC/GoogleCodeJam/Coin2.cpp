#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int isPrime (long long int a){
  for (int i=2;i<floor(sqrt(a)+1);i++){
    if (a%i==0) return i;
  }
  return 0;
}

long long int inBase (int num[],int base){
  long long int res=0;
  int te=1;
  forn(i,16){
    res=res+te*num[15-i];
    te=te*base;
  }
  cout<<"Base "<<base<<" res "<<res<<endl;
  return res;
}

void next (int num[], int n){
  
  bool carry=false;
  num[n-2]++;
  if (num[n-2]==2) {
    num[n-2]=0;
    carry=true;
  }
  
  forn (i,n-3){
    if (carry) {num[n-3-i]++;carry=false;}
    if (num[n-3-i]==2) {
      num[n-3-i]=0;
      carry=true;
    }
  }
  //return;
}

int divel (int num[], int n){
  int res=0;
  forn (i,n){
    if (i%2==0) res=res+num[i];
    else res=res-num[i];
  }
  if (res % 11==0) return 1;
  else return 0;
}

int eleinb (int base){
  int res =1+base;
  return res;
}
int main () {
  
  int n,j;
  
  //long long int curr=1000000000000001;
  
  int num[32]={0};
  num[0]=1;
  //num[15]=1;
  cin>>j;
  cin>>n;
  cin>>j;
  num[n-1]=1;
  
  cout<<"Case #1:"<<endl;
  
  while (j>0){
    if (divel(num, n)){
      j--;
      //cout<<j<<endl;
      
      forn (i,n) cout<<num[i];
      //cout<<endl;
      forn(i,9) cout<<" "<<eleinb(i+2);
      cout<<endl;
      //show answer
    }
    
    next(num,n);
  }
  //for (int i=0;curr<10000000000000000)
  /*cin>>j;
  while (j>0){
    //cout<<"!"<<endl;
    int div[10]={0};
    forn (i,9){
      div[i]=isPrime(inBase(num,i+2));
      //cout<<div[i]<<"  ";
    }
    cout<<endl;
    if (not(div[0]==0||div[1]==0||div[2]==0||div[3]==0||div[4]==0||div[5]==0||div[6]==0||div[7]==0||div[8]==0)){
      //cout result
      cout<<"a"<<endl;
      forn (i,16) cout<<num[i];
      cout<<endl;
      forn(i,9) cout<<div[i];
      cout<<endl;
      
      j--;
      //siguiente num
      next (num);
    }
    else {
      next(num);
      cout<<"b"<<endl;
    }
  }*/
  
  return 0;
}