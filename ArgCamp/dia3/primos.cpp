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
	int n;
	
	cin >> n;
	while (n!=0){
		vector<tint> pri;
		
		forn (i,n){
			tint t;
			cin>>t;
			pri.pb(t);
		}
		set<tint> posibles;
		posibles.insert(1);
		
		tint xx,yy;
		cin>>xx>>yy;
	
	
		int cnt=0;
		bool flag=true;
		while (flag){
			
			tint temp=*posibles.begin();
			if (cnt>0&&temp>=xx && temp<=yy) cout<<",";
			posibles.erase(posibles.begin());
			if (temp>=xx && temp<=yy){
				cout<<temp;
				cnt++;
			}else if (temp>yy){
				flag=false;
			}
			forn (i,n){
				//cout<<"hfjkdhn";
				posibles.insert(temp*pri[i]);
			}
		}
		if (cnt==0) cout<<"none";
		cout<<endl;
		cin>>n;
	}
		
	return 0;
}
