//============================================================================
// Name        : CCC '06 J4 - It's tough being a teen!
// Author      : Dan Shan
//============================================================================
// Goal: complete tasks in set order given prerequisites
// Approach: try each task from first to last and if finished skip if a task finishes
//			 restart the loop and if no task finishes by the end close the loop
//			 check if all tasks are completed after loop and print them if so
#include<stdio.h>
int main(){
	int adj[9][9],c=0,o[7],visited[9];
	for(int i=0;i<9;i++){ // filling in arrays
		visited[i]=0;
		for(int j=0;j<9;j++){
			adj[i][j]=0;
		}
	}
	adj[1][7]=1; // preset prerequistes
	adj[1][4]=1;
	adj[2][1]=1;
	adj[3][4]=1;
	adj[3][5]=1;
	while(1){
		int a,b;
		scanf("%d %d",&a,&b);
		if(!a&&!b) break;
		adj[a][b]=1; // can't visit a if b visited
	}
	while(1){
	int ci=c;
	for(int i=1;i<8;i++){
		int possible=1;
		for(int j=1;j<8;j++){
			if(adj[j][i])possible=0; // if prerequiste found don't add task
		}
		if(possible&&!visited[i]) {o[c]=i;c++; visited[i]=1; // mark it as done
		for(int k=1;k<8;k++)adj[i][k]=0; // clear it as any prerequistes
		break;
		}
	}
	if(ci==c) break; // if increment not possible end
	}
	if(c==7){ // if all tasks completed return array
		printf("%d %d %d %d %d %d %d\n",o[0],o[1],o[2],o[3],o[4],o[5],o[6]);
	}
	else printf("Cannot complete these tasks. Going to bed.\n");
}
