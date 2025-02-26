// CCC '23 S3 - Palindromic Poster
// By: Dan Shan
#include <stdio.h>
int main() {
int n,m,r,c;
scanf("%d %d %d %d",&n,&m,&r,&c);
if(r>n||c>m||(r==n&&c==m-1)||(r==n-1&&c==m)||(n==r&&(!(m&1)&&(c&1)))||(m==c&&(!(n&1)&&(r&1)))){
	printf("IMPOSSIBLE\n");
	return 0;
}
char s[n][m+1];
for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		s[i][j]='a';
if(n!=r){
for(int i=0;i<m-c;i++)
    s[0][i]='b';
}
else{
for(int i=0;i<(m-c)/2;i++){
	s[0][i]='b';
	s[0][m-i-1]='b';
}
if((m-c)&1)s[0][m/2]='b';
}
if(m!=c){
for(int i=0;i<n-r;i++)
	s[i][0]='b';
}
else{
for(int i=0;i<(n-r)/2;i++){
	s[i][0]='b';
	s[n-i-1][0]='b';
}
}
if(n-r&&m-c)s[0][0]='d';
for(int i=0;i<n;i++){
	s[i][m]='\0';
	printf("%s\n",s[i]);
}
}
