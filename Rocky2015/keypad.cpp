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


int main () {

	int t=0, tests;
	cin>>tests;

	while (t<tests){
		t++;
		int r,c;
		cin >> r >> c;

		vector<vector<int> > mtx;

			mtx.resize(r);
		forn (i,r){
			mtx[i].resize(c);
			char ch;
			forn(j,c) {
				cin >> ch;

				mtx[i][j] = ch-'0';
			}
		}

		vector<int> fcmp;
		int filas1 = 0;
		int filasEq = 1;
		int colCount = 0;

		forn(i,r) {
			char en1 = 0;
			forn(j,c) {
				en1 = en1 || mtx[i][j];
			}

			if(en1) {
				if(!filas1) {
					fcmp = mtx[i];
				} else {
					filasEq = filasEq && fcmp == mtx[i];
				}

				filas1++;
			}
		}

		if(filas1) {
			forn(j,c) {
				if(fcmp[j]) colCount++;
			}
		}


		if (!filasEq){
			cout<<"impossible"<<endl;
		}else {
			char ch = filas1 > 1 && colCount > 1 ? 'I' : 'P';

			forn(i,r) {
				forn(j,c) {
					cout << (mtx[i][j] ? ch : 'N');
				}
				cout << endl;
			}
		}
		cout << "----------" << endl;
	}

		



	return 0;
	}