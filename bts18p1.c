// Back To School '18: Harambe
// Author: Dan Shan
#include <stdio.h>
int main() {
    int l=0,l2,c=0,k;
	char s[1001],ch;
    s[0]=getchar_unlocked();
    while(s[l]!='\n'){
        l++; s[l]=getchar_unlocked();
    }
    ch=getchar_unlocked();
    for(int i=0;i<l;i++){
        if(s[i]==' '&&ch!=' ') c+=1001;
        else if(s[i]!=' '&&ch==' ') c+=1001;
        if(s[i]!=ch) c++;
        ch=getchar_unlocked();
    }
    scanf("%d",&k);
    printf("%s\n",c>k?"No plagiarism":"Plagiarized");
}
