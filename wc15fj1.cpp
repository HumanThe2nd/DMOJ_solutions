//============================================================================
// Name        : WC '15 Finals J1 - Vertical Posting
// Author      : Dan Shan
//============================================================================
// Goal: print input horizontally and vertically intersecting at 1st char
// Approach: print normally with spaces between characters and \n at the end
//           print every letter after the first with \n in between and at the end
#include <iostream>
#include <string.h>
int main() {
char s[21];
scanf("%s",s);
int l = strlen(s);
for(int i=0;i<l-1;i++){
	printf("%c ",s[i]);
}
printf("%c\n",s[l-1]);
for(int i=1;i<l;i++){
	printf("%c\n",s[i]);
}
}
