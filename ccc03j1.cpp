#include <iostream>
using namespace std;
int main() {
// Note: height is the fork and length is the handle
  int height, width, length;
  cin >> height >> width >> length;
  // printing fork
  for(int i = 0; i < height;i++){
    cout << "*";
    for(int j = 0; j < width;j++){
      cout<<" ";
    }
    cout << "*";
    for(int j = 0; j < width;j++){
      cout<<" ";
    }
    cout << "*\n";
  }
  // printing middle
  cout << "***";
  for(int i = 0;i < width; i++){
    cout << "**"; 
  }
  // printing handle
  for(int i = 0; i < length;i++){
    cout << "\n ";
    for(int j = 0; j < width;j++){
      cout << " ";
    }
    cout << "*";
  }
  cout << "\n";
}
