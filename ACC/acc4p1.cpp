// Another Contest 4 Problem 1 - Identity Crisis
// By: Dan Shan
string f(int N){
    string s,s2;
    while(N){
        s.push_back(N%10+'0');
        N/=10;
    }
    for(int i=s.length()-1;i>=0;i--)s2.push_back(s[i]);
    return s2;
}
