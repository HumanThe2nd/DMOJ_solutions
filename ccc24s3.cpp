// CCC '24 S3 - Swipe
// By: Dan Shan
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n; // 0 for left and 1 for right when printing
    int a[n],b[n],c=0,ql[n],qr[n],qi[n],k=0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++){ // already equal
        if(a[i]!=b[i])break;
        if(i==n-1){
            printf("YES\n0\n");
            return 0;
        }
    }
    vector<int> order,index,index2; // index for left side index 2 for right side
    order.emplace_back(b[0]);
    index.emplace_back(0); // index where changes occur in b
    for(int i=1;i<n;i++){
        if(b[i]!=b[i-1]) {
            if(b[i]!=b[i-1]) {
                index.emplace_back(i);
                order.emplace_back(b[i]);
                index2.emplace_back(i-1);
            }
        }
    } index2.emplace_back(n-1);
    for(int i=0;i<n;i++){
        if(a[i]==order[c]) c++;
    }
    printf("%s\n",c==(int)order.size()?"YES":"NO");
    if(c!=(int)order.size()) return 0; 
    c=0;
    for(int i=0;i<n;i++){ // swipe left
        if(a[i]==order[c]){
            if(i>index[c]){
                qr[k]=i+1;ql[k]=index[c]+1,qi[k]=0;
                k++;
            }
            c++;
        }
    } c--;
    for(int i=n-1;i>=0;i--){ // swipe right
        if(a[i]==order[c]){
            if(i<index2[c]){
                ql[k]=i+1;qr[k]=index2[c]+1;qi[k]=1;
                k++;
            }
            c--;
        }
    }
    if(!k||(ql[k-1]<index2[0]&&qi[k-1])){
    ql[k]=1; qr[k]=index2[0]+1; qi[k]=1; k++;
    }
    if(k||(qr[k-1]<n-1&&qi[k-1]!=1)){
    ql[k]=index.back()+1; qr[k]=n; qi[k]=0; k++;
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++){
        printf("%s %d %d\n",qi[i]?"R":"L",ql[i]-1,qr[i]-1);
    }
}
