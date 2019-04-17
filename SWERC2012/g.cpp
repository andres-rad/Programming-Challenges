#include <bits/stdc++.h>

using namespace std;

#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;
#define sz(C) ((tint) C.size())

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int d, p, temp;

	while (cin >> d >> p) {
		string s;
		bool end = false;
		vector<int> seq;
	
		getline(cin, s);
		istringstream stream(s);
	
		while(stream >> temp) {
			seq.pb(temp);
		}

		if (seq[0] > p) {
			cout << "The spider is going to fall!" << endl;
			continue;
		}

		if (seq.size() >= d + 1) {
		
			forn (i, d+1) {
				if (seq[i] > p) {
					cout << d - i + 1 << endl;
					end = true;
					break;
				}
			}
			if (end) {
				continue;
			}

			cout << "The spider may fall!" << endl;
		
		} else {

			forn (i, seq.size()) {
				if (seq[i] > p) {
					cout << d - i + 1 << endl;
					end = true;
					break;
				}
				if (end) continue;
			}

			// double a, b, x0, x1, temp;
			tint a, b, x0, x1, temp, divi;

			if (seq[1] != 0) {
				//while(seq[1]*seq[1] - seq[0] * seq[2] == 0);
			
				// a = (double)(seq[3]*seq[1] - seq[2]) / (double)(seq[1]*seq[1] - seq[0]);
				// b = (double)(seq[2] - a*seq[0]) / (double)seq[1];
			

				a = (seq[3] * seq[1] - seq[2] * seq[2]);
				b = (seq[2] * (seq[1]*seq[1] - seq[0] * seq[2]) - a * seq[0]);
				a *= seq[1];
				divi = (seq[1] * seq[1] - seq[0] * seq[2]) * seq[1];
				debug(a);
				debug(b);
				debug(divi);
			} else {
			
				cout << "The spider may fall!" << endl;
				continue;
			
			}

			x0 = seq[2];
			x1 = seq[3];

			tint ddivi = divi;

			forsn(i, 4, d + 1) {
			
				temp = a*x0 + b*x1;
			
				// if (round(temp) > p) {
				if(temp > ddivi * p){
					cout << d - i + 1 << endl;
					end = true;
					break;
				}
			
				x0 = ddivi * x1;
				x1 = temp;

				ddivi = ddivi * divi;
			}

			if (!end) {
				cout << "The spider may fall!" << endl;
			}
		}
	}	
	return 0;
}