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

	int n;
	cin>>n;

	int i=0;
	while (i<n){
		cout<<"I ";
		if (i%2==0){
			cout<<"hate ";
		}else{
			cout<<"love ";
		}

		if (i!=n-1){
			cout<<"that ";
		}
		i++;
	}
	cout<<"it"<<endl;

	return 0;
}
