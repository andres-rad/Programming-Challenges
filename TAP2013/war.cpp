#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

bool mayor(long i, long j){ return (i>j); }

int main(){
	int s;
	cin >> s;
	vector<long> enemigo;
	vector<long> aliado;
	forn(i,s){
		long temp;
		cin >> temp;
		enemigo.pb(temp);
	}

	forn(i, s){
		long temp;
		cin >> temp;
		aliado.pb(temp);
	}

	sort(enemigo.begin(), enemigo.end(), mayor);
	sort(aliado.begin(), aliado.end(), mayor);

	int ganadas = 0;
	vector<long>::iterator it = enemigo.begin();
	for(auto itt = aliado.begin(); itt != aliado.end(); ++itt){
		while(*itt <= *it && itt < aliado.end() && it < enemigo.end()){
			it++;
		}
		if(it == enemigo.end()) break;

		ganadas++;
		it++;


	}
	cout << ganadas << endl;
	return 0;
}