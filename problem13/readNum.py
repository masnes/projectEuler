# Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

numGrid = [] #grid for getting input from txt file
valGrid = [0 for i in range(0,100)]

with open('numbers.txt') as inputfile:
    for line in inputfile:
        numGrid.append(line.strip())

#check that grid contains the right values
"""
printstring = ""
for i in range(0,100):
    for j in range(0, 50):
        printstring += str(numGrid[i][j])
    printstring += "\n"

print printstring
"""
c = 0
val = 0
d = 0
e = ""
val = 0
valString = "0"

for j in reversed(range(0,50)):
    val = int(valString)
    valString = "0"
    for i in range(0,100):
        val += int(numGrid[i][j])
    valString = str(val)
    print valString
    valGrid[j] = valString[-1:]
    valString = valString[:-1]


print valGrid
print valString
print "The first two numbers are in the second line. From there follow the above grid in order"
