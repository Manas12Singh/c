s = input()
s = s.split()
for i in s:
    if i.lower() in ('a', 'an', 'the'):
        s.remove(i)
for i in s:
    print(i+": "+len(i))
