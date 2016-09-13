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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main(){

	int n, mi, ch;
	cin>>n;
	mi=0;
	ch=0;

	forn (i,n){
		int m,c;
		cin>>m>>c;
		if (m>c) mi++;
		else if (m<c) ch++;
	}

	if (mi>ch){
		cout<<"Mishka"<<endl;
	}else if (mi<ch){
		cout<<"Chris"<<endl;
	}else{
		cout<<"Friendship is magic!^^"<<endl;
	}

	return 0;
}
