s=input()
ofile = open(s, "r")
nfile = open("New.txt", "w")
s = ofile.read()
nfile.write(s)
ofile.close()
nfile.close()