
#include <iostream>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)


int main () {
 int i [100000];
  int j [100000];
  int max [100000];
  int c,d;
  int t=0;
  int n,z,h;
  
  forn (g,100001){
    i[g]=1;
    j[g]=1;
    }
    
    
  
  while (cin>>c>>d) {
      i[t]=c;
      j[t]=d;
      t++;
    
  }
  
  
  
  
  
  forn (a,t){
    max[a]=0;
    
    if(i[a]<=j[a]){
        
      for (int g=i[a];g<=j[a];g++){
            n=1;
        h=g;
        
        
            while (h!=1){
              if ((h%2)==0) h=h/2;
              else h=(h*3)+1;
             
              n++;
  
      }
  
            if (n>max[a]) max[a]=n;
                
        }
    
    }
      else{
          for (int g=j[a];g<=i[a];g++){
            n=1;
            h=g;
           
            while (h!=1){
                n++;
                if (h%2==0) h=h/2;
                else h=3*h+1;
            
            }
            if (n>max[a]) max[a]=n;
                
        }
    
    
          
      }
      
  }
  
  forn (g,t){
        cout << i[g]<<" "<<j[g]<< " "<<max[g]<< endl;
        
    }
  return 0;
}
