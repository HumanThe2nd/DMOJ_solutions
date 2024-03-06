// GFSSOC '17 J4 - Top Courses
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n,c,m,t=0;
    cin >> n >> c >> m;
    cin.ignore();  // Ignore the newline character in the buffer
    if(n<c){
        printf("Ace is dunzos\n");
        return 0;
    }
    unordered_map<string, int> s;
    for(int i=0;i<n;i++){
        string line, si;
        int ni;
        getline(cin, line);
        size_t pos = line.find_last_of(' ');  // Find the last space in the line
        si = line.substr(0, pos);  // String
        ni = stoi(line.substr(pos+1));  // Get the integer
        s[si]=ni;
    }
    for(int i=0;i<m;i++){
        string si;
        getline(cin,si);
        if(s.find(si)==s.end()){
            printf("Ace is dunzos\n");
            return 0;
        }
        t+=s[si];
        s[si]=0;
    }
    vector<int> v;
    for(auto x:s){
        v.emplace_back(x.second);
    }
    sort(v.begin(),v.end(),greater<>());
    for(int i=0;i<c-m;i++) t+=v[i];
    double a = (double)t/c;
    printf("%0.2lf\n",a);
}
