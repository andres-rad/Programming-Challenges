#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

struct RMQ{
	#define LVL 10
	tipo vec[LVL][1<<(LVL+1)];
	tipo &operator[](int p){return vec[0][p];}

	tipo get(int i, int j){
		int p=31-__builtin_clz(j-i);
		return operacion
	}
};

int main() {

	return 0;
}