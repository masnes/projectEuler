#Solution for project euler problem 11, largest product in a grid
import pprint
import re

gridText = open("vals.txt")
gridText2 = open("vals.txt")
gridText3 = open("vals.txt")
numRegex = re.compile('[0-9]{2}')
lineNum = -1
wordNum = -1
lineList = []
wordList = []
for line in gridText2:
    lineNum += 1

linecache.getline(array.py, lineNum)



print(lineNum, wordNum)

wordArray = [[0 for k in range(0,30)] for j in range(0,30)]

lineNum = 0

for line in gridText:
    wordNum = 0
    lineNum += 1
    for numRegex in line:
        wordNum += 1
        wordString = numRegex
        #print(wordString)
        #wordFloat = float(wordString)
        #print(wordNum, lineNum)
        print(lineNum, wordNum)
        wordArray[lineNum][wordNum] = 1
#pprint.pprint(wordArray)




