years = map(lambda x: 1960+x*10, range(21))

bits = []
j = 4
for i in range(21):
    bits.append(j)
    j *= 2


import math
i = 0
j = 1
f = 1
while i<21:
    j += 1
    f *= j
    if math.ceil(math.log2(f)) > bits[i]:
        print(j-1)
        i+=1
