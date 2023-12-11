// DMOPC '23 Contest 1 P2 - Knights on Chessboard
// By: Dan Shan
// Important note: -1 is a trick in no cases is it the real answer
// there are less optimal answers that passes this is my best one
#include <stdio.h>
int main() {
int n;
scanf("%d",&n);
int g[n][n];
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		g[i][j]=0;
	}
}
for(int i=1;i<n-1;i++){
	for(int j=2;j<n-2;j+=5){
		g[i][j]=1;
	}
}
for(int i=1;i<n-1;i++){
		g[i][n-3]=1;
	}
for(int i=0;i<n;i++){
	if(g[1][i]&&!g[1][i+1]&&!g[1][i-1]){
		g[1][i-2]=1;
		g[n-2][i-2]=1;
	}
}
for(int i=0;i<n-4;i++){
	if(g[1][i]&&g[1][i+4]&&((i-2)%5)){
		g[1][i]=0;
		g[n-2][i]=0;
	}
}
if(g[1][n-4]){
    for(int i=3;i<n-4;i+=3){
        g[i][n-4]=0;
        g[i][n-3]=0;
    }
}
for(int i=0;i<n;i++){
	for(int j=0;j<n-1;j++){
		printf("%d ",g[i][j]);
	}
	printf("%d\n",g[i][n-1]);
}
}
