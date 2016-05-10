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

				if (contiene[adj[v][i]] == 1) {
					
					if (adj[v][i] == N-1) {
						cout << 'Y';
						return true;
					} else {
						contiene[llaves[adj[v][i]]] = 2;
						contiene[adj[v][i]] = 2;
						bfsq.push(adj[v][i]);
						visitado[adj[v][i]] = true;
					}
				} else if (contiene[adj[v][i]] == 2) {
					if (adj[v][i] == N-1) { 
						cout << 'Y';
						return true;
					} else {
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

	cin >> N >> K >> M;

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

	while (c_contiene != contiene) {
		if (bfsq(N, llaves, adj, contiene)) {
			break;
		}
		c_contiene = contiene;
	}

	if (!bfsq(N, llaves, adj, contiene)) {
		cout << 'N';
	}

	return 0;
}