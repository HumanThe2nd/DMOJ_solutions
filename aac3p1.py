n = input().split(" ")
if int(n[0]) < int(n[1]):
     if int(n[2]) < int(n[3]):
        print("Go to the department store")
     else:
        print("Go to the grocery store")   
else:
    if int(n[2]) < int(n[3]):
        print("Go to the pharmacy")
    else:
        print("Stay home")
