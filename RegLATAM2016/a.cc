#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)

using namespace std;

int main() {

	vector<int> v(4);

	cin >> v[0] >> v[1] >> v[2] >> v[3];

	sort(v.begin(), v.end());

	cout << abs((v[0]+v[3] - v[1] - v[2])) << endl;


	return 0;
}