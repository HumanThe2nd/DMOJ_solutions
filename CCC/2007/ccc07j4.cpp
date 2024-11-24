//============================================================================
// Name        : CCC '07 J4 - Anagram Checker
// Author      : Dan Shan
//============================================================================
// Goal: find if occurence of each nonspace characters are same in 2 strings
// Approach: link each nonspace char to its number of occurences and check if they
//           are equal for the the second string
#include<bits/stdc++.h>
using namespace std;
int main(){
char s1[100],s2[100];
bool anagram = 1;
scanf("%[^\n]%*c %[^\n]%*c", s1,s2);
unordered_map<char, int> occurences;
for(int i=0;i<(int)strlen(s1);i++){
char x = s1[i];
if(x==' ') continue;
if(occurences.find(x)==occurences.end())occurences[x]=1;
else occurences[x]++;
}
for(int i=0;i<(int)strlen(s2);i++){
char x = s2[i];
if(x==' ') continue;
if(occurences.find(x)==occurences.end()) anagram=0;
else if(occurences[x]==0) anagram=0;
else occurences[x]--;
}
if(anagram) printf("Is an anagram.");
else printf("Is not an anagram.");
}
