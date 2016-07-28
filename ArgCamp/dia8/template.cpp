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
#include <sstream>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

using namespace std;

typedef long long int tint;

int MP = (int) (1e6);

int CANT = 78498;

int primo[78498];

void criba(){
	int maxsqrt = (int)(sqrt(double(MP)));
	maxsqrt++;
	bool *esPrimo = new bool[MP+1];
	memset(esPrimo, true, sizeof(bool)*(MP+1));
	int cont = 1; int k,m;
	primo[0] = 2;
	for(m = 3;m <= maxsqrt; m+=2){
		if(esPrimo[m]){
			primo[cont] = m;
			cont++;
			for(k = m*m; k <= MP; k += m) esPrimo[k] = false;
		}
	}
	if(maxsqrt % 2 == 0) maxsqrt++;
	for(int j = maxsqrt+2; j <= MP; j += 2){
		if(esPrimo[j]){
			primo[cont] = j;
			cont++;
		}
	}
}

int main(){
	string n;
	cin >> n;
	string nn;
	int contador = 0;
	while(n != "0"){
		contador++;
		nn = n;
		sort(nn.begin(), nn.end());
		tint a, b;
		a = stoll(n);
		b = stoll(nn);
		tint c = b - a;
		n = to_string(c);
	}
	cout << contador << '\n';
	
	return 0;
}
