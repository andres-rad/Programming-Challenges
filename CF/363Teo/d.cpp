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

vector<int> vis;

struct nodo{
  int next;
};

vector<nodo> grafo;

int primeraraiz;

bool dfs(int start){
  vis[start]=1;

  bool ans=true;

  if (vis[grafo[start].next]==1){
    ans= grafo[start].next==primeraraiz;
  }else if (vis[grafo[start].next]==2){
    ans= true;
  }else{
    ans= dfs(grafo[start].next);
  }

  vis[start]=2;

  return ans;
}



int main () {

  int n;
  cin>>n;


  vector<int> seq;
  vis=vector<int> (n,0);
  grafo=vector<nodo> (n);
   primeraraiz=-1;

  forn (i,n){
    int t;
    cin>>t;
    if (primeraraiz==-1 && t==i+1){
      primeraraiz=i;
    }
    seq.pb(t);
    grafo[i].next=t-1;
  }

  int ans=0;

  int cnt=0;

  while (cnt<n){
    while (cnt<n && vis[cnt]){
      cnt++;
    }


    //vis=vector<int> (n,0);

    if (cnt<n && !dfs(cnt)){
      if (primeraraiz==-1){
        primeraraiz=cnt;

      }
      ans++;
      seq[cnt]=primeraraiz+1;
    }

  }

  cout<<ans<<endl;

  forn (i,n-1){
    cout<<seq[i]<<' ';
  }
  cout<<seq[n-1]<<endl;

  return 0;
}
