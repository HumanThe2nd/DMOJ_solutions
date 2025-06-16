// Alphabet Score
// By: Dan Shan
s = input()
c = 0;
for i in range(0,len(s)):
    c+=ord(s[i])-ord('a')+1
print(c)
