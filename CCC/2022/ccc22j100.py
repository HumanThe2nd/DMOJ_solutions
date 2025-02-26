# CCC '22 J2 - Fergusonball Ratings
# Author: HumanThe2nd
# Date: 2023-06-27
inp = input().split();
start = int(inp[0]);
days = int(inp[1]);
print("Sun Mon Tue Wed Thr Fri Sat");
print("    "*(start-1),end =" ")
for i in range(1,days+1):
    if(i<10):
        print(f" {i}",end = "")
    else:
        print(i,end = "")
    if(i == days):
      break;
    elif(i+start-1)%7 ==0:
        print()
        print(" ",end="")
    else:
        print("  ",end="")
print();
