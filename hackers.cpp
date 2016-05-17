#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define MAX 10**9+20

struct node{

	vector<pair<int,int> > adj;
};

//node nodes[3003];

void prim (node nod[]){
	vector<pair<int,int> > padre;
	padre.resize(3003,make_pair(0,-1));
	//vector<int> pesoMin;
	//pesoMin.resize(3003,MAX);

	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > que;
	int visitada[3003]={0};

	int curr=1;
	//visitada[1]=1;
	que.push(make_pair(0,curr));

	while (!que.empty()){

		pair<int,int> current=que.top();
		que.pop();
		visitada[current.second]=1;

		if (!visitada[current.second]==0){
			for (int i =0; i<nod[current.second].adj.size();i++){
				//int w =nod[curr].adj[i].first;
				//int n =nod[curr].adj[i].second;
				//if (w<pesoMin[n]) pesoMin[n]=w
				padre [nod[current.second].adj[i].second]=current;
				cout<<"curr  "<<nod[current.second].adj[i].first<<"  "<<nod[current.second].adj[i].second<<endl;

				que.push(nod[current.second].adj[i]);
				//nod[current.second].adj.erase(i);
				//visitada[nod[current.second].adj[i].second]=1;
			}
		}
	}

	forn (j,3001){
		nod[j].adj.clear();
	}

	forn (i,3001){
		//cout<<"ciclo"<<endl;
		if (padre[i].second!=-1){
			cout<<"if"<<endl;
			nod[i].adj.pb(padre[i]);
			nod[padre[i].second].adj.pb(mp(padre[i].first,i));
		}
	}



	return;
}

int recorre(int s, int t, node nod[], int maxim){

	int maxi=0;
	if (s==t) return maxim;

	forn(i, nod[s].adj.size()){



		maxi=max(maxi, recorre(nod[s].adj[i].second,t,nod,max(maxim,nod[s].adj[i].first )));
	}

	return maxi;

}

int main(){
	int c,l,h;

	cin>>c>>l>>h;

	while (c!=-1){

		node nodes[3003];

		forn (i,l){
			int a,b,w;
			cin>>a>>b>>w;

			nodes[a].adj.pb(mp(w,b));
			nodes[b].adj.pb(mp(w,a));
		}

		//calculo MPT
		prim(nodes);

		forn (i,h){
			int s,t;
			cin>>s>>t;

			//Recorre de s a t y devuelve peso max
			cout<<recorre(s,t,nodes,0);
			cout<<' ';


		}
		cout<<endl;





		cin>>c>>l>>h;
	}


	return 0;
}