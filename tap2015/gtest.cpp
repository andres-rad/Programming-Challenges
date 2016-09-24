#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "iostream"
#include "cstring"
#include "stdlib.h"


#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair

using namespace std;

map<char,char> rev = {{'b','d'},{'d','b'},{'p','q'},{'q','p'},
					  {'o','o'},{'v','v'},{'w','w'},{'x','x'}};
					  
char c[1005];

int dfs(char*a, char*b, int n, int k, int i, int j, bool reversed){
	if (k == n) return 0;

	int m = 10000;

	//if(!reversed) {
	//	if(a[k] == b[i]) {
	//		m = dfs(a,b,n,k+1,i+1,j,false);
	//	} else if(a[k] == rev[b[j]]) {
	//		m = dfs(a,b,n,k+1,i,j-1,true) + 1;
	//	}
	//} else {
	//	if(a[k] == rev[b[j]]) {
	//		m = dfs(a,b,n,k+1,i,j-1,true);
	//	} else if(a[k] == b[i]) {
	//		m = dfs(a,b,n,k+1,i+1,j,false) + 1;
	//	}
	//}

	int mm=10000;
	if(a[k] == b[i]) {
		mm = dfs(a,b,n,k+1,i+1,j,false) + (reversed ? 1 : 0);
		//cout<<"primer caso "<<k<<" "<<i<<" "<<mm<<endl;
	}
	if(a[k] == c[j]) {
		m = min(m,dfs(a,b,n,k+1,i,j-1,true) + (reversed ? 0 : 1));
		//cout<<"segundo caso "<<k<<" "<<j<<" "<<m<<endl;
	}

	m=min(m,mm);
	return m;
}


int main() {

	ios::sync_with_stdio(false);
	
	int n=900;
	
	char examp[]={ 'b', 'd', 'o', 'p', 'q', 'v', 'w', 'x'};
	int j=0;
	
	
	char a[1005],b[1005];

	while (j<n){
		a[j]=examp[j%8];
		b[j]=examp[j%8];
		j++;
	}
	
	
	
	
	
	cout<<n<<endl;
	
	forn(i,n){
		cout<<a[i];
	}
	cout<<endl;
	
	forn(i,n){
		cout<<b[i];
	}
	cout<<endl;
	
	return 0;

}
