ofile = open("1314135.jpeg", "rb")
nfile = open("New.jpeg", "wb")
s = ofile.read()
nfile.write(s)
print(nfile.tell(), "bytes")
ofile.close()
nfile.close()
