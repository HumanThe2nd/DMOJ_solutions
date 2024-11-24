// CCC '08 J3 - GPS Text Entry
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  unordered_map<char, vector<int>> m;
  m['A']={0,0}; m['B']={0,1}; m['C']={0,2}; m['D']={0,3};
  m['E']={0,4}; m['F']={0,5}; m['G']={1,0}; m['H']={1,1};
  m['I']={1,2}; m['J']={1,3}; m['K']={1,4}; m['L']={1,5};
  m['M']={2,0}; m['N']={2,1}; m['O']={2,2}; m['P']={2,3};
  m['Q']={2,4}; m['R']={2,5}; m['S']={3,0}; m['T']={3,1};
  m['U']={3,2}; m['V']={3,3}; m['W']={3,4}; m['X']={3,5};
  m['Y']={4,0}; m['Z']={4,1}; m[' ']={4,2}; m['-']={4,3};
  m['.']={4,4};
char word[41];
cin.getline(word,41);
int x=0,y=0,c=0;
for(int i=0;i<strlen(word);i++){
  vector<int> v = m[word[i]];
  while(x>v[0]){x--; c++;}
  while(x<v[0]){x++; c++;}
  while(y>v[1]){y--; c++;}
  while(y<v[1]){y++; c++;}
}
  vector<int> v = {4,5};
  while(x>v[0]){x--; c++;}
  while(x<v[0]){x++; c++;}
  while(y>v[1]){y--; c++;}
  while(y<v[1]){y++; c++;}
  printf("%d\n",c);
}
