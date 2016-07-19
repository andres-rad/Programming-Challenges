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

int main(){
	int casos;
	int caso=0;
	cin >> casos;
	while(caso < casos){
		caso++;
		int E,F,C;
		cin >> E >> F >> C;
		if(C == 1 && (E > 0 || F > 0)){
			cout << 0 << "\n";
		}
		else{
			int rec = E + F;
			int tomadas = 0;
			while(rec/C > 0){
				//cout << "h" << tomadas<<" "<<resto+rec<<endl;
				tomadas += (rec)/C;
				rec = (rec)/C + (rec % C);
			}
			cout << tomadas << "\n";
		}
	}
	return 0;
}
