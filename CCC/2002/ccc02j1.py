n = int(input());
def right():
    for i in range(3):
        print(" "*6+"*");
def left():
    for i in range(3):
        print("*");
def lr():
    for i in range(3):
        print("*"+" "*5+"*");
def line():
    print(" * * *");
def rl():
    right();
    line();
def pr():
    print();
    right();
def ll():
    left();
    line();
if n == 0:
    line();
    lr();
    print();
    lr();
    line();
elif n == 1:
    pr();
    pr();
    print();
elif n == 2:
    line();
    rl();
    ll();
elif n == 3:
    line();
    rl();
    rl();   
elif n == 4:
    print();
    lr();
    line();
    right();
    print();
elif n == 5:
    line();
    ll();
    rl();
elif n == 6:
    line();
    ll();
    lr();
    line();
elif n == 7:
    line();
    right();
    print();
    right();
    print();
elif n == 8:
    line();
    lr();
    line();
    lr();
    line();
else:
    line();
    lr();
    line();
    rl();
