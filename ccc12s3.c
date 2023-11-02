// CCC '12 S3 - Absolutely Acidic
// By: Dan Shan
#include <stdio.h>
int n,r[1001],max,min,a1,a2,b1,b2;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	int in;
    	scanf("%d",&in);
    	r[in]++;
    }
    for(int i=1;i<=1000;i++){ // find largest 2 occurences
    	if(r[i]>max)max=r[i]; // largest
    	else if(r[i]>min) min=r[i]; // second largest
    }
    for(int i=1;i<=1000;i++){ // lowest 2
    	if(r[i]==max)a1=i;
    	if(r[i]==min)b1=i;
    }
    for(int i=1000;i>0;i--){ // highest 2
        if(r[i]==max)a2=i;
        if(r[i]==min)b2=i;
    }
    int s = abs(b2-a1);
    if(abs(b1-a2)>s)s = abs(b1-a2);
    printf("%d\n",s);
}
