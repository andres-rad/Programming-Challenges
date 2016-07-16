#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <set>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back

int main(){
	int casos;
	cin >> casos;
	int caso = 0;
	while(caso < casos){
		caso++;
		string logg;
		cin >> logg;
		int n = logg.size();
		for(int i = 1; i <= n; i++){
			set<string> comb;
			int j = 0;
			while(comb.size() != pow(2, i) && j+i <= n){
				comb.insert(logg.substr(j, i));
				j++;
			}
			if(comb.size() < pow(2, i)){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}