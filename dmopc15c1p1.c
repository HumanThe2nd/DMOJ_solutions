#include <stdio.h>
int main(){
int n;
double m=-1,mi;
char name[27],name1[27];
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%s %lf",name1,&mi);
if(mi>m){m = mi; 
for(int i=0;i<26;i++){
    name[i]=name1[i];
}

}
}
printf("%s\n",name);
}
