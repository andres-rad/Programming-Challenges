//touch {a..m}.in; tee {a..m}.cpp < template.cpp
//#include <bits/stdc++.h>

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef long long int tint;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl //;)

const int MAXN=100100;
int n;

int main() {
	int n,m;
    while(cin >>m>> n){

		vector<vector<int> > res (204, vector<int> (204,0));

		forr (i,1,201){
			forr(j,0,i+1){
				//cout<<i-j<<' '<<j<<endl;
				if (j!=0 && j!=i){
					res[i-j][j]= max(res[max(0,i-j-2)][j+1], res[i-j+1][max(0,j-2)])+1;
				}
				//res[min(max(1,i-j),100)][min(max(1,j),100)]= max(res[min(100,i-j+1)][max(min(100,j-2),0)], res[max(min(100,i-j-2),0)][min(100,j+1)]) +1;
			}
		}
		
/*
		forn (i,101){
			forn (j,101){
				cout<<res[i][j]<<' ';
			}
			cout<<endl;
		}

		cout<<endl<<endl;
		*/

		res[1][1]=0;
		cout<<res[n][m]<<endl;




    }

    return 0;
}
