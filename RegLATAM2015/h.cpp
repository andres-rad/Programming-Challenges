//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back

vector<vector <int > > mat;
long long int res;
int r,c;



vector<vector< int> > vis;


void dfs(int i, int j){
	vis[i][j]=1;
	if (i+1<r && mat[i+1][j]==mat[i][j] && !vis[i+1][j]){
		dfs (i+1,j);

	}
	if (i-1>=0 && mat[i-1][j]==mat[i][j] && !vis[i-1][j]){
		dfs (i-1,j);

	}


	if (j+1<c && mat[i][j+1]==mat[i][j] && !vis[i][j+1]){
		dfs (i,1+j);
	}
	if (j-1>=0 && mat[i][j-1]==mat[i][j] && !vis[i][j-1]){
		dfs (i,j-1);
	}

}

int main() {
	//	int r,c;

	while(cin>>r){
		cin>>c;
		mat.clear();


		forn (i,r){
			mat.pb(vector<int> (0));
			forn (j,c){
				int temp;
				cin>>temp;
				mat[i].pb(temp);
			}
		}
		vis.clear();

		vis=vector<vector<int > >(r+c, vector<int> (r+c, 0));


		res=5;

		forn (i, r){
			forn (j,c){
				if (!vis[i][j]){
					dfs(i,j);
					res++;
				}
			}
		}

		//cout<<endl<<res<<endl;

		int umax, umin;
		long long int esant;
		for (int i =1;i<r;i++){
			umax=0;
			esant=0;
			umin=0;

			forn (j,c){
				long long int a=mat[i-1][j];
				long long int b=mat[i][j];
				if ((umin >= max(a,b) || umax<= min(a,b) || esant*(b-a) <=0) && b-a!=0) {
					res++;
				//cout<< i<<endl<<j<<endl;

				}


				esant=b-a;
				umin=min(a,b);
				umax=max(a,b);
			}
		}
		//cout<<endl;

		for (int j =1;j<c;j++){
			umax=0;
			esant=0;
			umin=0;

			forn (i,r){
				long long int a=mat[i][j-1];
				long long int b=mat[i][j];
				if ((umin >= max(a,b) || umax<= min(a,b) || esant*(b-a) <=0) && b-a!=0) {
					res++;
				//cout<< i<<endl<<j<<endl;

				}


				esant=b-a;
				umin=min(a,b);
				umax=max(a,b);
			}
		}

		cout<<res<<endl;

	}

	return 0;
}
