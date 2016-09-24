#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>

using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair


int main () {

	int t=0, tests;
	cin>>tests;
	int mo=10*10*10*10*10*10*10*10*10+7;

	while (t<tests){
		priority_queue<long long int> numspos;
		priority_queue<long long int, vector<long long int>, greater<int> > numsneg;

		int n,k;
		cin>>n>>k;

		forn (i,n){
			int t;
			scanf("%d",t);
			if (t>0) numspos.push(t);
			else numsneg.push(t);
		}

		long long int tot=1;
		forn(i,k){
			if(i+1==k&&!numspos.empty()) {
				tot=tot*numspos.top() 	

	}
	return 0;
}
