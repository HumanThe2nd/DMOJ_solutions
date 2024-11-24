#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  string inp;
  bool run = true;
  while(run == true){
    cin >> inp;
    if(inp == "CU") cout << "see you";
    else if(inp == ":-)") cout << "I'm happy";
    else if(inp == ":-(") cout << "I'm unhappy";
    else if(inp == ";-)") cout << "wink";
    else if(inp == ":-P") cout << "stick out my tongue";
    else if(inp == "(~.~)") cout << "sleepy";
    else if(inp == "TA") cout << "totally awesome";
    else if(inp == "CCC") cout << "Canadian Computing Competition";
    else if(inp == "CUZ") cout << "because";
    else if(inp == "TY") cout << "thank-you";
    else if(inp == "YW") cout << "you're welcome";
    else if(inp == "TTYL") {
      cout << "talk to you later";
      break;
    }
    else cout << inp;
    cout << "\n";
  }
}
