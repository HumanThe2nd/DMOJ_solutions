//============================================================================
// Name        : VMSS '15 #1 - Senpai, Help Me
// Author      : Dan Shan
//============================================================================
// Goal: Find minumum perimeter for a rectangle of given area
// Approach: check for a valid perimeter starting closest from the sqrt of the area to 1
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
int a;
scanf("%d",&a);
double as = sqrt(a);
for(int i=as;i>0;i--){
if((double)a/i==(int)a/i){printf("%d\n",(int)2*(i+a/i)); break;}
}
}
