// STNBD P3 - Rinslet Laurenfrost
// By: Dan Shan
// compare occurence of each letter 
#include <stdio.h>
int main() {
	int al[26];
	for(int i=0;i<26;i++) al[i]=0;
	char c=getchar_unlocked();
	while(c!='\n'){
		al[c-'a']++;
		c=getchar_unlocked();
	}
	while(c!=EOF){
		c=getchar_unlocked();
		al[c-'a']--;
	}
	int s=0;
	for(int i=0;i<26;i++){
		if(al[i]<0) s-=al[i];
		else s+=al[i];
	}
	printf("%d\n",s);
}
