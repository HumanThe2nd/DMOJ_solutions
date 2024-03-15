// DMOPC '15 Contest 5 P2 - D-Mails
// By: Dan Shan
// subsequence checker
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    for(int ti=0;ti<n;ti++){
        char s[101],
        so[]="elpsycongroo",
        sm[]="tuturu",
        sd[]="superhacker",
        sk[]="myfork";
        scanf("%s",s);
        int o=0,l; // o: boolean for or 
        for(int i=0;i<101;i++){
            if(s[i]=='\0'){
                l=i; break;
            }
        } int j=0;
        for(int i=0;i<l;i++){
            if(s[i]!=so[j]) continue;
            j++;
            if(j!=12) continue;
            printf("Okabe"); o=1;
            break;
        } j=0;
        for(int i=0;i<l;i++){
            if(s[i]!=sm[j]) continue;
            j++;
            if(j!=6) continue;
            printf("%sMayuri",o?" or ":""); o=1;
            break;
        } j=0;
        for(int i=0;i<l;i++){
            if(s[i]!=sd[j]) continue;
            j++;
            if(j!=11) continue;
            printf("%sDaru",o?" or ":""); o=1;
            break;
        } j=0;
        for(int i=0;i<l;i++){
            if(s[i]!=sk[j]) continue;
            j++;
            if(j!=6) continue;
            printf("%sKurisu",o?" or ":""); o=1;
            break;
        } 
        printf("%s\n",!o?"SERN spy!":"");
    }
}
