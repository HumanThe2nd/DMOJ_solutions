n = int(input());
t = s = 0;
for i in range(n):
    str = input();
    for j in str.lower():
        if j == "t":
            t+=1;
        elif j == "s":
            s+=1;
if s >= t:
    print("French");
else:
    print("English");
