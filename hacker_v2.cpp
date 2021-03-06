// Example program
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

vector<pair <int, int> > prim( vector<vector<pair<int, int> > > ady, int N){

  pair<int, int> init = make_pair(-1, -1);
	vector<pair<int, int> > arbol(N, init);
	vector<int> visitado(N, 0);

	//Esta parte de mierda estaria rompiendo todo, quiero una estructura de datos que sea < <peso12, nodo1>, nodo2> y ordenar por peso.
	priority_queue < pair<pair<int,int> , int>, vector<pair<pair<int,int> , int> >, less<pair<pair<int,int> , int> >() > cola;

	arbol[0].first = -1;
	arbol[0].second = 0;
	visitado[0] = 1;

	for (int i = 0; i < ady.size(); i++) {

		cola.push(make_pair(ady[0][i], 0));
	}

	while(!cola.empty()){

		int current = cola.top().first.second;

		if (!visitado[current]) {

			arbol[current].second = cola.top().second;
			arbol[current].first  = cola.top().first.first;
			visitado[current] = 1;

			for (int j = 0; j < ady[current].size(); j++){
				cola.push( make_pair(ady[current][j], j) );
			}
		}

		cola.pop();

	}



	return arbol;
}


void maximoPeso(int S, int T, vector<pair<int, int> > arbol){

	int maximo;

	while(arbol[S].first != arbol[T].first){
		maximo = max(arbol[S].second, arbol[T].second);
		S = arbol[S].first;
		T = arbol[T].first;
	}

	cout << maximo << ' ';
	return;

}

int main(){

	int C,L,H;


	while (cin >> C >> L >> H){

		if (C == -1) return 0;

		vector<vector<pair <int, int> > > ady;

		ady.resize(C);

		for (int i = 0; i < L; i++){

			int A, B, V;
			cin >> A >> B >> V;

			ady[A].push_back(make_pair(V, B));
			ady[B].push_back(make_pair(V, A));


		}

		vector<pair<int, int> > mst(prim(ady, C));

		for (int i = 0; i < H; i++){
			int S, T;
			cin >> S >> T;

			maximoPeso(S, T, mst);
		}

		cout << endl;
	}



	return 0;
}
