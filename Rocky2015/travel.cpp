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
		set<string> cities;

		int n;
		cin>>n;

		forn (i,n){
			string city;
			cin>>city;

			cities.insert(city);
		}

		cout<<cities.size()<<endl;
	}

		



	return 0;
	}