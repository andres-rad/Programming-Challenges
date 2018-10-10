#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define debug(v) //cerr << #v << ": " << (v) << endl
#define fst first
#define snd second
typedef long long tint;

pair<int, int> grid[4010][4010];

int main() {
	int n;

	while (cin >> n){
	forn(i, 4010) forn(j, 4010) {
		grid[i][j].fst = 0;
		grid[i][j].snd = 0;
	}
	
	forn(i, n){
		char type;
		int x, y, a;
		cin >> type >> x >> y >> a;
		x+=2005; y+=2005;
		if (type == 'A'){
			grid[x-a/2][y-a/2].fst = a;
		}else{
			debug("type b");
			grid[x][y-a/2].snd = a;
		}
		
	}



	forsn(j, 2, 4008){
		forsn(i, 2, 4008){

			if (grid[i][j].fst){
				debug("fst");
				debug(i-2005);
				debug(j-2005);
				grid[i+1][j].fst = max(grid[i+1][j].fst, grid[i][j].fst - 1);
				grid[i+1][j+1].fst = max(grid[i+1][j+1].fst, grid[i][j].fst - 1);
				grid[i][j+1].fst = max(grid[i][j+1].fst, grid[i][j].fst - 1);
			}
			if (grid[i][j].snd){
				debug("snd");
				debug(i-2005);
				debug(j-2005);
				grid[i+1][j+1].snd = max(grid[i+1][j+1].snd, grid[i][j].snd - 2);
				grid[i-1][j+1].snd = max(grid[i-1][j+1].snd, grid[i][j].snd - 2);
				grid[i][j+2].snd = max(grid[i][j+2].snd, grid[i][j].snd - 2);
			}
		}
	}
	tint cnt = 0;
	debug(cnt);

	forsn(i, 1, 4009) forsn(j, 1, 4009){
		int t1, t2, t3, t4;
			t1 = t2 = t3 = t4 = 0;
		if (grid[i][j].fst){
			// debug("fst");
			t1 = t2 = t3 = t4 = 1;
		}else{
			if (grid[i][j].snd){
				t1 = t4 = 1;
			}
			if (grid[i+1][j].snd){
				t1 = t2 = 1;
			}
			if (grid[i][j-1].snd){
				t3 = t4 = 1;
			}
			if (grid[i+1][j-1].snd){
				t2 = t3 = 1;
			}

		}

		cnt += t1 + t2 + t3 + t4;
		// debug(cnt);
	}	

	debug(cnt);

	cout << fixed << setprecision(2) << ((double) cnt) / 4.0 << '\n';
}
	return 0;
}