// Amplitude Hackathon '23 Practice Problem 4 - Gigatron Autoscaling
// Author: Dan Shan
// incremenets and decrements with limits
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
int main(int argc, char *argv[]) {
    int n=scan(),p=scan();
    for(int i=0;i<n;i++){
        char c=getchar_unlocked();
        int a=scan();
        if(c=='I'){
            p+=a;
            if(p>1024) p=1024;
        }
        else{
            p-=a;
            if(p<1) p=1;
        }
        printf("%d\n",p);
    }
}
