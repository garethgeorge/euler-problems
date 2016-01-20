import numpy as np

MAX_LENGTH = 1500000

# ALOT OF TOP
A = np.matrix([
        [1, -2, 2],
        [2, -1, 2],
        [2, -2, 3]
    ])

B = np.matrix([
        [1, 2, 2],
        [2, 1, 2],
        [2, 2, 3]
    ])

C = np.matrix([
        [-1, 2, 2],
        [-2, 1, 2],
        [-2, 2, 3]
    ])

root = np.matrix([
        [3],
        [4],
        [5]
    ])

print "allocating counts array"
counts = [0 for x in range(MAX_LENGTH + 1)]

def toTupple(columnVector):
    return (int(columnVector[0][0]), int(columnVector[1][0]), int(columnVector[2][0]))

def generateAll(parent):
    t = toTupple(parent)
    
    a1 = t[0]
    b1 = t[1]
    c1 = t[2]
    l = a1 + b1 + c1
    
    if l > MAX_LENGTH:
        return

    for x in range(l, MAX_LENGTH, l):
        counts[x] = counts[x] + 1

    a = A * parent
    b = B * parent
    c = C * parent

    generateAll(a)
    generateAll(b)
    generateAll(c)

print "generating pythagorean tripples"
generateAll(root)
print "finished generating tripples"

count = sum(filter((lambda x: x == 1), counts))
print(count)
