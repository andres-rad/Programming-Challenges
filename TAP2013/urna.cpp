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

bool mayor(long i, long j){ return (i>j); }

int main(){
	int count;

	cin >> count;

	int tot = 0;
	int mx = 0, sx = 0;
	forn(i,count) {
		int v;
		cin >> v;

		tot += v;

		int a = v;
		if(v > mx) {
			a = mx;
			mx = v;
		}
		if(a > sx) {
			sx = a;
		}
	}
	double mf, sf, diff;
	mf = (double)mx / (double)tot;
	sf = (double)sx / (double)tot;
	diff = (double)(mx - sx) / (double)tot;

	int mt = (mx * 20) / tot;
	int diffT = ((mx - sx) * 20) / tot;

	//if(mf >= 0.45 || (mf >= 0.4 && diff >= 0.1)) {
	if(mt >= 9 || (mt >= 8 && diffT >= 2)) {
		cout << 1 << endl;
	} else {
		cout << 2 << endl;
	}

	return 0;
}