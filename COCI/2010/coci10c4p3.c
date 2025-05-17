/*
COCI '10 Contest 4 #3 Astro
Author: Dan Shan
Date: 2024-11-15
Store all time in minutes, continously increment smaller time, if match found run modulus to find real value
otherwise break after set amount of iterations to avoid infinite looping
*/
#include <stdio.h>
int main() {
	char s[6],s2[6],t[6],t2[6],d[][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	scanf("%s%s%s%s",s,s2,t,t2);
	int m=(s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0',m2; // first star
	m2=(s2[0]-'0')*600+(s2[1]-'0')*60+(s2[3]-'0')*10+s2[4]-'0'; // second star
	int mc=(t[0]-'0')*600+(t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0',mc2;
	mc2=(t2[0]-'0')*600+(t2[1]-'0')*60+(t2[3]-'0')*10+t2[4]-'0';
	for(int i=0;i<3000;i++){
		if(m==m2) break;
		if(m<m2) m+=mc;
		else m2+=mc2;
	}
	if(m==m2) printf("%s\n%s%d:%s%d\n",d[(m/1440)%7],(m%1440)/60>9?"":"0",(m%1440)/60,m%60<10?"0":"",m%60);
	else printf("Never\n");
}
