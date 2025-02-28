/*
Dr. Anne Anderson Coding Contest 1 P5 - Guessing Grades
Author: Dan Shan
Date: 2025-02-28
find number of missing characters for each array:
directly count valid pairs (and store occurence of characters in second string)
for inavlid, store number of each character
compute the number of each missing character in second string using the stored array and provided answer count

for each character in second string, find the difference between its occurence and every otehr occurence in the first string
the maximal difference or zero is the minimum he could have gotten right out of the unknown
add that number to the counted pairs for the total
Time Complexity: O(N)
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int max(int a, int b){
    return a>b?a:b;
}
int main() {
    int n,a[]={0,0,0,0},a2[]={0,0,0,0},c=0,mn=0;
    scanf("%d  ",&n);
    char s[n+1],s2[n+1];
    scanf("%s %s",s,s2);
    for(int i=0;i<n;i++){
        if(s[i]==s2[i]) c++;
        if(s2[i]=='?') a[s[i]-'A']++;
        else a2[s2[i]-'A']--;
    }
    for(int i=0;i<4;i++) {
        int ai;
        scanf("%d",&ai);
        a2[i]+=ai;
    }
    mn = max(mn,a2[0]-a[1]-a[2]-a[3]);
    mn = max(mn,a2[1]-a[0]-a[2]-a[3]);
    mn = max(mn,a2[2]-a[1]-a[0]-a[3]);
    mn = max(mn,a2[3]-a[1]-a[2]-a[0]);
    printf("%d\n",c+mn);
}
