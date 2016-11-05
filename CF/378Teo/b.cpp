#include <vector>
#include <iostream>
#include<iomanip>
#include <queue>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back



int main() {

	int n;
	cin>>n;

	int Rcur=0;
	int Rcurmax=0;
	int Lcur=0;
	int Lcurmax=0;

	vector<vector<int> > cols (n, vector<int> (2,0));

	int L=0;int  R=0;




	forn (i,n){
		int l,r;
		cin>>l>>r;
		cols[i][0]=l;
		cols[i][1]=r;
		L+=l;
		R+=r;
	}

	int difcur=abs(L-R);

	forn(i,n){
		int l=cols[i][0];
		int r=cols[i][1];

		int difnueva=abs(L-l+r - (R-r+l));

		if (difnueva> difcur){
			difcur=difnueva;
			Lcur=i+1;
			Rcur=i+1;

		}

	}


	cout<<Lcur<<endl;

	return 0;
}
