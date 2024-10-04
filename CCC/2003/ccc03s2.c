// CCC '03 S2 - Poetry
// Author: Dan Shan
// Ascii manipulation
// case folding input simplifies program
#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n); getchar_unlocked();
    while(n--){
        char s[4][81],v[]={'a','e','i','o','u',' '};
        int l[]={0,0,0,0};
        for(int i=0;i<4;i++){
            char si[81];
            int li=0;
            si[0]=getchar_unlocked();
            while(si[li]!='\n') {
                li++;
                si[li]=getchar_unlocked();
                if(si[li]<92&&si[li]!='\n'&&si[li]!=' ')si[li]+=32;
            } li--;
            while(li>=0){
                s[i][l[i]]=si[li]; 
                for(int j=0;j<6;j++) if(si[li]==v[j]) li=0;
                if(si[li]==' ') break;
                li--; l[i]++;
            }
            s[i][l[i]]='\0';
        } // booleans for even, cross, shell
        int e=l[0]==l[1]&&l[2]==l[3],c=l[0]==l[2]&&l[1]==l[3],sh=l[0]==l[3]&&l[1]==l[2];
        if(e){// check even
            for(int i=0;i<l[0];i++){
                if(s[0][i]!=s[1][i]) e=0;
            }
            for(int i=0;i<l[2];i++){
                if(s[2][i]!=s[3][i]) e=0;
            }
        }
        if(c){ // check cross
            for(int i=0;i<l[0];i++){
                if(s[0][i]!=s[2][i]) c=0;
            }
            for(int i=0;i<l[1];i++){
                if(s[1][i]!=s[3][i]) c=0;
            }
        }
        if(sh){
             for(int i=0;i<l[0];i++){
                if(s[0][i]!=s[3][i]) sh=0;
            }
            for(int i=0;i<l[1];i++){
                if(s[1][i]!=s[2][i]) sh=0;
            }
        }
        if(e&&c&&sh) printf("perfect\n");
        else if(e) printf("even\n");
        else if(c) printf("cross\n");
        else if(sh) printf("shell\n");
        else printf("free\n");
    }
}
