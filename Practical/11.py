l = []
s = 0
n = int(input("Enter the number of elements: "))
print("Enter the elements: ")
for i in range(n):
    e = input()
    l.append(e)
for i in l:
    # if type(eval(i)) in (int,float):
    if isinstance(i, (int, float)):
        s += eval(i)
print("Sum:", s)
