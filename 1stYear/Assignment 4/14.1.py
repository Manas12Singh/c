S1 = "Kent$from$Kentucky".split('$')
print(S1)
s2 = ''
for k in S1:
    if k[0].lower() == "k":
        s2 = k + ' ' + s2
print(s2)
