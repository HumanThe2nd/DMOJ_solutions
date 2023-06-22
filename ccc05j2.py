start = int(input());
end = int(input());
count = 0;
for i in range(start,end+1):
    factors = 0;
    for j in range(1,i+1):
        if i%j == 0:
            factors += 1;
    if factors == 4:
        count += 1;
print(f"The number of RSA numbers between {start} and {end} is {count}")
