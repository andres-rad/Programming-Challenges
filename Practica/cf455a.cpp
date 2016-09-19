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
    
		vector <tint> cant (100000+2,0);
		
		forn (i,n){
			tint t;
			cin>>t;
			
			cant[t+1]+=t;
		}
		forr (i,2,100000+2){
			cant[i]=max(cant[i-1], cant[i-2]+cant[i]);
		}
		
		cout<<cant[100001]<<endl;
		
			
			
		
		
		
    }
    
    return 0;
}
