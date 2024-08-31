// CCC '24 J4 - Troublesome Keys
// Author: Dan Shan
// Date: 2024-08-31
// find characters in fake string never occuring in real string
#include <stdio.h>
int a[26],a2[26];
int main() {
    char s[500001],s2[500001];
    scanf("%s %s",s,s2);
    for(int i=0;i<500001;i++){
        if(s[i]=='\0') break;
        a[s[i]-'a']++;
    }
    for(int i=0;i<500001;i++){
        if(s2[i]=='\0') break;
        a2[s2[i]-'a']++;
    }
    char sil='-',q='-',q2;
    for(int i=0;i<26;i++){ // assumes silly key is larger alphabetically
        if(!a[i]&&a2[i]) q2='a'+i;
        else if(a[i]&&!a2[i]) {
            if(q=='-') q='a'+i;
            else sil='a'+i;
        }
    }
    int l=0,f=0; // flip silly with quiet if verification fails
    for(int i=0;i<500001;i++){ // verify
        if(s[i]=='\0') break;
        if(s[i]==sil) {
            l++;
            continue;
        }
        if(s[i]==q&&s2[i-l]==q2) continue;
        else if(s[i]!=s2[i-l]){
            f=1; break;
        }
    }
    if(f){
        char temp=sil;
        sil=q; q=temp;
    }
    printf("%c %c\n%c\n",q,q2,sil);
}
