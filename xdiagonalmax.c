// array diagonal maximum
// By: Dan Shan
// 2d array reading
#include <stdio.h>
int main(){
int n,m1=0,m2=0;
scanf("%d",&n);
int ivan[n][n];
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		scanf("%d",&ivan[i][j]);
	}
}
for(int i=0;i<n;i++){ // one direction
int s = 0, s2 = 0;
for(int j=0;j+i<n;j++){
	s+=ivan[j+i][j];
}
if(s>m1) m1 = s;
for(int j=0;j+i<n;j++){
	s2+=ivan[j][j+i];
}
if(s2>m1) m1 = s2;
}
for(int i=0;i<n;i++){ // other direction
int s = 0, s2 = 0;
for(int j=0;j+i<n;j++){
	s+=ivan[n-j-i-1][j];
}
if(s>m2) m2 = s;
for(int j=0;j+i<n;j++){
	s2+=ivan[i+j][n-j-1];
}
if(s2>m2) m2 = s2;
}
printf("%d\n",m1+m2);
}
