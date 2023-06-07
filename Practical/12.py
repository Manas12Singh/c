l = []
n = int(input("Enter the number of cities: "))
print("Enter the cities: ")
for i in range(n):
    e = input()
    l.append(e)
l = tuple(l)
for i in l:
    print(i)
