/*
CCC '05 S5 - Pinball Ranking
Author: Dan Shan
Date: 2025-06-19
1. Coordinate compreesion: limit to t distinct scores
2. Frequency array of scores in *descending* order
3. Binary Index Tree: PSA of frequency array
4. Each query: PSA to retrieve freuqnecies of higher scores (rank), update frequency array
Time Complexity: O(T*Log(T))
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define bs 1<<24 // Templates
char buf[bs];
char *ptr = buf;
void buff(){
    fread(buf,1,bs,stdin);
}
long long scan(){ // Fast input
    long long num=0,neg=1;
    while((*ptr<'0'||*ptr>'9')&&*ptr!='-')++ptr; // Skip non-digit characters
    while(*ptr=='-')++ptr,neg*=-1;
    while(*ptr>='0'&&*ptr<='9') {
        num=num*10+(*ptr-'0');
        ++ptr;
    }
    return num*neg;
}
int tree[100002];
int main() {
    buff();
    unordered_map<int,int> ind;
    int n=scan(),s=0,a[n+2];
    double c=0;
    vector<int> coords(n);
    for(int i=1;i<=n;++i){
        a[i]=scan();
        coords[i-1]=a[i];
    }
    sort(coords.begin(),coords.end(),greater<>()); // descending
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    for(auto x:coords) ind[x]=++s; // coord compression
    for(int i=1;i<=n;++i){
        int j=ind[a[i]],j2=j-1;
        double r=1; // retrieve rank
        while(j2>0){
            r+=tree[j2];
            j2-=j2&-j2;
        } c+=r;
        while(j<=n){ // update ranks
            ++tree[j];
            j+=j&-j;
        }
    }
    printf("%0.2lf\n",c/n);
}
