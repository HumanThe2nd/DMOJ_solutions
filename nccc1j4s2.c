//============================================================================
// Name        : Mock CCC '18 Contest 1 J4/S2 - A Square Problem
// Author      : Dan Shan
//============================================================================
// Goal: check if a n by n array is a latin square, reduced or neither
// Latin: each number occurs only once in each column and once in each row
// Reduced: top row and left col are sorted in increasing order
// Approach: input as char array and check if latin, reduced or neither
#include <iostream>
#include <stdio.h>
int n,v[100],l=1;
int main() {
	scanf("%d",&n);
	char square[n][n+1];
	for(int i=0;i<n;i++){
		scanf("%s",square[i]);
	}
	for(int i=0;i<n;i++){ // check if latin using visited arr
		if(!l) break;
		for(int j=0;j<n;j++){
			if(v[square[j][i]-'0']) l=0; // !latin if revisited
			v[square[j][i]-'0']=1; // mark visited
		}
		for(int j=0;j<100;j++){
			v[j]=0;
		}
	}
	for(int i=0;i<n;i++){ // check if latin using visited arr
			if(!l) break;
			for(int j=0;j<n;j++){
				if(v[square[i][j]-'0']) l=0; // !latin if revisited
				v[square[i][j]-'0']=1; // mark visited
			}
			for(int j=0;j<100;j++){
				v[j]=0;
			}
		}
	if(!l){ // if latin print and end program
		printf("No\n");
		return 0;
	}
	int s = square[0][0]-'0',r=1;
	for(int i=1;i<n;i++){ // check if reduced
		if(square[0][i]-'0'<s) r=0;
		s = square[0][i]-'0';
	}
	s = square[0][0]-'0';
	for(int i=1;i<n;i++){ // check if reduced
		if(square[i][0]-'0'<s) r=0;
		s = square[i][0]-'0';
	}
	if(r)printf("Reduced\n");
	else printf("Latin\n");
}
