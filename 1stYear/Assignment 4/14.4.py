dict1 = {}
wrd = "Expand your horizon"
words = wrd.split()
for w in words:
    dict1[w] = dict1.get(w, len(w))
print(dict1)
