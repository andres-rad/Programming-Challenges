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

typedef long long int tint;

int agujeros(char c){
	if(c == 'B'){
		return 2;
	} else if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R') { 
		return 1; 
		}
	return 0;
}

int main(){
	char letra;
	int regiones = 0;
	while(cin >> letra){
		regiones += agujeros(letra);
	}
	cout << regiones << endl;
	return 0;
}
