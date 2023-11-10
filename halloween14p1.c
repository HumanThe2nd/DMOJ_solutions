#include<stdio.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	if(n<k) printf("%d\n",k-n);
	else {
	    n%=k;
	    if (n>k-n) printf("%d\n",k-n);
	    else printf("%d\n",n);
	}
}
