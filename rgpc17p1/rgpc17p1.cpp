//============================================================================
// Name        : RGPC '17 P1 - Circle Clicking!
// Author      : Dan Shan
//============================================================================
// Goal: count maximum number of points where distance between points less than a number
// Approach: set xi to 2000 to reset when chain broken and starting otherwise count
//           longest distance till broken
#include<stdio.h>
#include<math.h>
int main(){
    int n,d,c=0,m=0,xi=2000,yi=2000;
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++){
    	int x,y;
    	scanf("%d %d",&x,&y);
    	double xd = x;
    	double yd = y;
    	double D = sqrt((yd-yi)*(yd-yi)+(xd-xi)*(xd-xi));
    	if(xi==2000){c++;xi=x,yi=y;}
    	else if(D>d){if(c>m)m=c;c=0;xi=2000;}
    	else {c++;xi=x,yi=y;}
    }
    if(c>m)m=c;c=0;
    printf("%d\n",m);
}
