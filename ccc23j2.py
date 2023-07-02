num = int(input())
values = [1500, 6000, 15500, 40000, 75000, 125000]
names = ["Poblano", "Mirasol", "Serrano", "Cayenne", "Thai", "Habanero"]
total = 0
for i in range(num):
  chilli = input()
  total += values[names.index(chilli)]

print(total)
