// Word Scrambler
// By: Dan Shan
// Ordered permutation finder
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
void sw(char *a,char *b){
	char t=*a;
	*a=*b; *b=t;
}
int cmp(const void *a, const void *b){
    return (*(char*)a-*(char*)b);
}
int fc(char s[],char f,int l,int h){
    int c=l;
    for (int i=l+1;i<= h;i++)
        if (s[i]>f&&s[i]<s[c]) c=i;
    return c;
}
void p(char s[]) {
    int l=strlen(s);
    qsort(s,l,sizeof(s[0]),cmp);
    int f=0;
    while(!f) {
        printf("%s\n", s);
        int i;
        for(i=l-2;i>=0;--i)
            if(s[i]<s[i+1]) break;
        if(i==-1) f=1;
        else{
            int ceil=fc(s,s[i],i+1,l-1);
            sw(&s[i], &s[ceil]);
            qsort(s+i+1,l-i-1,sizeof(s[0]),cmp);
        }
    }
}
int main() {
	char s[7];
	for(int i=0;i<6;i++){
		s[i]=getchar_unlocked();
		if(s[i]=='\n') {
			s[i]='\0'; break;
		}
	}
	p(s);
}
