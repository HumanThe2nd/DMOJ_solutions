// Lucky Board
// By: Dan Shan
#include <iostream>
#include <vector>
#include <algorithm>
class kid{
public:
    int n;
    long double v;
};
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<kid> vk(n);
    for(int i=0;i<n;i++){
        kid ki; int a,b;
        ki.n=i+1;
        std::cin >> a >> b;
        ki.v = (long double)a/(a+b);
        vk[i]=ki;
    }
    std::stable_sort(vk.begin(),vk.end(),[&](kid a, kid b){return a.v>b.v;});
    for(int i=0;i<n-1;i++){
        printf("%d ",vk[i].n);
    }
    printf("%d\n",vk.back().n);
    }
