// CCC '15 J3 - Rövarspråket
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
set<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z'};
int main(){
  char word[31]="";
  unordered_set<char> vowels = {'a','o','u','i','e'};
  scanf("%s",word);
  for(auto x:word) {if(vowels.find(x)!=vowels.end())cout<<x;
                    else if(alpha.find(x)!=alpha.end()){
      cout<<x;
      bool run=1;
      auto l= alpha.find(x);
      auto r = l;
      while(run==1){
      if(l!=alpha.begin()) l--;
      if(r!=alpha.end()--) r++;
      if(vowels.find(*l)!=vowels.end()){
        cout<<*l;
        break;
      }
      if(vowels.find(*r)!=vowels.end()){
        cout<<*r;
        break;
      }
      }
      r= alpha.find(x);
      while(run==1){
      if(*r=='z'){
      cout<<'z';
      break;
      }
      if(r!=alpha.end()--) r++;
      if(vowels.find(*r)==vowels.end()){
        cout<<*r;
        break;
      }
      }
    }
  }
}
