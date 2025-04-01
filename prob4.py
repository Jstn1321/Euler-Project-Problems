def max_list(list):
    max = list[0]
    for o in range(0, len(list)):
        if list[o] > max:
            max = list[o]
    return max
palindromes = []
for i in range (100, 1001):
    for x in range (i, 1001):
        product = i * x
        product = str(product)
        if len(product) % 2 == 1:
            forward = product[:int(((len(product)/2)))]
            backward = product[int(((len(product)/2)+1)):]
            backward = backward[::-1]
            palinyn = True
            for p in range(0, len(forward)):
                if forward[p] != backward[p]:
                    palinyn = False
            if palinyn == True:
                product = int(product)
                palindromes.append(product)
        else:
            forward = product[:int(len(product)/2)]
            backward = product[int((len(product)/2)-1):]
            backward = backward[::-1]
            palinyn = True
            for p in range(0, len(forward)):
                if forward[p] != backward[p]:
                    palinyn = False
            if palinyn == True:
                product = int(product)
                palindromes.append(product)
print(max_list(palindromes))