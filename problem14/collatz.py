#collatz numbers:
"""
    if i % 100000 == 0:
        print i
    if n is even: n = n/2
    if n is odd: n = 3n + 1
"""
#Which starting number < 1,000,000 produces the longest collatz sequence?

count = 0
seqStart = 1
seqLongest = 1
seqLongestLength = 0
seq = 0

for i in range(0, 1000000):
    seq = i
    seqStart = i
    count = 0
    while seq > 1:
        count += 1
        if seq % 2 == 0:
            seq = seq/2
        else:
            seq = 3*seq + 1
    if count > seqLongestLength:
        seqLongest = seqStart
        seqLongestLength = count

print seqLongest
print seqLongestLength
