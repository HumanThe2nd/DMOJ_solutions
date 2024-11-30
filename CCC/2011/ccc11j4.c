// CCC '11 J4 - Boring Business
// Author: Dan Shan
// Date: 2024-08-29
// mark visited cells in a 2d grid
#include <stdio.h>
int v[401][201];
int main() {
    int x=-1,y=5; // existing path
    for(int i=0;i<9;i++) v[i+199][7]=1;
    for(int i=0;i<8;i++) v[i+200][3]=1; 
    v[204][3]=0; v[204][5]=1; v[200][1]=1;
    v[200][2]=1; v[203][4]=1; v[205][4]=1;
    v[203][5]=1; v[205][5]=1; v[199][5]=1;
    v[199][6]=1; v[207][4]=1; v[207][5]=1;
    v[207][6]=1;/*
    for(int i=0;i<201;i++){
        for(int j=0;j<401;j++) if(v[j][i]) printf("%d %d\n",i,j);
    }*/
    while(1){
        int d,f=1; char s[2];
        scanf("%s %d",s,&d);
        if(s[0]=='q') break;
        if(s[0]=='l'){
            while(d--){
                x--;
                if(v[x+200][y])f=0;
                else v[x+200][y]=1;
            }
        }
       else if(s[0]=='d'){
            while(d--){
                y++;
                if(v[x+200][y])f=0;
                else v[x+200][y]=1;
            }
        }
        else if(s[0]=='r'){
            while(d--){
                x++;
                if(v[x+200][y])f=0;
                else v[x+200][y]=1;
            }
        }
        else {
            while(d--){
                y--;
                if(v[x+200][y])f=0;
                else v[x+200][y]=1;
            }
        }
        printf("%d %d %s\n",x,-y,f?"safe":"DANGER");
        if(!f) break;
    }
}
