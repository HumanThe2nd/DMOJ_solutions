// BSSPC '21 J2 - James and Youtube
// Author: Dan Shan
// interval overlap checker
#include <stdio.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int t[1441];
int main() {
    int m,n;
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++){
            t[i]=1;
        }
    }
    scanf("%d",&n);
    while(n--){
        int a,b,f=0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++){
            if(t[i])f=1;
        }
        printf("%s\n",f?"Break is Over! Stop playing games! Stop watching Youtube!":":eyy:");
    }
}
