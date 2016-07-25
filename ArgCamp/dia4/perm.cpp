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

typedef pair<int,int> par;
typedef long long int tint;


tint modulo = 1000003;
vector<tint> seq(1000010);

void secuencia(){
	seq[1]=1;
	forsn(i,2,1000003){
		seq[i] = (1 + i*seq[i-1])%modulo;
	}
}
int main(){
	int q;
	cin >> q;
	secuencia();
	forn(i,q){
		int temp;
		cin>>temp;
		cout << seq[temp]	<< endl;
	}
	return 0;
}
