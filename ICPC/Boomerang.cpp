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


int main (){

  int t,n;
  pair <int,int> st[2005];



  cin>>t;

  forn (h,t){
    int cnt=0;

    cin>>n;

    forn (j ,n){
      cin>>st[j].first>>st[j].second;
    }

    sort (st,st+n);

    forn (i,n){
      forn (j,n){

        //int j=p;

        if (j==i) j++;
        if (j>=n) continue;

        int d=(st[j].first-st[i].first)*(st[j].first-st[i].first)+(st[j].second-st[i].second)*(st[j].second-st[i].second);



        int z=1;
        if (i+z==j) z++;

        while ((st[i+z].first-st[i].first)*(st[i+z].first-st[i].first)<=d&&i+z<n){



          int dt=(st[i+z].first-st[i].first)*(st[i+z].first-st[i].first)+(st[i+z].second-st[i].second)*(st[i+z].second-st[i].second);

          if (dt==d) {cnt++;
            //cout<<"i "<<i<<" j "<<j<<" z "<<i+z<<endl;
          }

          z++;
          if (i+z==j) z++;
        }

         z=-1;
        if (i+z==j) z--;

        while ((st[i+z].first-st[i].first)*(st[i+z].first-st[i].first)<=d&&i+z>=0){



          int dt=(st[i+z].first-st[i].first)*(st[i+z].first-st[i].first)+(st[i+z].second-st[i].second)*(st[i+z].second-st[i].second);

          if (dt==d) {cnt++;
            //cout<<"I "<<i<<" j "<<j<<" z "<<i+z<<endl;
          }

          z--;
          if (i+z==j) z--;
        }


        /*int z=1;

        while ((st[j+z].first-st[i].first)^2<=d&&j+z<n){

          int dt=(st[j+z].first-st[i].first)^2+(st[j+z].second-st[i].second)^2;
          //cout<<"dt d "<<dt<<d<<z<<j<<endl;
          if (dt==d) {cnt++;
            cout<<i<<"  "<<j<<"  "<<j+z<<endl; }
          z++;
          if (j+z==j) z++;

        }

        z=-1;

        while ((st[i+z].first-st[i].first)^2<=d&&i+z>=0){

          int dt=(st[i+z].first-st[i].first)^2+(st[i+z].second-st[i].second)^2;
          //cout<<"dt d "<<dt<<d<<z<<j<<endl;
          if (dt==d) {cnt++;
            cout<<i<<"  "<<j<<"  "<<i+z<<endl;  }
          z--;
          if (i+z==j) z--;

        }*/

      }
    }

    cout<<"Case #"<<h+1<<": "<<cnt/2<<endl;


  }


  return 0;
}
