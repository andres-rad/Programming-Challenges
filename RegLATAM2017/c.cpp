#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define first fst
#define second snd
#define push_back pb
#define make_pair mp
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif
  
int main(){
	int k, n;
	cin >> k >> n;
	vector<int> app (k, 0);
	forn(i, n){
		int t;
		cin >> t;
		app[t-1]++;
	}
	
	int mini = 0, maxi = 0;
	
	forn(i, k){
		if (app[i] <= app[mini]) mini = i;
		if (app[i] >= app[maxi]) maxi = i;
	
	}
	
	debug(mini);
	debug(maxi);
	debug(app[mini]);
	debug(app[maxi]);
	
	if (app[maxi] - app[mini] > 2){
		cout << '*' << endl;
		return 0;
	}
	
	int check = 0;
	while (check == mini or check == maxi){
		check++;
	}
	debug(check);
	debug(app[check]);
	
	if (app[maxi]-1 == app[check] and app[mini]+1 == app[check]){
		app[maxi]--;
		app[mini]++;
		forn (i, k){
			if (app[i] != app[check]){
				cout << '*' << endl;
				return 0;
			}
		}
		cout << "-" << maxi+1 << " +" << mini+1 << endl;
		return 0;
	}else if (app[maxi]-1 == app[check]){
		app[maxi]--;
		//app[mini]--;
		forn (i, k){
			if (app[i] != app[check]){
				cout << '*' << endl;
				return 0;
			}
		}
		cout << "-" << maxi+1 << endl;
		return 0;
	}else if (app[mini]+1 == app[check]){
		//app[maxi]--;
		app[mini]++;
		forn (i, k){
			if (app[i] != app[check]){
				cout << '*' << endl;
				return 0;
			}
		}
		cout << "+" << mini+1 << endl;
		return 0;
	}
	
	cout << "*" << endl;
	
	return 0;
}
