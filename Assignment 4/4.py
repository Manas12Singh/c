a = 0b001010101
b = 0b101010111
c = a ^ b
print(c)
c = a & b
print(c)
c = (a | b) >> 2
print(c)
c = ~(a ^ 10)
print(c)

0b100000010
0b1010101
0b1010101
-0b1100000
