height = int(input())
for i in range(int((height+1)/2)):
    print((1+ 2*i)*"*" + " "*(2*(height -2*i)-2) + (1+ 2*i)*"*")
for i in range(int((height+1)/2)):
    if int((height-2*i)-2) <= 0:
        break;
    else:
        print(int((height-2*i)-2)*"*" + " "*int(4+4*i) + int((height-2*i)-2)*"*")
