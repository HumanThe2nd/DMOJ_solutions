// ECOO '19 R2 P1 - Email
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string fix(string email){
  bool a=0;
  bool p=0;
  string out;
  for(auto x:email){
    if(x==*"@"){a=1;}
    if(x==*"+"){p=1;}
    if((x!=*"."||a==1)&&(x!=*"+"||a==1)&&(p==0||a==1))out+=tolower(x);
  }
  return out;
}
int main() {
  for(int i=0;i<10;i++){
    int q;
    scanf("%d",&q);
    unordered_set<string> emails;
    for(int j=0;j<q;j++){
      char in[30]="";
      string inp;
      scanf("%s",in);
      for(auto x:in) if(x!=*""&&x!=*" ")inp+=x;
      string email = fix(inp);
      bool c=0;
      if(emails.find(email)!=emails.end())c=1;
      if(c==0)emails.insert(email);
    }
    int n = emails.size();
    printf("%d %s",*&n,"\n");
  }
}
