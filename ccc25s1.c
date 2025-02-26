/*
CCC '25 S1 - Positioning Peter's Paintings
Author: Dan Shan
Date: 2025-02-19
rectangles must share the length or width, pick the minimal
output perimeter: 2*width + 2*length
*/
#include <stdio.h>
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a<b?b:a;
}
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n",min(2*max(a,c)+2*(b+d),2*max(b,d)+2*(a+c)));
}#include <stdio.h>
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a<b?b:a;
}
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d\n",min(2*max(a,c)+2*(b+d),2*max(b,d)+2*(a+c)));
}
