//============================================================================
// Name        : CCC '08 S1 - It's Cold Here!
// Author      : Dan Shan
//============================================================================
// Goal: Find minimum value and print string connected to it
// Approach: find index of minimum and print string at the same index
#include <iostream>
#include <vector>
int main() {
std::vector<std::string> names;
std::vector<int> temps;
while(1){
	std::string city;
	int temp;
	std::cin >> city;
	std::cin >> temp;
	names.push_back(city);
	temps.push_back(temp);
	if(city=="Waterloo") break;
}
int min = temps[0],index=0;
for(int i=1;i<(int)temps.size();i++){
	if(temps[i]<min) {min=temps[i];index=i;}
}
std::cout<<names[index]<<"\n";
}
