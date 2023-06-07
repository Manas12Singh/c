l = []
sum = 0
n = int(input("Enter the number of elements: "))
print("Enter the elements: ")
for i in range(n):
    e = eval(input())
    l.append(e)
for i in l:
    if isinstance(i, (int, float)):
        sum += i
print(sum)
