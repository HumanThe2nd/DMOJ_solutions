run = True;
while run == True:
    inp = int(input()); 
    if inp == 0:
        break;   
    if inp**0.5 == int(inp**0.5):
        side = int(inp**0.5)
        # square
        print(f"Minimum perimeter is {4*side} with dimensions {side} x {side}")
    else:
        min = 99999999999999999999999999999999999999999999999999999999999;
        # check all combinations if not sqaure
        for i in range(1,int(inp**0.5)+1):
            if inp%i == 0 and 2*inp/i+2*i < min:
                x = i
                y = int(inp/i)
                min = int(2*inp/i+2*i);
        print(f"Minimum perimeter is {min} with dimensions {x} x {y}")
