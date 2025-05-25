# CCC '18 S2 - Sunflowers
# Date: 2023-05-17
N = int(input())
lst = []
for i in range(N):
    seed = input().split()
    lst.append(seed)
    

if int(lst[0][0]) > int(lst[0][1]):
    if int(lst[0][0]) > int(lst[1][0]):
        # 180 degrees clockwise
        lst = list(zip(*lst[::-1]))
        lst = list(zip(*lst[::-1]))
    else:
        # 270 degrees clockwise
        lst = list(zip(*lst[::-1]))
        lst = list(zip(*lst[::-1]))
        lst = list(zip(*lst[::-1]))
else:
    if int(lst[0][0]) < int(lst[1][0]):
        # 0 degrees rotated
        output = lst
    else:
        # 90 degrees clockwise
        lst = list(zip(*lst[::-1]))

# If no condition is triggered original matrix is printed
for i in range(N):
    print(*lst[i],sep=" ")
