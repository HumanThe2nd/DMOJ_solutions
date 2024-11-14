// CCC '06 J3 - Cell-Phone Messaging
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
unordered_set<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v','w', 'x', 'y', 'z'};
int main(){
  unordered_map<char, int> m,m2;
  m['a']=1; m['b']=2; m['c']=3; m['d']=1; m['e']=2; m['f']=3;
  m['g']=1; m['h']=2; m['i']=3; m['j']=1; m['k']=2; m['l']=3;
  m['m']=1; m['n']=2; m['o']=3; m['p']=1; m['q']=2; m['r']=3;
  m['s']=4; m['t']=1; m['u']=2; m['v']=3; m['w']=1; m['x']=2;
  m['y']=3; m['z']=4;
  m2['a']=2; m2['b']=2; m2['c']=2; m2['d']=3; m2['e']=3; m2['f']=3;
  m2['g']=4; m2['h']=4; m2['i']=4; m2['j']=5; m2['k']=5; m2['l']=5;
  m2['m']=6; m2['n']=6; m2['o']=6; m2['p']=7; m2['q']=7; m2['r']=7;
  m2['s']=7; m2['t']=8; m2['u']=8; m2['v']=8; m2['w']=9; m2['x']=9;
  m2['y']=9; m2['z']=9;
  bool r=1;
  while(r){
  int c=0,h=1;
  char in[21]="";
  scanf("%s",in);
  if(in[0]=='h'&&in[1]=='a'&&in[2]=='l'&&in[3]=='t') break;
  for(auto x:in) {if(alpha.find(x)!=alpha.end()){
    c+=m[x];
    if(m2[x]==h) c+=2;
    h = m2[x];
  }
  }
  printf("%d\n",c);
  }
}
