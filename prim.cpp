// prim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool bfsq(int N, const vector<int> &llaves, const vector<vector<int>> &adj, vector<int> &contiene) {

	queue<int> bfsq;
	vector<bool> visitado(N, false);
	bfsq.push(0);
	visitado[0] = true;

	while (!bfsq.empty()) {

		int v = bfsq.front();
		bfsq.pop();

		for (int i = 0; i < adj[v].size(); i++) {

			if (!visitado[adj[v][i]]) {

				if (adj[v][i] == N-1) {
					cout << 'Y' << endl;
					return true;
				}

				if (contiene[adj[v][i]] == 1) {

						contiene[llaves[adj[v][i]]] = 2;
						contiene[adj[v][i]] = 2;
						bfsq.push(adj[v][i]);
						visitado[adj[v][i]] = true;
					}
				} else (contiene[adj[v][i]] == 2) {
						bfsq.push(adj[v][i]);
						visitado[adj[v][i]] = true;
					}
				}
			}
		}
	}
	return false;
}


int main() {

	int N;
	int K;
	int M;

	while(cin >> N >> K >> M){

		if (N == -1) {
			return 0;
		}

		vector<vector<int>> adj(N);

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
		//Va a guardar el estado del grafo antes de recorrerlo para comparar
		vector<int> c_contiene;
		bool progreso = false;

		while (c_contiene != contiene) {
			c_contiene = contiene;
			progreso = bfsq(N, llaves, adj, contiene);
			if (progreso) {
				break;
			}
		}

		if (!progreso) {
			cout << 'N' << endl;
		}
	}
	return 0;
}
