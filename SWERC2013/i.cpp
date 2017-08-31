#include <bits/stdc++.h>
using namespace std;
#define dprint(v) cout << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define fst first
#define snd second
#define INF 1e9
#define debug(a) cerr<< #a <<": "<<a<<endl;
typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;
/////

struct entry{
  map<int, int> hist;
  //vector<pair<int, int> > hist;
  int ult;
};

struct qentry {
  int freq;
  string name;
  int last;

  bool operator<(const qentry  & otro) const{
    if (freq!=otro.freq){
      return freq < otro.freq;
    }else if (name != otro.name){
      return name > otro.name;
    }else{
      return last < otro.last;
    }
  }
};



int main() {

  map<string, entry> m;
  priority_queue<qentry> qu;

  string temp;
  int day=0;
  while (cin>>temp){
    //debug(temp);
    if (temp == "<text>"){
      day++;
      //debug(day);

      cin>>temp;
      set<string> app;
      //debug(temp);
      while (temp !="</text>"){
        if (temp.length()>=4){

          app.insert(temp);
          auto & ent = m[temp];
          ent.ult = day;
          //actualizo la historia
          auto it=ent.hist.find(day);
          if (it == ent.hist.end()){
            if (ent.hist.empty()){
              ent.hist[day]=1;
            }else{
              //debug(temp);
              //debug(day);
              auto it = ent.hist.end();
              it--;
              //debug(it->second);

              ent.hist[day] = it->second + 1;
              //debug(ent.hist[day]);
            }
          }else{
            it->second=it->second+1;
          }


        }

        cin>>temp;
      }
      //debug(temp);
      //getline(cin, temp);
      //debug(temp);

      for (auto x :app){
        auto & ent = m[x];
        auto it = ent.hist.end();
        it--;
        int f = it->second;
        while (it != ent.hist.begin() && it->first > day - 7){
          it--;
        }
        //debug(f);
        if (it->first <= day-7){
          //debug(it->second);
          f-=it->second;
        }
        qu.push({f, x, ent.ult});
      }

    }else{
      //query tops
      int n;
      cin>>n;
      cin>>temp;
      //debug(day);
      cout<<"<top "<<n<<">"<<endl;
      int lastF=0;
      set<qentry> resave;
      while (!qu.empty() && (n>0 || lastF==qu.top().freq)){
        auto curr = qu.top();
        qu.pop();
        //debug(curr.name);
        //debug(curr.last);
        //debug(m[curr.name].ult);
        //debug(curr.freq);
        lastF = curr.freq;
        if (curr.last>day-7 && curr.freq!=0){ //me fijo que sea de los ultimos 7 dias
          if (curr.last == m[curr.name].ult){
            resave.insert(curr);
            cout<<curr.name<<' '<<curr.freq<<endl;
            n--;
          }
        }
      }
      for (auto x :resave){
        qu.push(x);
      }
      cout<<"</top>"<<endl;
    }
  }

  return 0;
}
