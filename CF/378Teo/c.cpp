#include <vector>
#include <iostream>
#include<iomanip>
#include <queue>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair

vector<pair<int, char> > inst;


bool puedoComer(vector<int> & mostros, int desfasaje){

	vector<int> maxs;
	int max=0;

	if (mostros.size()==1) return true;
	//cerr<<"tam "<<mostros.size()<<endl;
	forn (i, mostros.size()){
		if (mostros[i]>max){
			maxs.clear();
			maxs.pb(i);
			max=mostros[i];
		}else if (max==mostros[i]){
			maxs.pb(i);
		}
	}




	if (maxs.size()==mostros.size()){
		return false;
	}

	int elijo=0;

	bool listo=false;

	if (maxs[elijo]!=0 ){
		listo=true;
		//cerr<<"caso "<<elijo<<endl;
	}

	while (!listo){
		if (elijo+1==maxs.size() || maxs[elijo]+1!=maxs[elijo+1]){
			listo=true;
		}else{
			elijo++;
		}
	}

	if (maxs[elijo]==mostros.size()-1 || (elijo+1<maxs.size() && maxs[elijo]+1==maxs[elijo+1])){
		int cur=maxs[elijo];

	 	while (cur>0){
	 		inst.pb(mp(cur+desfasaje, 'L'));
	 		cur--;
	 	}

		cur=maxs[elijo];

		while (cur<mostros.size()-1){
			inst.pb(mp(0+desfasaje, 'R'));
			cur++;
		}
	}else{
		cerr<<"else"<<endl;

		int cur=maxs[elijo];

		while (cur<mostros.size()-1){

			inst.pb(mp(maxs[elijo]+desfasaje, 'R'));
			cur++;
		}

		 cur=maxs[elijo];

		while (cur>0){
			inst.pb(mp(cur+desfasaje, 'L'));
			cur--;
		}
	}


	return true;
}




int main() {

	int n;
	cin>>n;

	vector<int> ini;

	forn (i,n){
		int temp;
		cin>>temp;
		ini.pb(temp);
	}

	int k;
	cin>>k;

	vector<int> fin;
	forn (i,k){
		int temp;
		cin>>temp;
		fin.pb(temp);
	}


	//int indn=n-1;
	//int indnant=n-1;

	/*dforn(i,k){
		int suma=0;

		while (suma<fin[i] && indn>=0){
			suma+=ini[indn];
			cerr<<"suma "<<suma<<endl;
			indn--;
		}

		if (suma==fin[i]){
			vector<int> newVec(ini.begin() + indn, ini.begin() + indnant);

			forn (i, newVec.size()){
				cerr<<"nVec "<<newVec[i]<<endl;
			}
			if (!puedoComer(newVec, indn+1)){
				cout<<"NO"<<endl;
				return 0;
			}


		}else{
			cout<<"NO"<<endl;
			return 0;
		}

		indnant=indn;

	}*/

	int indn=0;
	int indnant=0;

	forn (i,k){
		int suma=0;

		while (suma<fin[i] && indn<n){
			suma+=ini[indn];
			//cerr<<"suma "<<suma<<endl;
			indn++;
		}
		if (suma==fin[i]){
			vector<int> newVec(ini.begin() + indnant, ini.begin() + indn);


			if (!puedoComer(newVec, 1+i)){
				cout<<"NO"<<endl;
				return 0;
			}


		}else{
			cout<<"NO"<<endl;
			return 0;
		}

		indnant=indn;
	}

	if (indn!=n){cout<<"NO"<<endl; return 0;}

	cout<<"YES"<<endl;

	forn(i, inst.size()){
		cout<<inst[i].first<<' '<<inst[i].second<<endl;
	}


	return 0;
}
