// CCC '03 S4 - Substrings
// Author: Dan Shan
// Suffix Array
#include <bits/stdc++.h>
using namespace std;
struct suf{
    int ind;
    char *suff;
};
int cmp(struct suf a,suf b){
    return strcmp(a.suff,b.suff)<0?1:0;
}
int *build(char *txt,int n){
    struct suf s[n];
    for(int i=0;i<n;i++){
        s[i].ind=i;
        s[i].suff=(txt+i);
    }
    sort(s,s+n,cmp);
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=s[i].ind;
    }
    return arr;
}
int count(char *txt, int *arr, int n) {
    int result=n-arr[0]; // Count the unique substrings starting from the first suffix
    for (int i=1;i<n;i++) {
        int lp=0;
        while(txt[arr[i]+lp]==txt[arr[i-1]+lp]) lp++;
        result+=(n-arr[i]-lp);
    }
    return result;
}
int main() {
	int n;
    scanf("%d",&n);
    for(int t=0;t<n;t++){
        char s[5002];
        scanf("%s",s);
        int *arr=build(s,strlen(s));
        int res=count(s,arr,strlen(s));
        printf("%d\n",res+1);
    }
}
