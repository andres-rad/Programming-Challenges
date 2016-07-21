#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cassert>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

struct jugador{
	string nombre;
	int elo;
	double w;
	double we;
	int k;
};

int main(){
	string torneo;
	cin >> torneo;
	int n;
	cin >> n;
	vector<jugador> part;
	int media = 0;
	forn(i,n){
		string nombre;
		jugador temp;
		int elo;
		double w;
		double we;
		int k;
		cin >> nombre >> elo >> w >> we >> k;
		temp.nombre=nombre;
		temp.elo=elo;
		temp.w=w;
		temp.we=we;
		temp.k=k;
		part.pb(temp);
		media+=elo;
	} 
	media=round((double)media/n);
	forn(i,n){
		part[i].elo += round((double)part[i].k*(part[i].w-part[i].we));
	}
	cout << "Tournament: " << torneo << "\n";
	cout << "Number of players: " << n << "\n";
	cout << "New ratings:" << "\n";
	forn(i,n){
		cout << part[i].nombre << " " << part[i].elo << "\n";
	}
	cout << (int)media << "\n";
	
	return 0;
}
