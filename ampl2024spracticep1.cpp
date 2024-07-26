// Amplitude Hackathon Summer '24 Practice Problem 1 - Jeffrey's Favorite Integer
// Author: Dan Shan
// Binary Search
#include <iostream>
#include <string>
using namespace std;
int main() {
    int low = 1, high = 100;
    while(low <= high) {
        int mid = (high + low) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        if(s[0] == 'C') break;
        if(s[0] == 'L') high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}
