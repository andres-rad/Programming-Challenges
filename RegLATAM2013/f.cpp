#include <bits/stdc++.h>
#define forsn(i,s,n) for(long i = s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second

using namespace std;

int main() {
	long n,g;

	while(cin >> n) {
		long points = 0;
		long empat = 0;
		priority_queue<long> perd;

		cin >> g;

		forn(i,n) {
			long s,r;
			cin >> s >> r;

			if(s>r){
				points += 3;
			} else if(s == r) {
				points++;
				empat++;
			} else {
				perd.push(s-r);
			}
			
		}

		long p = min(empat, g);
		points += p * 2;
		empat -= p;
		g -= p;

		while(g > 0 and perd.size()) {
			long a = -perd.top();
			perd.pop();

			if(g > a) {
				points += 3;
				g -= a+1;
			} else if(g == a) {
				points += 1;
				g = 0;
			} else {
				g = 0;
			}
		}

		cout << points << endl;
	}


	return 0;
}