//============================================================================
// Name        : CCC '05 S1 - Snow Calls
// Author      : Dan Shan
//============================================================================
// Goal: Convert non chars to int according to the phone keyboard and output with specifified format
// Approach input everything as a char array and convert everythng to the number
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	int n;
	unordered_map<char, int> m;
	m['0']=0; m['1']=1;m['2']=2; m['3']=3; m['4']=4; m['5']=5;
	m['6']=6; m['7']=7; m['8']=8; m['9']=9; m['A']=2; m['B']=2;
	m['C']=2; m['D']=3; m['E']=3; m['F']=3; m['G']=4; m['H']=4;
	m['I']=4; m['J']=5; m['K']=5; m['L']=5; m['M']=6; m['N']=6;
	m['O']=6; m['P']=7; m['Q']=7; m['R']=7; m['S']=7; m['T']=8;
	m['U']=8; m['V']=8; m['W']=9; m['X']=9; m['Y']=9; m['Z']=9;
	scanf("%d",&n);
	for(int j=0;j<n;j++){
	char in[41];
	scanf("%s",in);
	vector<int> out;
	int s = strlen(in);
	for(int i=0;i<s;i++) if(in[i]!='-')out.push_back(m[in[i]]);
	for(int i=0;i<3;i++)printf("%d",out[i]);
	printf("-");
	for(int i=3;i<6;i++)printf("%d",out[i]);
	printf("-");
	for(int i=6;i<10;i++)printf("%d",out[i]);
	printf("\n");
	}
}
