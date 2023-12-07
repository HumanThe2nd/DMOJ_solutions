#include <stdio.h>
int n;
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
int a;
scanf("%d",&a);
int d[a],s[a],c=0,f=0;
for(int j=1;j<=a/j;j++){
	if(!(a%j)){ // factor found
		d[c]=(a/j)-j;
		s[c]=(a/j)+j;
		c++;
	}
}
	for(int k=0;k<c;k++){
		for(int j=0;j<c;j++){
			if(d[k]==s[j]){
				f=1;k=c;j=c; // break if found
			}
		}
	}
	if(f)printf("%d is nasty\n",a);
	else printf("%d is not nasty\n",a);
}
}
