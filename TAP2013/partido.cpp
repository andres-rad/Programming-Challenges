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
	long N, F, A, B, C, M;
	cin >> N >> F;
	cin >> A >> B >> C;
	cin >> M;

	vector<set<long>> eqs (F);
	vector<long> act (N);

	// gen
	long last = A;
	eqs[A].insert(0);
	act[0] = A;
	for(int i = 1; i < N ; i++) {
		last = ((long long) B * (long long)last + (long long)C)
					% (long long)F;
		
		eqs[last].insert(i);
		act[i] = last;

		//cout << last << " ";
	}
	//cout << endl << endl;

	// mudar

	forn(mud, M){
		long pos, e;
		cin >> pos >> e;
		pos--;

		// borrar
		eqs[act[pos]].erase(eqs[act[pos]].find(pos));

		auto it = eqs[e].insert(pos).first;
		act[pos] = e;

		//cout << "en eqs[e] " << eqs[e].size() << endl;
		//cout << "valor it " << *it << endl;
		//cout << "valor begin " << *eqs[e].begin() << endl;


		if(it != eqs[e].begin()) {
			it--;
			cout << (pos - *it);
			it++;
		} else {
			auto ite = eqs[e].end();
			//cout << "ite " << *ite << endl;
			ite--;
			cout << (N + pos - *ite);
		}

		cout << " ";

		it++;
		if(it != eqs[e].end()) {
			cout << (*it - pos);
		} else {
			auto ite = eqs[e].begin();
			cout << (N + *ite - pos);
		}

		cout << endl;
	}

	return 0;
}