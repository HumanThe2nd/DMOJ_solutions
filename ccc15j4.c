//============================================================================
// Name        : CCC '15 J4 - Wait Time
// Author      : Dan Shan
//============================================================================
// Goal: track send and reply times for different people and state if unreplied
// Approach: - track send times and remove when replied
// 		 	 - store sum of time to answer each
//       	 - if a message is unanswered store print it as invalid (-1)
//       	 - else print the total time of the message following the index
#include<stdio.h>
int tt[100],tl[100]; // total time, time of last msg
int main(){
    int n,t=1; // t: time elapsed
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[2]; int a;
        scanf("%s %d",s,&a);
        a--; // convert to 0 indexing
        if(s[0]=='W')t+=a-1;
        else if(s[0]=='R')tl[a]=t;
        else {
                tt[a]+=(t-tl[a]);
                tl[a]=0; // mark as replied
        }
        t++; // elapse time by a if w otherwise 1
    }
    for(int i=0;i<100;i++){
        if(tl[i]) printf("%d -1\n",i+1); // unreplied msg
        else if(tt[i]) printf("%d %d\n",i+1,tt[i]);
    }
}
