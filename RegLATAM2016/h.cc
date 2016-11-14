#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {
	int n,k;

	cin >> n >> k;

	priority_queue<int,vector<int>,greater<int>> v;

	int res = 0;
	int acum = 0;

	forn(i,n)  {
		int a;
		cin >> a;

		v.push(a);
		acum++;

		if(i % (k+1) != k) {
			res += v.top();
			//cerr << i << " " << v.top() << endl;
			v.pop();
		} else {
			acum -= k;
		}
		//cerr << "- " << acum << endl;
	}

	cout << res << endl;

	return 0;
}