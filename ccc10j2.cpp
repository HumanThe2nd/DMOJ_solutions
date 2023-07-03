#include <iostream>
#include <vector>
// spent an extra hour from a typo >:(
using namespace std;
int main() {
  // using t1 and t2 for max full cycles
  int a,b,c,d,s,dN,dB,t1,t2;
  cin>>a>>b>>c>>d>>s;
  t1 = s/(a+b);
  t2 = s/(c+d);
  // complete cycles:
  dN = t1*(a-b);
  dB = t2*(c-d);
  // incomplete cycles:
  if(s-t1*(a+b) >= a) dN += a - (s-t1*(a+b)-a);
  else dN += (s-t1*(a+b));
  if(s-t2*(c+d) >= c) dB += c - (s-t2*(c+d)-c);
  else dB += (s-t2*(c+d));
  // print who's further
  if(dN > dB) cout << "Nikky";
  else if (dN == dB) cout << "Tied";
      else cout << "Byron";
}
