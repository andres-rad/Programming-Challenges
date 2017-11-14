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
int cl(int i){return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i]));}
void join (int i, int j){ if (cl(i) != cl(j)) _cl[cl(i)] = cl(j);}
void ini (int n) {_cl.clear(); _cl.insert(_cl.begin(), n, -1);}

int id (int a, int b){return a+603*b;}

vector<vector<char> > sent;
int main() {

	int n;
	while (cin>>n){
		//debug(n);
		ini(id(610, 610));

		sent = vector<vector<char> > ( 2*n+1 , vector<char> (2*n+1, ' '));

		forn(i, 2*n - 1){
			forn(j, n){
				int temp = (i%2 ? 2*(1+j)-1 : 2*(1+j)-2 );
				cin>>sent[i][temp];
				//debug(i); debug(temp);
				//debug(sent[i][temp]);
			}
		}

		forn(i, 2*n ){
			forn(j, 2*n + 1){
				if ((i+j)%2){
					if (j<2*n && (i==0 || sent[i-1][j] == 'H'))
						join(id(i,j), id(i, j+1));
					if (i<2*n - 1 && (j==0 || sent[i][(j-1)] == 'V'))
						join(id(i,j), id(i+1, j));
				}else{
					if (j<2*n && (sent[i][j] == 'H' or sent[i][j] == ' '))
						join(id(i,j), id(i, j+1));
					if (i<2*n - 1 && (sent[i][j] == 'V' or sent[i][j] == ' '))
						join(id(i,j), id(i+1, j));
				}


			}
		}

		set<int> res;

		forn(i, 2*n){
			forn(j, 2*n + 1){
				//debug(i);
				//debug(j);
				//debug(cl(id(i, j)));
				res.insert(cl(id(i, j)));

			}
		}

		cout<<((int) res.size()) - 1<<endl;
	}
	return 0;
}
