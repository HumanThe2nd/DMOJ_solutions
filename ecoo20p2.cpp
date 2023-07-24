// ECOO '20 P2 - Online Shopping
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  scanf("%d",&T);
  for(int _=0;_<T;_++){
  int N;
  vector<string> name;
  vector<int> stock,price;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
  int N2;
  scanf("%d",&N2);
  for(int i=0;i<N2;i++){
    int p,n;
    string t="";
    char in[50] = "";
    scanf("%s %d %d",in,&p,&n);
    for(auto x:in)if(x!=*""&&x!=*" ")t+=x;
    name.push_back(t);
    stock.push_back(n);
    price.push_back(p);
  }
  }
  int k;
  int c=0;
  queue<string> items;
  queue<int> amounts;
  scanf("%d",&k);
  for(int i=0;i<k;i++){
    string t="";
    int a;
    char in[50] = "";
    scanf("%s %d",in,&a);
    for(auto x:in)if(x!=*""&&x!=*" ")t+=x;
    items.push(t);
    amounts.push(a);
  }
  while(items.size()!=0){
    string f = items.front();
    int index;
    int min = 100000;
    for(int i=0;i<name.size();i++){
      if(items.front()==name[i]&&price[i]<min) {
        min = price[i];
        index = i;
      }
    }
      if(stock[index]>=amounts.front()){
        c+=amounts.front()*price[index];
        amounts.pop();
        items.pop();
    }
    else {
      c+=stock[index]*price[index];
      amounts.front()-=stock[index];
      price[index]=1000000000;
    }
    }
    printf("%d %s",c,"\n");
  }
}
