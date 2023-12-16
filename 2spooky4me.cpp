// 2spooky4me
// By: Dan Shan
#include <iostream>
#include <map>
int main() {
    int n,l,m;
    std::map<int,int> d;
    scanf("%d %d %d",&n,&l,&m);
    for(int i=0;i<n;i++){
        int a,b,s;
        scanf("%d %d %d",&a,&b,&s);b++;
        if(d.find(a)==d.end())d[a]=s;
        else d[a]+=s;
        if(d.find(b)==d.end())d[b]=-s;
        else d[b]-=s;
        if(!d[a])d.erase(a);
        if(!d[b])d.erase(b);
    }
    int s,sl,c=0; // initialized with first element in map
    bool f=1,fl=0;
    for(auto x:d){
    if(s>=m)fl=1;
    else fl=0;
    if(f){
        f=0;
        sl=x.first;
        s=x.second;
        continue;
    }
    s+=x.second;
    if(fl)c+=x.first-sl;
    sl=x.first;
    }
    printf("%d\n",l-c);
    return 0;
}
