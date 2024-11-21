/*
Back To School '17: Avalon
Author: Dan Shan
Date: 2024-11-20
probability formula
multiply good people and divide by total people each time
good people are equal to total - evil people
*/
int main() {
    int n;
    scanf("%d",&n);
    double r=1;
    while(n--){
        double e,p;
        scanf("%lf %lf",&e,&p);
        r*=(p-e)/p;
    }
    printf("%lf\n",r);
}
