lst = [1567, 34.56, "divine", 99.5, 56234, "soul"]
ss1 = ''
for itm in lst:
    if type(itm) is not int and type(itm) is not float:
        ss1 = ss1+itm+' '
print(ss1)
