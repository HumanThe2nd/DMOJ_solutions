// USACO 2019 Open Contest Bronze P1 - Bucket Brigade
// By: Dan Shan
#include<iostream>
#include<queue>
int main() {
    int arr[10][10],bx,by,lx,ly,d=-1,f=0,dx[]={0,0,1,-1},dy[]={1,-1,0,0};
    for(int i=0;i<10;i++){
        char l[11];
        scanf("%s",l);
        for(int j=0;j<10;j++){
            l[j]=='R'?arr[i][j]=0:arr[i][j]=1;
            if(l[j]=='B'){
                bx=i;by=j;
            }
            else if(l[j]=='L'){
                lx=i;ly=j;
            }
        }
    }
    std::queue<int> qx,qy,qd;
    qx.push(bx);qy.push(by);
    qd.push(0);arr[bx][by]=0;
    while(!qx.empty()&&!f){
        int xi=qx.front(),yi=qy.front(),di=qd.front();
        qx.pop(); qy.pop(); qd.pop();
        for(int i=0;i<4;i++){
            int xii=xi+dx[i], yii=yi+dy[i];
            if(xii<10&&xii>=0&&yii<10&&yii>=0){
                if(xii==lx&&yii==ly){
                    d=di;
                    f=1;
                    break;
                }
                if(arr[xii][yii]){
                    qx.push(xii); qy.push(yii); qd.push(di+1);
                    arr[xii][yii]=0;
                }
            }
        }
    }
    printf("%d\n",d);
}
