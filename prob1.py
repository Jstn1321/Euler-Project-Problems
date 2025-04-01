threeMulti = []
fiveMulti = []
threeSum = 0
fiveSum = 0
for i in range(1, 1000):

    threeAdd = i * 3
    fiveAdd = i * 5
    if threeAdd < 1000:
        threeMulti.append(i * 3)
    if fiveAdd < 1000:
        fiveMulti.append(fiveAdd)

for i in range(len(threeMulti)):
    threeSum += threeMulti[i]
for i in range(len(fiveMulti)):
    fiveSum += fiveMulti[i]

print(threeSum+fiveSum)