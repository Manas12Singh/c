a = int(input())
b = int(input())

# (a)
r = a**b
print(r)

# (b)
if b != 0:
    r = a/b
    print(r)

# (c)
if b != 0:
    r = a//b
    print(r)

# (d)
c = (a-b/10**2+b*2)
print(c)
