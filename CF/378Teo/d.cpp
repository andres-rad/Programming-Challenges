#include <vector>
#include <iostream>
#include<iomanip>
#include <queue>
#include<map>
#include<algorithm>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define mp make_pair


int main() {



	map <pair<int, int> , pair<pair<int, int> , pair<int, int> > > m;

	int n;
	cin>>n;

	forn (i,n){
		vector<int> vals(3);
		cin>>vals[0]>>vals[1]>>vals[2];
		sort(vals.begin(), vals.end());

		reverse(vals.begin(), vals.end());


		auto it=m.find(mp(vals[0], vals[1]));
		if (it==m.end()){
			m.insert(mp(mp(vals[0], vals[1]), mp(mp(vals[2], i), mp(0, -1))));
		}else{
			pair<pair<int, int> , pair<int, int> > aIns;
			if (vals[2]>it->second.first.first){

				aIns= mp(mp(vals[2], i), it->second.first);
				//def.second=def.first;
				//def.first=mp(vals[2], i);
			}else if(vals[2]>it->second.second.first){

				aIns= mp(it->second.first, mp(vals[2], i));

				//def.second=mp(vals[2], i);
			}
			//m.erase(mp(vals[0], vals[1]));
			//m.insert(mp(mp(vals[0], vals[1]), aIns));
			it->second=aIns;
		}

	}

	int res=0;
	int a=-1; int b=-1;

	for(auto iterator = m.begin(); iterator != m.end(); iterator++) {



		int posa=(iterator->second.first.second);
		int posb=(iterator->second.second.second);
		int posres=(iterator->second.first.first)+(iterator->second.second.first);

		if(posb==-1){
			posres=min(posres, iterator->first.first);

		}else{
			posres=min(posres, min(iterator->first.first, iterator->first.second));
		}


		if(res<posres){
				a=posa;
				b=posb;
			res=posres;
		}
	}

	if (b==-1){
		cout<<1<<endl<<a+1<<endl;
	}else{
		cout<<2<<endl<<a+1<<" "<<b+1<<endl;
	}


	return 0;
}
