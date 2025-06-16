## a2 Mirrored Pairs
## by Dan Shan
run = True;
print("Ready")
while run == True:
    inp = input()
    if inp[0] == "q" and inp[1] == "p":
        print("Mirrored pair")
    elif inp[0] == "p" and inp[1] == "q":
        print("Mirrored pair")
    elif inp[0] == "b" and inp[1] == "d":
        print("Mirrored pair")
    elif inp[0] == "d" and inp[1] == "b":
        print("Mirrored pair")
    elif inp == "  ":
        break;
    else:
        print("Ordinary pair")
