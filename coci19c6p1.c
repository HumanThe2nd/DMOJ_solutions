// COCI '19 Contest 6 #1 Datum
// Author: Dan Shan
// if current month is greater of equal to required month, start at a year 1 higher
// for each year check if the respective month/date is valid
#include <stdio.h>
int main() {
    int n,m[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    scanf("%d",&n);
    while(n--){
        char s[12];
        scanf("%s",s);
        int year=s[9]-'0'+(s[8]-'0')*10+(s[7]-'0')*100+(s[6]-'0')*1000;
        int mi=s[4]-'0'+(s[3]-'0')*10,di=s[1]-'0'+(s[0]-'0')*10;
        int month=s[6]-'0'+(s[7]-'0')*10,day=s[8]-'0'+(s[9]-'0')*10;
        if(month>12||day>m[month-1]||month<mi||(month==mi&&day<=di)) year++; // skip current year if needed
        if(month==2&&day==29&&year%4)  year++;
        for(int i=year;i<10000;i++){ // check day and month boundaries
            di=(i%10)*10+(i/10)%10;
            mi=i/1000+((i/100)%10)*10;
            if(mi>12||!mi||!di||di>m[mi-1]) continue;
            if(mi==2&&di==29&&i%4) continue;
            year=i; break;
        }
        printf("%d%d.%d%d.%d%d%d%d.\n",year%10,(year/10)%10,(year/100)%10,year/1000,year/1000,(year/100)%10,(year/10)%10,year%10);
    }
}
