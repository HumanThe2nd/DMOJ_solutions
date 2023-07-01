n = int(input());
cmax = 0;
nmax = 0;
for i in range(n):
    inp = input().split();
    x = int(inp[0]);
    y = int(inp[1]);
    if x*y > cmax: cmax = x*y;
n = int(input());
for i in range(n):
    inp = input().split();
    x = int(inp[0]);
    y = int(inp[1]);
    if x*y > nmax: nmax = x*y;
if nmax > cmax: print("Natalie");
elif cmax > nmax: print("Casper");
else: print("Tie");
