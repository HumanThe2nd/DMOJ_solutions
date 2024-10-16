// Back From Summer '17 P2: Crayola Lightsaber
// Author: Dan Shan
// Date: 2024-10-15
// find max and total
// optimal solution given by 2*maximum <= total -> total (possible to use all markers)
// otherwise (total-maximum)*2+1 (add 1 since we can start with the maximum marker)
#include <stdio.h>
int n,c[6],m=-1,t=0;
int main() {
	scanf("%d",&n);
	while(n--){
		char s[10];
		scanf("%s",s);
		if(s[0]=='r') c[0]++;
		else if(s[0]=='o') c[1]++;
		else if(s[0]=='y') c[2]++;
		else if(s[0]=='g') c[3]++;
		else if(s[3]=='e') c[4]++;
		else c[5]++;
	}
	for(int i=0;i<6;i++){
		t+=c[i];
		if(c[i]>m) m=c[i];
	} 
	if(2*m<=t) printf("%d\n",t);
	else printf("%d\n",(t-m)*2+1);
}
