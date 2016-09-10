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

	if(a[k] == b[i]) {
		m = dfs(a,b,n,k+1,i+1,j,false) + (reversed ? 1 : 0);
	}
	if(a[k] == rev[b[j]]) {
		m = min(m,dfs(a,b,n,k+1,i,j-1,true) + (reversed ? 0 : 1));
	}

	return m;
}


int main() {

	ios::sync_with_stdio(false);
	
	int n;
	char a[1005],b[1005];

	while(cin >> n){
		if(n<1 || n > 1000) return 0;

		cin >> a >> b;
		//scanf("\n%s",a);
		//scanf("\n%s",b);

		//cout << "a " << a << endl;
		//cout << "b " << b << endl;

		int res = dfs(b,a,n,0,0,n-1,false);

		if(res>=10000) res = -1;

		cout<<res<<endl;
	}

	return 0;

}
