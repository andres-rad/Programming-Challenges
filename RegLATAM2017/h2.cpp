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
	int a1, a2, a3, b1, b2 , b3;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	cout << max(0, b1-a1) + max(0, b2 - a2) + max(0, b3 - a3) << endl;
	return 0;
}
