#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
  vector<string> songs = {"A","B","C","D","E"};
  string holder;
  bool run = true;
  int b,n;
  while(run == true){
    cin >> b >> n;
    // button 4 (close program)
    if(b == 4 && n == 1){
      for(int i = 0;i<songs.size();i++){
        cout << songs[i] << " ";
      }
      break;
    }
    // button 1
    if(b == 1){
      for(int i = 0;i<n;i++){
        songs.push_back(songs[0]);
        songs.erase(songs.begin());
      }
    }
    // button 2
    else if(b == 2){
      for(int i = 0;i<n;i++){
        songs.insert(songs.begin(),songs.back());
        songs.pop_back();
      }
    }
    // button 3
    else if(b == 3){
      for(int i = 0;i<n;i++){
        holder = songs[0];
        songs[0] = songs[1];
        songs[1] = holder;
      }
    }
  }
}
