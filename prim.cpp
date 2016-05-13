// prim.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool bfsq(int N, const vector<int> &llaves, const vector<vector<int> > &adj, vector<int> &contiene) {

	queue<int> bfsq;
	vector<bool> visitado(N, false);
	bfsq.push(0);
	visitado[0] = true;

	bool ans=false;

	while (!bfsq.empty()) {

		int v = bfsq.front();
		bfsq.pop();





		for (int i = 0; i < adj[v].size(); i++) {

			if (adj[v][i] == N-1) ans=true;

			if (!visitado[adj[v][i]]) {

				if (contiene[adj[v][i]] == 1) {

						contiene[llaves[adj[v][i]]] = 2;
						contiene[adj[v][i]] = 2;
						bfsq.push(adj[v][i]);
						visitado[adj[v][i]] = true;

						if (visitado[llaves[adj[v][i]]]){
							bfsq.push(llaves[adj[v][i]]);
							visitado[llaves[adj[v][i]]] = false;
						}

				} else if (contiene[adj[v][i]] == 2) {

						bfsq.push(adj[v][i]);
						visitado[adj[v][i]] = true;

				} else if (contiene[adj[v][i]] == 0){
						visitado[adj[v][i]] = true;
				}
			}
		}
	}
	return ans;
}


int main() {

	int N;
	int K;
	int M;

	while(cin >> N >> K >> M){

		if (N == -1) {
			return 0;
		}

		vector<vector<int> > adj(N);

		//contiene[i] -> 0 = puerta cerrada, 1 = llave, 2 = nada
		vector<int> contiene(N, 2);
		// llave[i] = j -> la llave en el nodo i abre la puerta en el nodo j
		vector<int> llaves(N, -1);

		for (int i = 0; i < K; i++) {

			int a, b;
			cin >> a >> b;
			a--;
			b--;

			contiene[a] = 1;
			contiene[b] = 0;
			llaves[a] = b;

		}

		for (int i = 0; i < M; i++) {

			int n1;
			int n2;
			cin >> n1 >> n2;
			n1--;
			n2--;
			adj[n1].push_back(n2);
			adj[n2].push_back(n1);

		}

		if (bfsq(N, llaves, adj, contiene)){
			cout<<"Y"<<endl;

		}
		else{
			cout<<"N"<<endl;
		}
		//Va a guardar el estado del grafo antes de recorrerlo para comparar
		/*vector<int> c_contiene;

		while (c_contiene != contiene) {
			if (bfsq(N, llaves, adj, contiene)) {
				break;
			}
			c_contiene = contiene;
		}

		if (!bfsq(N, llaves, adj, contiene)) {
			cout << 'N';
		}*/
	}
	return 0;
}
