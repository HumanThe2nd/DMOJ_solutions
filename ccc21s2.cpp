//============================================================================
// Name        : CCC '21 S2 - Modern Art
// Author      : Dan Shan
//============================================================================
// Goal: given 2d array paint each row or column in query if already painted
// 		 then unpaint output the sum of painted values
// Approach: take in all queries if flipping reoccurences between 1 and 0
//			 use 2 arrays to track rows and columns as booleans and for
//			 each column subtract the rows it intersects and vice versa
#include <iostream>
#include <string.h>
using namespace std;
using ll = long long;
int main() {
    int m,n,k,g=0,c=0,r=0;
    scanf("%d %d %d",&m,&n,&k);
    bool row[m],col[n];
    memset(row,0,m);
    memset(col,0,n);
    for(int i=0;i<k;i++){
    	char rc[2]; int in;
    	scanf("%s %d",rc,&in);
    	if(rc[0]=='R'){
    		if(row[in-1])row[in-1]=0;
    		else row[in-1]=1;
    	}
    	else{
    		if(col[in-1])col[in-1]=0;
    		else col[in-1]=1;
    	}
    }
    for(int i=0;i<m;i++){
    	if(row[i])r++;
    }
    for(int i=0;i<n;i++){
    	if(col[i])c++;
    }
    g+=r*m-c;
    g+=c*n-r;
    g = r*n + c*m - 2*r*c;
    printf("%d\n",g);
}
