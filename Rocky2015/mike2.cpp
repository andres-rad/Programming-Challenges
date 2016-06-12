#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair

//UNION FIND
vector<int> _cl;
int cl(int i) { return (_cl[i] == -1 ? i : _cl[i] = cl(_cl[i])); }
void join(int i, int j) { if(cl(i)!=cl(j)) _cl[cl(i)] = cl(j); }
void ini(int n) { _cl.clear(); _cl.insert(_cl.begin(), n, -1); }

int main () {

	int t=0, tests;
	cin>>tests;

	while (t<tests){
		t++;


		int p,q;
		int n;
		cin>>n;

		ini(2*n+1);

		/*
		if(n==0){
			cout << "possible" << endl;
		}
		else{} */
		// n es mayor igual a 1

		vector<int> cuenta(n+2,0);
		vector<int> tam(2*n+1,1);
		int maxi=0;
		forn (i,n){
			cin>>p>>q;
			maxi=max(maxi,max(p,q));
			int clp=cl(p), clq=cl(q);
			//cout<<"CLP "<<clp<<" CLQ "<<clq<<endl;
			int temp=cuenta[clp]+cuenta[clq]+1;
			if (clp==clq) temp=cuenta[clp]+1;
			cuenta[clp]=0;
			cuenta[clq]=0;

			int temp2=tam[clp]+tam[clq];
			if (clp==clq) temp2=tam[clp];
			tam[clp]=0;
			tam[clq]=0;

			join(p,q);
			//cout<<"JOIN "<<p<<q<<endl;
			cuenta[cl(p)]=temp;
			tam[cl(p)]=temp2;

		}

		/*forn (i,maxi){
			cout<<"Clase "<<cl(i+1)<<" Cuenta "<<cuenta[cl(i+1)]<<" TAM "<<tam[cl(i+1)]<<endl;
		}*/

		/*
		std::set<int>::iterator it;
		forn (i, conexos.size()){
			cout<<"Conexos ";

			for (it=conexos[i].begin(); it!=conexos[i].end(); ++it){
    		cout  << *it<<", ";
			}
			cout<<" Cuenta "<<cuenta[i]<<endl;

		}
		*/
		bool todos_bien = true;
		forn(i, maxi){
			if(cuenta[cl(i+1)] > tam[cl(i+1)]){
				todos_bien = false;
				break;
			}
		}
		todos_bien ? (cout << "possible") : (cout << "impossible");
		cout << endl;

	}
	return 0;
}
