// COCI '15 Contest 7 #1 Nizovi
// By: Dan Shan
#include<stdio.h>
#include<string.h>
int main() {
char s[1501],si[1500];
scanf("%s",s);
int l = strlen(s),d=0,c=0;
for(int i=0;i<l;i++){
	if(s[i]=='{'){
		for(int j=0;j<d;j++)printf("  ");
		printf("{\n");
		d++;
	}
	else if(s[i]=='}'){
		if(c) {
			si[c] = '\0';
		for(int j=0;j<d;j++)printf("  ");
		printf("%s\n",si);
		for(int j=0;j<c;j++)si[j]='\0';
		c=0;
		}
		d--;
		for(int j=0;j<d;j++)printf("  ");
		if(i<l-1&&s[i+1]==','){
			printf("},\n");
			i++;
		}
		else printf("}\n");
	}
	else if(s[i]==','){
		for(int j=0;j<d;j++)printf("  ");
		si[c] = '\0';
		printf("%s,\n",si);
		for(int j=0;j<c;j++)si[j]='\0';
		c=0;
	}
	else {
		si[c]=s[i];
		c++;
	}
}
}
