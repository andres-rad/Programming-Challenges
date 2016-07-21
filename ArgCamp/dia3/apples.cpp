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

int main(){
	int bolsa;
	while(cin >> bolsa){
		int pares=0;
		int impares=0;
		forn(i, bolsa){
			int temp;
			cin >> temp;
			if(temp%2==0){
				pares++;
			} else {
				impares++;
			}
		}
		if(impares%2==0) cout << pares << endl;
		if(impares%2==1) cout << impares << endl;
	}	
	return 0;
}
