// OCI '08 Contest 4 #1 Mjehuric
// Author: Dan Shan
// Date: 2024-10-16
// bubble sort with constant array length
#include <stdio.h>
int main() {
	int a[5];
	for(int i=0;i<5;i++) scanf("%d",&a[i]);
	for(int k=0;k<4;k++){
		for(int i=0;i<4;i++){
			if(a[i]>a[i+1]){
				int t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
			}
		}
	}
}
