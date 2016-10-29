#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) for(int i = n; i >= 0; i--)
#define pb push_back

int main() {

	int cartas[5] = {1, 10, 100, 1000, 10000};
	int n, m;		
	while(cin >> n){
		cin >> m;
		int res = 0;
		forn(i,m){
			int B, daed;
			cin >> B >> daed;
			forn(j, n-1){
				int carta;
				cin >> carta;
				B -= carta;
			}
		
			if(B-daed < 0){
				dforn(j, 4){
					if(cartas[j] < daed && B - cartas[j] >= 0){
						res += cartas[j];
						break;
					}
				}
			}
			else{
				dforn(j, 4){
					if(cartas[j]>daed && B-cartas[j] >= 0){
						res += cartas[j]-daed;
						break;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}