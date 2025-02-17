/*
COCI '08 Contest 4 #2 Datum
Author: Dan Shan
Date: 2025-02-16
Brute force days by adding each month
output day modulo 7 as its respective 'day of week' 
*/
#include <stdio.h>
#pragma GCC optimize("Ofast")
int main() {
    int d,m;
    scanf("%d %d",&d,&m); d--;
    if(m>1) d+=31;
    if(m>2) d+=28;
    if(m>3) d+=31;
    if(m>4) d+=30;
    if(m>5) d+=31;
    if(m>6) d+=30;
    if(m>7) d+=31;
    if(m>8) d+=31;
    if(m>9) d+=30;
    if(m>10) d+=31;
    if(m>11) d+=30;
    char s[][12]={"Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday", "Wednesday"};
    puts(s[d%7]);
}
