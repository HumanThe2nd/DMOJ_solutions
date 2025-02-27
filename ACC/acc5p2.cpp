// Another Contest 5 Problem 2 - Great Graffiti
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string s;
  cin >> s;
  if(s=="DMOJ") cout<<0<<endl;
  else if(s.find("DMO")<4||s.find("MOJ")<4||
    s.find("DOJ")<4||s.find("DMJ")<4)cout<<1<<endl;
  else if(s.find("DM")<4||s.find("MO")<4||s.find("MJ")<4||
    s.find("OJ")<4||s.find("DO")<4||s.find("DJ")<4) cout<<2<<endl;
  else cout<<3<<endl;
}
