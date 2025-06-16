n1 = int(input())
n2 = int(input())
lst1 = []
lst2 = []
for i in range(n1):
    inp = input();
    lst1.append(inp)
for i in range(n2):
    inp = input();
    lst2.append(inp)
for i in lst1:
    for j in lst2:
        print(f"{i} as {j}")
