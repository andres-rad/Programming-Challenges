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

typedef long long int tint;


int main () {

  int n;
  cin>>n;

  vector<int> estados;
  estados.pb(0);

  forn (i,n){
    int temp;
    cin>>temp;
    estados.pb(temp);
  }

  vector<vector<int > >   dp(n+1, vector<int> (3, 0));
  //dp[i][j] hasta el iesimo dia, cuantos dias trabaje si la ultima actividade fue descansar (0), escribir (1) o gym (2)


  for (int i=1; i<n+1; i++){
    if (estados[i]==0){
      dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
      dp[i][1]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
      dp[i][2]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
    }else if (estados[i]==1){
      dp[i][1]=max(dp[i-1][1],max(dp[i-1][0], dp[i-1][2])+1);
      dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
      dp[i][2]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));

    }else if (estados[i]==2){
      dp[i][2]=max(dp[i-1][2],max(dp[i-1][0], dp[i-1][1])+1);
      dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
      dp[i][1]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));

    }else if (estados[i]==3){
      dp[i][1]=max(dp[i-1][1],max(dp[i-1][0], dp[i-1][2])+1);
      dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
      dp[i][2]=max(dp[i-1][2],max(dp[i-1][0], dp[i-1][1])+1);

    }
  }

  //cout<<dp[n][1]<<endl;

  cout<<n-max(dp[n][0],max(dp[n][1], dp[n][2]))<<endl;


  return 0;
}
