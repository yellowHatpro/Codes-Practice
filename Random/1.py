from pip import main


def calculateAverage(inputArray):
    sum = 0
    count = 0
    for i in inputArray:
        if i%6==0:
            sum += i
            count+=1
    return sum / count 

print(calculateAverage([444 ,514, 540, 518, 825, 940, 584]))