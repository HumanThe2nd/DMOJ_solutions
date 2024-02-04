// COCI '15 Contest 4 #1 Yoda
// By: Dan Shan
#include <stdio.h>
int main() {
    int n,m,c1=0,c2=0,n1[10],n2[10];
    scanf("%d %d",&n,&m);
    int max = n>m?n:m;
    for(long long i=1;i<=max;i*=10){
    	int d1=n/i%10,d2=m/i%10;
    	if(d1==d2){
    		n1[c1]=d1;
    		n2[c2]=d2;
    		c1++; c2++;
    	}
    	else if(d1>d2){
    		n1[c1]=d1;
    		c1++;
    }
    	else {
    		n2[c2]=d2;
    		c2++;
    	}
    }
    if(!c1)  printf("YODA");
    else{
    	int z=1;
    	for(int i=0;i<c1;i++){
    	    if(n1[c1-i-1]==0&&z) continue;
    	    	z=0;
    	    	printf("%d",n1[c1-i-1]);
    	    }
    	if(z)printf("0");
    }
    printf("\n");
    if(!c2) printf("YODA");
    else{
    	int z=1;
    	for(int i=0;i<c2;i++){
    		if(n2[c2-i-1]==0&&z) continue;
    		z=0;
    	    printf("%d",n2[c2-i-1]);
    	}
    	if(z)printf("0");
    }
    printf("\n");
}
