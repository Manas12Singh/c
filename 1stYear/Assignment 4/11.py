s = input()
d = {}
for i in s:
    d[i] = s.count(i)
for i in d:
    print(f'{i}: {d[i]}')
