/*
SAC '22 Code Challenge 3 Junior P1 - Normal Problem
Author: Dan Shan
Date: 2024-12-15
Brute force string check
*/
#include <stdio.h>
int main() {
	char s[100001];
   scanf("%s",s);
   int f=0;
   for(int i=6;i<100001;i++){
      if(s[i]=='\0') break;
      if(s[i-6]=='d'&&s[i-5]=='e'&&s[i-4]=='m'&&s[i-3]=='e'&&s[i-2]=='l'&&s[i-1]=='l'&&s[i]=='o') f=1;
   }
   printf("%s\n",f?"liar":"what are we going to do?");
}
