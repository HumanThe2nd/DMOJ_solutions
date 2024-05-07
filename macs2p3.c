// Max's Anger Contest Series 2 P3 - Array Anger
// By: Dan Shan
// PSA + binary search
#include<stdio.h>
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
int main() {
	int n=scan(),q=scan();
	int a[n+1]; a[0]=0;
	for(int i=0;i<n;i++){
		int ai=scan();
		a[i+1]=a[i]+ai;
	}
    for(int i=0;i<q;i++){
        int s=scan(),m=scan();
            int l = s, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (a[mid]-a[s-1] < m) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            printf("%d\n",l);
    }
}
