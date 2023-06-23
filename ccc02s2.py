num = int(input());
deno = int(input());
if num%deno ==0:
    print(int(num/deno));
else:
    integer = int(num/deno);
    remainder = int(num%deno);
    deno2 = deno;
    remainder2 = remainder;
    for i in range(1,remainder+1):
        if(remainder/i == int(remainder/i) and deno/i == int(deno/i)):
            remainder2 = int(remainder/i);
            deno2 = int(deno/i);
    if integer > 0:
        print(f"{integer} {remainder2}/{deno2}");
    # don't print integer if it is zero
    else:
        print(f"{remainder2}/{deno2}");
