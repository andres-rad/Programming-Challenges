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
#define fs first
#define sd second


int main () {
	int n;
	cin>>n;
	int t;
	cin>>t;

	char num[200005];
	cin>>num;

	int poscoma=0;
	while (num[poscoma]!='.'){
		poscoma++;
	}

	
	int primerred=poscoma+1;
	while (t>0 && primerred!=n){
		

		while (primerred<n && num[primerred]-'0'<5){
			primerred++;
		}

		if (primerred==poscoma+1){
			if (poscoma==0){
				cout<<1<<endl;
				return 0;

			}
			else{
				while (poscoma!=0 && num[poscoma-1]=='9'){
					num[poscoma-1]='0';
					if (poscoma-1==0){
						cout<<1;
					}
						
					
					poscoma--;
					
				}
				if (poscoma!=0)num[poscoma-1]++;
				forn (i, poscoma+1){
					cout<<num[i];
				}
				cout<<endl;
				return 0;
			}
		}

		else if (primerred<n){
			num[primerred-1]++;
			t--;
			n=primerred; // no se si va ese +1
			primerred--;
		}
	}

	forn (i, n){
		cout<<num[i];
	}
	cout<<endl;


	return 0;
}