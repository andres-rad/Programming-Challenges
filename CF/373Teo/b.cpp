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
#define fs first
#define sd second


int main () {
  
  int n;
  cin>>n;

  vector<vector<int> > dp(n+1, vector<int> (2,1000000000));

  vector<int> seq;
  seq.pb(-1);

  forn (i,n){
    char t;
    cin>>t;
    if (t=='b'){
      seq.pb(0);
    }
    else{ seq.pb(1);
    }
  }
  dp[0][0]=0; dp[0][1]=0;

  dp[1][seq[1]]=0;
  dp[1][(seq[1]+1)%2]=1;

  for (int i=2;i<n+1;i++){
    if (seq[i-1]!=seq[i]){

      dp[i][seq[i]]=dp[i-1][(seq[i]+1)%2];
      //cout<<i<<" "<<dp[i][seq[i]]<<endl;

      dp[i][(seq[i]+1)%2]=min(dp[i-1][seq[i]]+1, dp[i-2][seq[i-1]]+1);


    }else{
      dp[i][seq[i]]=dp[i-1][(seq[i]+1)%2];
      dp[i][(seq[i]+1)%2]=dp[i-1][seq[i]]+1;
    }
  }


  cout<<min(dp[n][0], dp[n][1])<<endl;
  
  return 0;
}