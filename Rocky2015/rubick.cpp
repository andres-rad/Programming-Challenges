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

#define matriz vector<vector<char> >

int main () {

	char in;
	while (cin >> in){
		vector<vector<char> > mtx;

		mtx.resize(4);
		forn (i,4){
			mtx[i].resize(4);
			forn(j,4) {
				if(i || j) cin >> in;
				mtx[i][j] = in == 'R' ? 0 :
							in == 'G' ? 1 :
							in == 'B' ? 2 :
										3 ;
			}
		}


		set<


















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