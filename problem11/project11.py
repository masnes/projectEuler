#What is the greatest product of four adjacent numbers in the same direction
#(up, down, left, right, or diagonally)
#in the 20 x 20 grid in the vals.txt file?
import sys
import time
initialTimestamp = time.time()
grid = [] #grid for getting input from txt file

with open('vals.txt') as inputfile:
    for line in inputfile:
        grid.append(line.strip().split(' '))

#check that grid contains the right values
"""
printstring = " "
for i in range(1,20):
    printstring = " "
    for j in range(1, 20):
        printstring += str(grid[i][j])
        printstring += " "
    print printstring
"""

values = ""
highestValue = -sys.maxint -1
currentValue = -1
stringValue = ""

a = 0
b = 0
c = 0
d = 0

# Case 1: greatest product left to right or vice versa (note: left to right is the same as right to left)
for i in range(0, 20): #check line
    for j in range(0, 17): #check values in each line - 0, to 16 because 4 values are being checked at a time
        stringValue = (grid[i][j]) + (grid[i][j+1]) + (grid[i][j+2]) + (grid[i][j+3])
        currentValue = int(grid[i][j]) * int(grid[i][j+1]) * int(grid[i][j+2]) * int(grid[i][j+3])
        if currentValue > highestValue:
            highestValue = currentValue
            values = "Line number %d, Column numbers %d, %d, %d, and %d" % (i, j,j+1,j+2,j+3)
            valValues = str(grid[i][j]) + str(grid[i][j+1]) + str(grid[i][j+2]) + str(grid[i][j+3])
print values
print valValues
print highestValue

# Case 2: greatest product up and down lines with the same column
for i in range(0, 17): #check line
    for j in range(0, 20): #check values in each line - 0, to 16 because 4 values are being checked at a time
        stringValue = (grid[i][j]) + (grid[i+1][j]) + (grid[i+2][j]) + (grid[i+3][j])
        currentValue = int(grid[i][j]) * int(grid[i+1][j]) * int(grid[i+2][j]) * int(grid[i+3][j])
        if currentValue > highestValue:
            highestValue = currentValue
            values = "Column number %d, line numbers %d, %d, %d, and %d" % (j, i,i+1,i+2,i+3)
            valValues = str(grid[i][j]) + str(grid[i+1][j]) + str(grid[i+2][j]) + str(grid[i+3][j])
print values
print valValues
print highestValue

# Case 3: greatest product forward and down in a diagonal line
for i in range(0, 17): #check line
    for j in range(0, 17): #check values in each line - 0, to 16 because 4 values are being checked at a time
        stringValue = (grid[i][j]) + (grid[i+1][j+1]) + (grid[i+2][j+2]) + (grid[i+3][j+3])
        currentValue = int(grid[i][j]) * int(grid[i+1][j+1]) * int(grid[i+2][j+2]) * int(grid[i+3][j+3])
        if currentValue > highestValue:
            highestValue = currentValue
            values = "Line number %d, column number %d" % (i, j)
            values += ", Line number %d, column number %d" % (i+1, j+1)
            values += ", Line number %d, column number %d" % (i+2, j+2)
            values += ", Line number %d, column number %d" % (i+3, j+3)
            valValues = str(grid[i][j]) + str(grid[i+1][j+1]) + str(grid[i+2][j+2]) + str(grid[i+3][j+3])
print values
print valValues
print highestValue

# Case 4: greatest product backward and up in a diagonal line
for i in reversed(range(3, 20)): #check line
    for j in range(0, 17): #check values in each line - 0, to 16 because 4 values are being checked at a time
        stringValue = (grid[i][j]) + (grid[i-1][j+1]) + (grid[i-2][j+2]) + (grid[i-3][j+3])
        currentValue = int(grid[i][j]) * int(grid[i-1][j+1]) * int(grid[i-2][j+2]) * int(grid[i-3][j+3])
        if currentValue > highestValue:
            highestValue = currentValue
            values = "Line number %d, column number %d" % (i, j)
            values += ", Line number %d, column number %d" % (i-1, j+1)
            values += ", Line number %d, column number %d" % (i-2, j+2)
            values += ", Line number %d, column number %d" % (i-3, j+3)
            valValues = str(grid[i][j]) + str(grid[i-1][j+1]) + str(grid[i-2][j+2]) + str(grid[i-3][j+3])
print values
print valValues
print highestValue
finalTimestamp = time.time()
print "The time taken is:", finalTimestamp - initialTimestamp, "seconds."
