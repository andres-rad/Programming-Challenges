#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define x first
#define y second
using namespace std;

int main(){

  long n, px, py, lx, ly;

  while(cin >> n >> px >> py >> lx >> ly){

    vector<pair<int, int> > cat;
    vector<int> fs;
    vector<double> dist;
    vector<bool> visitado;

    if(n == -1) return 0;

    cat.push_back(make_pair(px, py));
    fs.push_back(0);
    dist.push_back(0);
    visitado.push_back(true)
    int cx, cy, f;

    for(int i = 0; i < n; i++){
      cin >> cx >> cy >> f;
      cat.push_back(make_pair(cx, cy));
      fs.push_back(f);
      dist.push_back(9999999999);
      visitado.push_back(false);
    }

    cat.push_back(make_pair(lx, ly));
    fs.push_back(0);
    dist.push_back(9999999999);
    visitado.push_back(false);

    for(int i = 0; i < n+2; i++){
      int curr = i;
      visitado[i] = true;
      for(int j = 0; j < n+2; j++){
        if(!visitado[j]){
          double d = abs( pow (pow(cat[curr].x - cat[j].x,2) + pow(cat[curr].y - cat[j].y, 2), 0.5) - fs[curr]);
          if (dist[j] > dist[curr] + d){
            dist[j] = dist[curr] + d;
          }
        }
      }
      for(int j = 0; j < n; j++){
        double minCurr = 9999999999;
        if(!visitado[j] && dist[j] < minCurr){
          curr = j;
        }
      }

      if(curr == n+2){
        double d = ((double)floor(dist[curr] * 100 + 0.5)) / 100.0;
        printf("%.2f", d);
        break;
      }
    }
  }

  return 0;
}
