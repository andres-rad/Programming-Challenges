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
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

struct app{
	int mensajes;
	vector <int> posiciones;
	int ultimoLeido;

};

struct notif{
	int app;
	bool leido;
};

int main(){


	int n,q;

	cin>>n>>q;

	app temp;
	temp.mensajes=0;
	temp.ultimoLeido=0;

	vector<app> apps(n+1,temp);

	vector<notif> notificaciones;
	int ultinotif=0;

	int sinleer=0;

	while (q>0){
		q--;

		int tipo, param;

		cin>>tipo>>param;

		if (tipo==1){
			notif temp;
			temp.leido=false;
			temp.app=param;
			apps[param].mensajes++;
			apps[param].posiciones.pb(notificaciones.size());
			notificaciones.pb(temp);
			sinleer++;
		}else if (tipo==2){

			int cnt=0;
			while (apps[param].ultimoLeido<apps[param].mensajes){
				if (!notificaciones[apps[param].posiciones[apps[param].ultimoLeido]].leido){
					cnt++;
					notificaciones[apps[param].posiciones[apps[param].ultimoLeido]].leido=true;
				}

				apps[param].ultimoLeido++;
			}
			sinleer=sinleer-cnt;
		}else if (tipo==3){
			int cnt=0;
			while (ultinotif<notificaciones.size() && ultinotif<param){
				if (!notificaciones[ultinotif].leido){
					notificaciones[ultinotif].leido=true;
					cnt++;
				}
				ultinotif++;
			}

			sinleer=sinleer-cnt;
		}

		cout<<sinleer<<endl;
	}

	return 0;
}
