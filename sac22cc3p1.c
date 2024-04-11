// SAC '22 Code Challenge 3 P1 - Hair Hazards
// By: Dan Shan
int main() {
    int h,s,q;
    scanf("%d %d %d",&h,&s,&q);
    for(int i=0;i<q;i++){
        h-=s;
        printf("%d\n",h);
    }
}
