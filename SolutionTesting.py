n = int(input())
n2 = int(input())
yes = False
for i in range(10000):
    if n*i%n2 ==1:
        print(i)
        yes = True;
        break;
if yes == False:
    print("No such integer exists.")