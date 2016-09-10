#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "unordered_map"
#include "iostream"
#include "cstring"
#include "stdlib.h"


#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair
#define umap unordered_map

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	
	int n;

	while(cin >> n){
		int r;

		cin >> r;

		vector<int> types(n+1);
		unordered_map<int,set<int>> unions;

		forn(i,n) {
			int t;
			cin >> t;
			types[i+1] = t;
			unions[t].insert(i+1);
		}

		forn(i,r) {
			char q;
			cin >> q;

			if(q == 'C') {
				int k,s;
				cin >> k >> s;

				int t = types[k];

				if(s == t) continue;

				auto it = unions[t].find(k);
				unions[s].insert(k);
				types[k] = s;

			} else {
				int k;
				cin >> k;

				int meters = 0;
				int low = 0;

				while(k>low) {
					int t = types[k];

					if(k != *unions[t].begin()) {
						auto it = unions[t].find(k);
						it--;
						low = max(low, *it);
					}

					meters++;
					k--;
				}

				cout << meters << endl;
			}
		}
	}

	return 0;

}
