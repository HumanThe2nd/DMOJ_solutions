// CCC '24 J3 - Bronze Count
// By: Dan Shan
int main() {
	int n,m1=0,m2=0,m3=0,c=0,c2=0,c3=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		if(a>m1){
			c3=c2; c2=c; c=1;
			m3=m2; m2=m1; m1=a;
		}
		else if(a==m1) c++;
		else if(a>m2){
			c3=c2; c2=1;
			m3=m2; m2=a;
		}
		else if(a==m2) c2++;
		else if(a>m3){
			m3=a; c3=1;
		}
		else if(a==m3) c3++;
	}
	printf("%d %d\n",m3,c3);
}
