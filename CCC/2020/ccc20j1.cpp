int main() {
  int s;
  int m;
  int l;
  std::cin >> s;
  std::cin >> m;
  std::cin >> l;
  if(s + m*2 + l*3 > 9)
    std::cout << "happy";
  else
    std::cout << "sad";
}
