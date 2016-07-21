#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cassert>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

int perim(vector<vector<char> > &campo, int i, int j){
	int tot = 0;
	if(i==0){
		tot++;
	}else if(campo[i-1][j] == 'H'){
		tot++;
	}
	
	if(j==0){
		tot++;
	} else if(campo[i][j-1] == 'H'){
		tot++;
	}
	
	if(i==99){
		tot++;
	} else if(campo[i+1][j] == 'H'){
		tot++;
	}
	
	if(j==99){
		tot++;
	} else if(campo[i][j+1] == 'H'){
		tot++;
	}
	
	return tot;
}
int n;
vector<vector<char> > campo(n, vector<char>(n, 'H'));
int main(){
	cin >> n;
	forn(i,n){
			int k, l;
			cin >> k >> l;
			campo[k][l] = 'B'; 
	}
	int res = 0;
	forn(i,100){
		forn(j,100){
			res+= perim(campo, i, j);
		}
	}
	cout << res << endl;
	return 0;
}
