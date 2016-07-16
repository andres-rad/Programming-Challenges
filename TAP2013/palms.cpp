#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair

long long mcd(long long a, long long b) {return (a == 0) ? b : mcd(b%a, a);}

int main(){
	vector< pair<int, int> > pt;

	int n;

	cin>>n;

	forn (i,n){
		int x,y;
		cin>>x>>y;

		pt.pb(mp(y,x));
	}

	sort(pt.begin(), pt.end() );

	map<pair<long long,long long>, set< pair<int , int> > > checks;

	forn (i, n){

		pair<int, int> p1 = pt[i];
		for (int j=i+1;j<n;j++){

			pair<int, int> p2 = pt[j];

			//cout<<"CHECK p1: "<<p1.second<<" "<<p1.first<<" p2: "<<p2.second<<" "<<p2.first<<endl;
			long long dx=p1.second-p2.second;
			long long dy=p1.first-p2.first;
			if (dy!=0){

				pair<long long,long long> x;
				if (dx!=0){

					long long m = mcd(abs(dx),abs(dy));
					dx /= m;
					dy /= m;

					long long ca = p1.first*dx - p1.second*dy; // ca / cb
					long long cb = dx;
					//long double c= (long double)p1.first-p1.second*(dy/dx);

					long long xa = -ca * dx; // xa / xb
					long long xb = cb * dy;
					//x=(long double)-c*(dx/dy);

					m = mcd(abs(xa), abs(xb));
					xa /= m;
					xb /= m;

					if(xb < 0) {
						xb = -xb;
						xa = -xa;
					}

					x.first = xa;
					x.second = xb;

				}else{
					x.first = p1.second;
					x.second = 1;
				}
				
				checks[x].insert(p2);
				//cout<<"dx: "<<dx<<" dy: "<<dy<<" C: "<<x<<endl;
			}

		}
	}

	int cnt[1002]={0};
	int tot=1;
	cnt[n]=1;
	

	for (auto it = checks.begin(); it!=checks.end(); ++it){
		int count=(it->second).size();
		if (cnt[count]==0){
			tot++;
			cnt[count]=1;
		}

		//cout<<"C: "<<it->first<<" cnt: "<<count<<endl;
	}

	cout<<tot<<endl;

	return 0;
}