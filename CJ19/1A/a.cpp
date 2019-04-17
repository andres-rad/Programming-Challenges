#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int caso = 1; caso <= t; ++caso){
        int r, c; cin >> r >> c;
        bool vuelta = r > c;
        if (vuelta)
            swap(r, c);
        cout << "Case #" << caso << ": ";
        int d;
        for (d = 2; d < c - 1; d++){
            int tot = r*c;
            int x = 0, y = 0;
            vector<vector<int>> mat(r, vector<int>(c, 0));
            while (tot){
                if (mat[x][y] == 1){
                    break;
                }
                mat[x][y] = 1;
                tot--;
                x += 1;
                x %= r;
                
                y += d;
                y %= c;
                
            }
            if (!tot){
                goto solve;
            }
        }
        cout << "IMPOSSIBLE" << endl;
        continue;
        
        solve:
        cout << "POSSIBLE" << endl;
        int tot = r*c;
        int x = 0, y = 0;
        
        while (tot){
            if (vuelta){
                cout << y+1 << " " << x + 1 << endl;
            }else{
                cout << x+1 << " " << y + 1 << endl;
            }
            tot--;
            x += 1;
            x %= r;
            
            y += d;
            y %= c;
            
        }
    }
    
}

/*

|x| | | |
| | |x| |
|x| | | |


| | | | |

*/