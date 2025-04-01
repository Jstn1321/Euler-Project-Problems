import math

def find_prime (n):
    primes = []
    for i in range (2, int(math.sqrt(n))):
        if n % i == 0:
            n /= i
            primes.append(i)
    return primes


def smallest(factors):
    for i in range(0, len(factors)):
        max = factors[0]
        if factors[i] > max:
            max = factors[i]

    return max

print(smallest(find_prime(600851475143)))