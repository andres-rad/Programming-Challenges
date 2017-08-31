#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back

std::vector<int> _cl;
int cl(int i){return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i]))}
void join (int i, int j){ if (cl(i) != cl(j)) _cl[cl(i)] = cl(j);}
void ini (int n) {_cl.clear(); _cl.insert(_cl.begin(), n, -1);}
int main() {

	int n;
	while (cin>>n){
		forn(i, 2*n){
			forn(j, 2*n + 1){
				
			}
		}
	}
	return 0;
}