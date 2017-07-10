#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define f first
#define s second
#define mp make_pair

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;

string ans3d[2] = {"True closed chains","No true closed chains"};
string ans2d[2] = {"Floor closed chains", "No floor closed chains"};

namespace std
{
	template <>
	struct hash<pii >
	{
		public:
		    inline size_t operator()(pii x) const throw()
			{
		         size_t h = 1000*x.f + x.s;
		         return h;
		    }
	};

	template <>
	struct hash<piii >
	{
		public:
		    inline size_t operator()(piii x) const throw()
			{
		         size_t h = 1000*1000*x.f.f + 1000*x.f.s + x.s;
		         return h;
		    }
	};
}

int main()
{
	int k;

	while(cin >> k)
	{
		unordered_map<pii, unordered_set<pii> > adj2d;
		unordered_map<piii, unordered_set<piii> > adj3d;
		unordered_map<piii, bool> vis3d;
		unordered_map<pii, bool> vis2d;
		
		int a,b,c,x,y,z;
		int co3 = 0; int co2 = 0;

		forn(i,k)
		{
			cin >> a >> b >> c >> x >> y >> z;

			piii U = mp(mp(a,b),c);
			piii V = mp(mp(x,y),z);
			
			if(U != V)
			{
				adj3d[U].insert(V); adj3d[V].insert(U);
			}
			vis3d[U] = false; vis3d[V] = false;
			if(U.f != V.f)
			{
				adj2d[U.f].insert(V.f); adj2d[V.f].insert(U.f);
			}
			vis2d[U.f] = false; vis2d[V.f] = false;
		}

		//bfs 3d
		unordered_map<piii, unordered_set<piii> >:: iterator it;
		unordered_set<piii>:: iterator jt;
		int noclosed = 1;
		for(it = adj3d.begin(); it != adj3d.end(); it++)
		{
			if(!vis3d[it->first])
			{				
				int n = 0; int m = 0;
				//cout << (it->first).f.f << " " << (
				vis3d[it->first] = true;
				queue<piii> Q;
				Q.push(it->first);
				piii u;
				while(!Q.empty())
				{
					u = Q.front(); Q.pop();
					n++;
					
					for(jt = adj3d[u].begin(); jt != adj3d[u].end(); jt++)
					{
						m++;
						if(!vis3d[*jt])
						{
							vis3d[*jt] = true;
							Q.push(*jt);
						}
					}
				}
				m /= 2;
				if(m > (n-1))
				{
					noclosed = 0;
					break;
				}
			}
		}

		cout << ans3d[noclosed] << endl;

		//bfs 2d
		unordered_map<pii, unordered_set<pii> >:: iterator it2;
		unordered_set<pii>:: iterator jt2;
		noclosed = 1;		
		for(it2 = adj2d.begin(); it2 != adj2d.end(); it2++)
		{
			if(!vis2d[it2->first])
			{
				int n = 0; int m = 0;
				vis2d[it2->first] = true;
				queue<pii> Qu;
				Qu.push(it2->first);
				pii u;
				while(!Qu.empty())
				{
					u = Qu.front(); Qu.pop();
					//cout << u.f << " " << u.s << endl;
					n++;
					
					for(jt2 = adj2d[u].begin(); jt2 != adj2d[u].end(); jt2++)
					{
						m++;
						//cout << "adj " << jt2->f << " " << jt2->s << endl;
						if(!vis2d[*jt2])
						{
							vis2d[*jt2] = true;
							Qu.push(*jt2);
						}
					}
				}
				//cout << n << " " << m/2 << endl;
				m /= 2;
				if(m > (n-1))
				{
					noclosed = 0;
					break;
				}
			}
		}

		cout << ans2d[noclosed] << endl;

	}

	return 0;
}
