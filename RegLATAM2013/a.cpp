#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define fst first
#define snd second

using namespace std;

#define N 20000

int out_match[N];
int in_match[N];
vector< vector<int> > adj;
bool visited[2*N];

int find_match(int source) { 
	int from[N], where, match;
	memset(from, -1, sizeof(from));
	from[source] = source; 
	queue<int> q;
	q.push(source); 
	bool found_path = false; 
	while (!found_path and !q.empty()) {

		where = q.front(); q.pop();
		forn(i, adj[where].size()) {
			match = adj[where][i];
			int next = in_match[match];
			if (where != next) {
				if (next == -1) {
					found_path = true;
					break;
				}

				if (from[next] == -1) {
					q.push(next);
					from[next] = where;
				}
			}
		}
	}

	if (!found_path) return 0;
	while (from[where] != where) {
		int aux = out_match[where];
		out_match[where] = match;
		in_match[match] = where;
		where = from[where];
		match = aux;
	}

	out_match[where] = match;
	in_match[match] = where;
	return 1;
}


int get_match(int n) {
	int m = 0;
	forn(i,n) m += find_match(i);
	return m;
}

int main() {
	long n;

	while(cin >> n) {
		string s;
		vector<vector<int>> map(n);

		forn(i,N) {
			out_match[i] = -1;
			in_match[i] = -1;
			visited[2*i] = false;
			visited[2*i + 1] = false;
		}

		forn(y,n) {
			cin >> s;
			map[y].reserve(n);
			forn(x,n) {
				map[y][x] = s[x] == '.' ? 0 : -1;
			}
		}

		int rows = 0;
		int cols = 0;

		forn(y,n) {
			int r = rows;
			forn(x,n) {
				if(map[y][x] != -1) {
					rows = r+1;
					map[y][x] = r;
				} else {
					r = rows;
				}
			}
		}

		//cerr << rows << " rows " << endl;

		adj = vector<vector<int>>(rows);
		forn(x,n) {
			int c = cols;
			forn(y,n) {
				if(map[y][x] != -1) {
					cols = c+1;
					//cerr << "col " << c << " - row " << map[y][x] << endl; 
					adj[map[y][x]].pb(c+rows);
				} else {
					c = cols;
				}
			}
		}

		adj.resize(rows+cols);
		forn(i,rows) {
			for(auto j : adj[i]) {
				adj[j].pb(i);
			}
		}

		cout << get_match(rows) << endl;
	}

	return 0;
}