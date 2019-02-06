#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define sq(x) ((x) * (x))
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define EPS 1e-10

using namespace std;
typedef pair<int,int> par;
typedef long long int tint;

struct pair_hash
{
	std::size_t operator () (par const &p) const
	{
		std::size_t h1 = std::hash<int>()(p.first);
		std::size_t h2 = std::hash<int>()(p.second);

		return (h1 * 35 + h2);
	}
};

int dp[510][510]; 
// dp[i][j] = maxima cantidad de jugglers si hay i cadenas azules y j rojas. Llamo a esto estado (i,j)
par p[510][510];
// p[i][j] = "padre" del estado (i,j). Apunta al estado (k,l) anterior a (i,j) en una cadena optima. Eso implica haber agregado el par (i-k,j-l)
//            para pasar de (k,l) a (i,j) o simplemente ignorar el excedente y usar solo las cadenas del estado (k,l). Depende de a.
bool a[510][510];
// a[i][j] = true si y solo si para pasar del estado (k,l) = p[i][j] a (i,j) hay que agregar el par (i-k,j-l)

//unordered_set< par, pair_hash > used[510][510];

int main()
{
	int t,r,b;

	cin >> t;

	int B = 501; int R = 501;
	
	// inicializo dp en la fila 0 y la columna 0. Si hay una sola dimension las unicas transiciones interesantes van a ocurrir en los numeros
	// triangulares, es decir, en los numeros x de la pinta x = n * (n + 1) / 2 para algun n.

	dp[0][0];
	p[0][0] = mp(-1,-1);
	a[0][0] = false;
	forsn(i,1,B)
	{
		int prev = dp[i-1][0];
		dp[i][0] = prev;
		a[i][0] = false;
		p[i][0] = p[i-1][0];
		//unordered_set< par, pair_hash >:: iterator it;
		//for(it = used[i-1][0].begin(); it != used[i-1][0].end(); it++)
		//	used[i][0].insert(*it);
		int tot = ( (prev) * (prev + 1) ) / 2;
		if(i - tot >= (prev + 1))
		{
			dp[i][0]++;
			a[i][0] = true;
			p[i][0] = mp(i - (prev + 1), 0);
			//used[i][0].insert(mp(prev+1,0));
		}
	}
	forsn(j,1,R)
	{
		int prev = dp[0][j-1];
		dp[0][j] = prev;
		a[0][j] = false;
		p[0][j] = p[0][j-1];
		//unordered_set< par, pair_hash >:: iterator it;
		//for(it = used[0][j-1].begin(); it != used[0][j-1].end(); it++)
		//	used[0][j].insert(*it);
		int tot = ( (prev) * (prev + 1) ) / 2;
		if(j - tot >= (prev + 1))
		{
			dp[0][j]++;
			a[0][j] = true;
			p[0][j] = mp(0, j - (prev + 1));
			//used[0][j].insert(mp(0,prev+1));
		}
	}

	/*
	forsn(i,1,B)
	{
		cout << i << " : " << dp[i][0] << " (" << p[i][0].f <<  "; " << p[i][0].s << ") " << a[i][0] << endl;
	}
	*/


	// Lleno solo B >= R
	
	forsn(i,1,B)
	{
		forsn(j,1,i+1)
		{
			int blue_opt = -1; int red_opt = -1;
			int best = -1; bool add = false;

			forn(k, min(35,i+1))
			{
				forn(l, min(35,j+1))
				{
					if(k == 0 and l == 0) continue;

					par cand = mp(k,l);
					par cur = mp(i - k, j - l);

					if((dp[i-k][j-l] + 1) <= best) continue; // no hay posibilidad de mejorar y ahorramos iteraciones

					bool in = false;

					// posibilidades: para pasar de (i - k, j - l) conviene agregar (k,l) o no. Depende de si (k,l) pertenece a la cadena optima
					// del estado (i - k, j - l). Para chequear esto, con el while recorro la cadena optima de (i - k, j - l)

					while(cur.f >= 0)
					{
						par next = p[cur.f][cur.s];
						par moved = mp(cur.f - next.f, cur.s - next.s);
						if(a[cur.f][cur.s])
						{
							if(moved == cand)
							{
								in = true;
								break;
							}
						}
						cur = next;
					}

					if(!in)
					{
						if((dp[i-k][j-l] + 1) > best)
						{
							best = dp[i-k][j-l] + 1;
							blue_opt = k;
							red_opt = l;
							add = true;
						}
					}
					else
					{
						if(dp[i-k][j-l] > best)
						{
							best = dp[i-k][j-l];
							blue_opt = k;
							red_opt = l;
							add = false;
						}
					}

					/*
					if( used[i-k][j-l].find(cand) == used[i-k][j-l].end() )
					{
						if((dp[i-k][j-l] + 1) > best)
						{
							best = dp[i-k][j-l] + 1;
							blue_opt = k;
							red_opt = l;
							add = true;
						}
					}
					else
					{
						if(dp[i-k][j-l] > best)
						{
							best = dp[i-k][j-l];
							blue_opt = k;
							red_opt = l;
							add = false;
						}
					}
					*/
				}
			}

			int k = blue_opt; int l = red_opt;

			//unordered_set< par, pair_hash >:: iterator it;
			//for(it = used[i-k][j-l].begin(); it != used[i-k][j-l].end(); it++)
			//	used[i][j].insert(*it);

			dp[i][j] = best;
			p[i][j] = mp(i - k, j - l);

			if(add)
			{
				a[i][j] = true;
				//used[i][j].insert(mp(k,l));
			}

			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}

	forsn(caso,1,t+1)
	{
		cin >> r >> b;
		if(r < b) swap(r,b);
		cout << "Case #" << caso << ": " << dp[r][b] << endl;
	}

	return 0;
}