sum = 0
fibSeq = [1,2]
while True:
    fibNum = fibSeq[len(fibSeq)-1] + fibSeq[len(fibSeq)-2]
    if fibNum <= 4000000:
        fibSeq.append(fibNum)
    else:
        break

for i in range(0, len(fibSeq)):
    if (fibSeq[i] % 2 == 0):
        sum += fibSeq[i]

print(sum)