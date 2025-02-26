// CCC '24 J2 - Dusa And The Yobis
// By: Dan Shan
int main() {
	int r;
	scanf("%d",&r);
	while(1){
		int a;
		scanf("%d",&a);
		if(r<=a) break;
		r+=a;
	}
	printf("%d\n",r);
}
