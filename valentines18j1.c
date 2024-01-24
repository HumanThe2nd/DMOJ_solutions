// Valentine's Day '18 J1 - The Cactus Number
// By: Dan Shan
#include <stdio.h>
#define MAX(a,b)((a)>(b)?(a):(b))
int main() {
int n,m=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
	int a;
	scanf("%d",&a);
	m = MAX(m,a);
}
if(m<=1000) printf("Cuteness by definition is similarity to Carol\n");
else if(m<=10000) printf("Cuteness by definition is similarity to Cactus\n");
else printf("Something is wrong with these cuteness values\n");
}
