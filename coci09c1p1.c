// COCI '09 Contest 1 #1 Note
// Author: Dan Shan
// Date: 2024-10-04
#include <stdio.h>
int main() {
	int a[8];
	for(int i=0;i<8;i++)scanf("%d",&a[i]);
	for(int i=1;i<8;i++){
		if(a[i]-a[i-1]!=1)break;
		if(i==7) return printf("ascending\n")*0;
	}
	for(int i=1;i<8;i++){
		if(a[i-1]-a[i]!=1)break;
		if(i==7) return printf("descending\n")*0;
	}	
	printf("mxied\n");
}
