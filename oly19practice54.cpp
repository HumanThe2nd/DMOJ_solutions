// String Connection
// By: Dan Shan 
#include <bits/stdc++.h>
using namespace std;
class letters{
    public: char str[1001]; string value;
};
int main(){
  int n,l;
  scanf("%d %d",&n,&l);
  char in[l];
  vector<letters> v;
  for(int i=0; i<n;i++){
    string c;
    letters arr;
    scanf("%s",in);
    for(int j=0;j<l;j++){
      arr.str[j]=in[j];
      c+= int(in[j]);
    }
    arr.value = c;
    v.push_back(arr);
  }
  sort(v.begin(),v.end(),[&](letters x, letters y)
  {return x.value>y.value;});
  for(auto x:v) for(int i=0;i<l;i++) cout<<x.str[i];
  cout<<"\n";
}
