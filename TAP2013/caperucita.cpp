#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define forn(i,n) for (long long i=0;i<n;i++)
#define pb push_back
#define mp make_pair

int main(){
	long long N, S;
	cin >> N >> S;
	vector<vector<long long> >caminos(N);

	long long valor[N];
	long long camMax[N];

	forn(i, N){
		valor[i] = camMax[i] = 0;
	}
	valor[0] = 1;
	forn(i, S){
		long long j, k;
		cin >> j >> k;
		caminos[N-k].pb(N-j);
	}
	forn(i, N){
		long long cam = camMax[i] + valor[i];
		for(auto it=caminos[i].begin(); it != caminos[i].end(); ++it){
			//cout << *it << endl;
			valor[*it] += valor[i];
			camMax[*it] = max(camMax[*it], cam);
		}
		//cout << valor[i] << endl;
		//cout << endl;
	}
		//cout << endl;
		//cout << endl;
	cout << (camMax[N-1] + valor[N-1]) << endl;
	return 0;
}