n = int(input());
count = 0;
for i in range(n):
    inp = input()
    while int(inp) > 9:
        for i in range(len(inp)):
            count += int(inp[i]);
        inp = str(count);
        count = 0;
    print(inp)
