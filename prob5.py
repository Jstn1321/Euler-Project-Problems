i = 20
while True:
    Pass = True
    for k in range(2, 21):
        if i % k != 0:
            Pass = False
            break
    if Pass == True:
        print(i)
        break
    i += 1