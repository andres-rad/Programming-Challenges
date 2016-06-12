#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair

int main () {

	int t=0, tests;
	cin>>tests;

	while (t<tests){
		t++;

		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > mano;
		pair<int, int> carta;
		int p,q;
		int n;
		cin>>n;
		/*
		if(n==0){
			cout << "possible" << endl;
		}
		else{} */
		// n es mayor igual a 1

		forn (i,n){
			cin>>p>>q;
			carta = mp(min(p,q), max(p,q));
			mano.push(carta);
		}

		vector<set<int> > conexos;
		vector<int> cuenta;

		carta = mano.top();
		mano.pop();

		set<int> primero;

		primero.insert(carta.first);
		primero.insert(carta.second);

		conexos.push_back(primero);
		cuenta.push_back(1);

		while(!mano.empty()){
			carta = mano.top();
			mano.pop();
			unsigned int j = 0;
			while(j < conexos.size()){
				if(carta.first == *conexos[j].find(carta.first) || carta.second == *conexos[j].find(carta.second)){
					conexos[j].insert(carta.first);
					conexos[j].insert(carta.second);
					cuenta[j]++;
					break;
				}
				j++;

				// 1 1  1 3  4 4  4 4
				// Posible error de esta manera
				/*
				j++;
				if(j == conexos.size()-1){
					set<int> nuevo;
					nuevo.insert(carta.first);
					nuevo.insert(carta.second);
					conexos.push_back(nuevo);
					cuenta.push_back(1);
					break;
				}
				*/
			}
			if (j==conexos.size()){
				set<int> nuevo;
				nuevo.insert(carta.first);
				nuevo.insert(carta.second);
				conexos.push_back(nuevo);
				cuenta.push_back(1);
			}
		}

		/*
		std::set<int>::iterator it;
		forn (i, conexos.size()){
			cout<<"Conexos ";

			for (it=conexos[i].begin(); it!=conexos[i].end(); ++it){
    		cout  << *it<<", ";
			}
			cout<<" Cuenta "<<cuenta[i]<<endl;

		}
		*/
		bool todos_bien = true;
		forn(i, cuenta.size()){
			if(cuenta[i] > conexos[i].size()){
				todos_bien = false;
				break;
			}
		}
		todos_bien ? (cout << "possible") : (cout << "impossible");
		cout << endl;

	}
	return 0;
}
