# CCC '23 J2 - Chili Peppers
# Author: HumanThe2nd
# Date: 2023-06-27
num = int(input())
values = [1500, 6000, 15500, 40000, 75000, 125000]
names = ["Poblano", "Mirasol", "Serrano", "Cayenne", "Thai", "Habanero"]
total = 0
for i in range(num):
  chilli = input()
  total += values[names.index(chilli)]

print(total)
