//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=29&page=show_problem&problem=647

#include <iostream>
#include <stdio.h>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
/*
      1
    -----
    |    |
  2 |    | 3
   4------
    |    |
 5  |    | 6
    ------
       7


*/




bool draw (char a, int pos) {
  switch (pos){
    case 1:
      switch (a){
        case '1':
        case '4':
          return false;
          break;
        default:
          return true;
      }
      break;

    case 2:
    switch (a){
      case '1':
      case '2':
      case '3':
      case '7':
        return false;
        break;
      default:
        return true;
    }
    break;

    case 3:
    switch (a){
      case '5':
      case '6':
        return false;
        break;
      default:
        return true;
    }
    break;

    case 4:
    switch (a){
      case '1':
      case '7':
      case '0':
        return false;
        break;
      default:
        return true;
    }
    break;

    case 5:
    switch (a){
      case '1':
      case '3':
      case '4':
      case '5':
      case '7':
      case '9':
        return false;
        break;
      default:
        return true;
    }
    break;

    case 6:
    switch (a){
      case '2':
        return false;
        break;
      default:
        return true;
    }
    break;

    case 7:
    switch (a){
      case '1':
      case '4':
      case '7':
        return false;
        break;
      default:
        return true;
    }
    break;

    default:
     return true;

  }
};


void printn (int n, string a){
  forn (i,n) cout<<a;
};
int main () {
  int siz;
  string num;

  cin>>siz;
  while ((siz!=0)){
    cin>>num;

  //str.size()


  for (int i=1;i<8;i++){

      if ((i==1)||(i==4)||(i==7)){
        forn (j,num.size()){
        if (draw(num[j], i)) {
          cout<<" ";
          printn (siz, "-");
          cout<<" ";
        }
        else printn (siz+2," ");

        if (j!=num.size()-1) cout<<" ";


      }
      if (i!=7) cout<<endl;
    }
      else {
        forn (h, siz){
        forn (j,num.size()){
        if (draw(num[j], i)) cout<<"|";
        else cout<<" ";
        printn (siz," ");
        if ((i==2)||(i==5)) {


          if (draw(num[j], i+1)) cout<<"|";
          else cout<<" ";

        }
         if (j!=num.size()-1) cout<<" ";

        //if (j==num.size()-1) cout<<endl;
      }
      cout<<endl;
    }
    i++;
  }
    }


cin>>siz;
if ((siz!=0)) cout<<endl<<endl;
}

  return 0;
}
