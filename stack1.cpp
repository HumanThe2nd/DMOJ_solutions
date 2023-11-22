#include<iostream>
#include<deque>
int main(){
std::cin.sync_with_stdio(0);
std::cin.tie(0);
int t,m;
std::cin >> t >> m;
std::deque<std::string> s;
for(int i=0;i<t;i++){
	std::string n, p;
	std::cin >> n >> p;
	if(p=="in") s.push_front(n);
	else if(s.front()==n){
		s.pop_front();
	}
	else if(s.back()==n&&(int)s.size()>m){
			s.pop_back();
		}
}
while(s.size()){
	std::cout<<s.back()<<"\n";
	s.pop_back();
}
}
