fp = open("File.txt", "a+")
s = input("Enter the text: ")
fp.write(s)
fp.seek(0)
s = fp.read()
print(s)
fp.close()
