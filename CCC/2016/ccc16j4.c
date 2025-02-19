// CCC '16 J4 - Arrival Time
// By: Dan Shan
#include <stdio.h>
char s[6];
int main(){
scanf("%s",s);
int h = (s[0]-'0')*10+s[1]-'0',
m = (s[3]-'0')*10+s[4]-'0';
for(int i=0;i<24;i++){ // go up 5 mins at a time
	if((h>6&&h<10)||(h>14&&h<19)){ // increment by 10 if between rush hour
		if(m==50){h++;m=0;}
		else m+=10;
	}
	else { // else increment 5
	if(m==55){h++;m=0;}
	else m+=5;
	}
	h%=24; // mod 24 hours
}
s[0]=h/10+'0'; s[1] = h%10+'0';
s[3]=m/10+'0'; s[4] = m%10+'0';
printf("%s",s);
}
