#include <vector>
#include <iostream>
#include<iomanip>
#include <queue>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back


int main() {
	int res=1;
	int cur=0;

	string inp;

	cin>>inp;

	inp.pb('a');

	forn (i, inp.size()){
		cur++;


		res=max(res, cur);
		if (inp[i]=='A' || inp[i]=='E' || inp[i]=='I' || inp[i]=='Y' || inp[i]=='O' || inp[i]=='U'){
			cur=0;
		}
	}

	cout<<res<<endl;

	return 0;
}
