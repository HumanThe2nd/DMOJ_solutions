//============================================================================
// Name        : USACO 2022 February Bronze P3 - Blocks
// Author      : Dan Shan
//============================================================================
// Goal: check if combination is possible
// Approach: test all possible comibinations 
// Note: try different orders too some cubes might have high and low priority letters
//       also handle backward iteration to cover all orders
#include<iostream>
#include<string.h>
int n;
char s[4][7];
int main(){
	scanf("%d",&n);
	for(int i=0;i<4;i++){
		scanf("%s",s[i]);
	}
	for(int _=0;_<n;_++){ // for each word
		char w[5];
		scanf("%s",w);
		int l = strlen(w),f=0;
		for(int jt=0;jt<2;jt++){ // negative and positive iteration
		for(int it=0;it<4;it++){
		int fi=0,v[] = {0,0,0,0};
		for(int i=0;i<l;i++){ // for each character
			for(int j=0;j<4;j++){ // for each cube
				int ji = (it+j)%4;
				for(int k=0;k<6;k++){ // for each of its sides
				if(!jt){ // backward iteration
					if(s[3-ji][k]==w[i]&&!v[3-ji]){
						v[3-ji]=1;
						fi++;j=4;k=4;
					}
				}
				else if(s[ji][k]==w[i]&&!v[ji]){
					v[ji]=1;
					fi++;
					j=4;k=6; // move to next character
				}
				}
			}
		}
		if(fi==l){
			printf("YES\n"); f=1;
			jt=4;it=4;
		}
		}
		}
	if(!f)printf("NO\n");
	}
}
