// THICC '17 P1 - Carol's Carnivorous Plants
// Author: Dan Shan
// sort and move down in decsending order
// note: overflows may occur when emplmenting exponents
#include<stdio.h>
#include<math.h>
int scan() {
    int num = 0;
    char c = getchar_unlocked();
    while (c>'9'||c<'0') c = getchar_unlocked();
    while (c>='0'&&c<='9') {
        num=num*10+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
int pw(int a,int b){
    long long res=1;
    for(int i=0;i<b;i++){
        res*=a; res%=(int)(1e9+7);
    }
    return (int)res;
}
int cmp(const void*a, const void*b){
   return(*(int*)a-*(int*)b);
}
int main(int argc, char *argv[]) {
    int n=scan(),m=scan();
    int a[n],p=0,c=0;
    for(int i=0;i<n;i++) a[i]=scan();
    qsort(a,n,sizeof(int),cmp);
    while(n>=0){
        for(int i=0;i<m;i++){
            n--; if(n<0) break;
            c+=pw(a[n],p); c%=(int)1e9+7;
        }
        p++;
    }
    printf("%d\n",c);
}
