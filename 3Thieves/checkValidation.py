
def isSafe(side1, side2):
    safe = True
    side1tot = 0
    money1 = 0
    side2tot = 0
    money2 = 0
    if(side1[0] == "A"):
        side1tot += 8
    if(side1[1] == "B"):
        side1tot += 5
    if(side1[2] == "C"):
        side1tot += 3

    if(side2[0] == "A"):
        side2tot += 8
    if(side2[1] == "B"):
        side2tot += 5
    if(side2[2] == "C"):
        side2tot += 3
    for i in range(3,6):
        money1 += side1[i]
        money2 += side2[i]
    if (side1tot<money1 and side1tot != 0) :
        safe =  False
    if (side2tot<money2 and side2tot != 0) :
        safe =  False
    return safe

def sideTrans(side1,side2, j):
        tmp = side1[j]
        side1[j] = side2[j]
        side2[j] = tmp
valid = "C8CCA5AACBC3A8B5CBAAA3BBB5,C3CCA5AACBC3A8B5CBAAA3BBB5,C3CCA5AACBC3A8B5CBAAA5CCC3,C3CCA5AACBC3A8B5BCAAA3BBB5,C3CCA5AACBC3A8B5BCAAA5CCC3,C3CCA5AACBB5A8C3CBAAA3BBB5,C3CCA5AACBB5A8C3CBAAA5CCC3,C3CCA5AACBB5A8C3BCAAA3BBB5,C3CCA5AACBB5A8C3BCAAA5CCC3,C3CCA5AABCC3A8B5CBAAA3BBB5,C3CCA5AABCC3A8B5CBAAA5CCC3,C3CCA5AABCC3A8B5BCAAA3BBB5,C3CCA5AABCC3A8B5BCAAA5CCC3,C3CCA5AABCB5A8C3CBAAA3BBB5,C3CCA5AABCB5A8C3CBAAA5CCC3,C3CCA5AABCB5A8C3BCAAA3BBB5,C3CCA5AABCB5A8C3BCAAA5CCC3,B5BBA3AACBC3A8B5CBAAA3BBB5,B5BBA3AACBC3A8B5CBAAA5CCC3,B5BBA3AACBC3A8B5BCAAA3BBB5,B5BBA3AACBC3A8B5BCAAA5CCC3,B5BBA3AACBB5A8C3CBAAA3BBB5,B5BBA3AACBB5A8C3CBAAA5CCC3,B5BBA3AACBB5A8C3BCAAA3BBB5,B5BBA3AACBB5A8C3BCAAA5CCC3,B5BBA3AABCC3A8B5CBAAA3BBB5,B5BBA3AABCC3A8B5CBAAA5CCC3,B5BBA3AABCC3A8B5BCAAA3BBB5,B5BBA3AABCC3A8B5BCAAA5CCC3,B5BBA3AABCB5A8C3CBAAA3BBB5,B5BBA3AABCB5A8C3CBAAA5CCC3,B5BBA3AABCB5A8C3BCAAA3BBB5,B5BBA3AABCB5A8C3BCAAA5CCC"

allSolutions = valid.split(",")

for i in allSolutions:
    side1 = ["A","B","C",8,5,3]
    place = ["A","B","C",8,5,3]
    side2 = [0,0,0,0,0,0]
    currSide = 1
    wrongMove = False
    for k in range(0, len(i)-1, 2):
        j = i[k]
        j2 = i[k+1]
        if(j=="8" or j=="5" or j=="3"):
            j = int(j)
        if(j2=="8" or j2=="5" or j2=="3"):
            j2 = int(j2)
        if(currSide == 1):
            if(j != j2):
                sideTrans(side1, side2, place.index(j))
                sideTrans(side1, side2, place.index(j2))
            else:
                sideTrans(side1, side2, place.index(j))
            currSide = 2
            
        elif(currSide==2):
            if(j != j2):
                sideTrans(side1, side2, place.index(j))
                sideTrans(side1, side2, place.index(j2))
            else:
                sideTrans(side2, side1, place.index(j))
            currSide = 1
            
        if(not isSafe(side1,side2)):
            wrongMove = True



    if(not wrongMove):
        print("Valid solution!", i)

    else:
        print(" NOT Valid solution!")