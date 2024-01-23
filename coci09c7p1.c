// COCI '09 Contest 7 #1 Spavanac
// By: Dan Shan
#include <stdio.h>
int main() {
int h,m;
scanf("%d %d",&h,&m);
m+=15;
int d = m/60; m%=60;
if(!d){ // hour moved back
	h+=23; h%=24;
}
printf("%d %d\n",h,m);
}
