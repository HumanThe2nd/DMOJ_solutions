// Back To School '18: Letter Frequency
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  map<char, vector<int>> freq;
  for (int i = 0; i < s.length(); i++) {
      freq[s[i]].push_back(i);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
      int start, end;
      char letter;
      cin >> start >> end >> letter;
      int first = lower_bound(freq[letter].begin(), freq[letter].end(), start - 1) - freq[letter].begin();
      int last = upper_bound(freq[letter].begin(), freq[letter].end(), end - 1) - freq[letter].begin();
      printf("%d %s",last-first,"\n");
  }
}
