//touch {a..m}.in; tee {a..m}.cpp < template.cpp
#include <bits/stdc++.h>

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
	int n;
    while(cin >> n){
    
		vector<vector<int> > res (104, vector<int> (104,0));
		
		forr (i,1,101){
			forr(j,1,101){
				
				res[i][j]= max (res[i+1][max(j-2,0)], res[max(i-2,0)][j+1]) +1;
			}
		}
		
		forn (i,101){
			forn (j,101){
				cout<<res[i][j]<<' ';
			}
			cout<<endl;
		}
		
		cout<<endl<<endl;
		
		cout<<res[3][5]<<endl<<res[4][4];
			
		
		
		
    }
    
    return 0;
}
