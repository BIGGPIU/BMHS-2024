'''
You are given a 2D array, you must find the character at the middle of the array and return it.

For this problem you should always round Down.

Restrictions:
arrays will be the same length and width.
'''
from math import floor #floor rounds down


def intersection(array:list[list[str]]) -> str:
    pass
    






















































































































































def myown(array:list[list[str]]) -> str:
    centerY = floor(len(array)/2)
    centerX = floor(len(array[centerY])/2)
    return array[centerY][centerX]

def check():
    qs = [
        [['a', 'b', 'c'], 
 ['d', 'e', 'f'], 
 ['g', 'h', 'i']],
 [['a', 'b', 'c', 'd'], 
 ['e', 'f', 'g', 'h'], 
 ['i', 'j', 'k', 'l'], 
 ['m', 'n', 'o', 'p']],
 [['a', 'b', 'c', 'd', 'e']],
 [['a'], 
 ['b'], 
 ['c'], 
 ['d'], 
 ['e']],
 [['a', 'b', 'c', 'd', 'e'], 
 ['f', 'g', 'h', 'i', 'j'], 
 ['k', 'l', 'm', 'n', 'o'], 
 ['p', 'q', 'r', 's', 't'], 
 ['u', 'v', 'w', 'x', 'y']],
 [['a', 'b'], 
 ['c', 'd']],
 [['a', 'b', 'c', 'd'], 
 ['e', 'f', 'g', 'h'], 
 ['i', 'j', 'k', 'l']],
 [['a', 'b'], 
 ['c', 'd'], 
 ['e', 'f'], 
 ['g', 'h'], 
 ['i', 'j']],
 [['a', 'b', 'c', 'd', 'e', 'f'], 
 ['g', 'h', 'i', 'j', 'k', 'l'], 
 ['m', 'n', 'o', 'p', 'q', 'r'], 
 ['s', 't', 'u', 'v', 'w', 'x'], 
 ['y', 'z', 'a', 'b', 'c', 'd'], 
 ['e', 'f', 'g', 'h', 'i', 'j']],
 [['a', 'b', 'c', 'd', 'e', 'f', 'g'], 
 ['h', 'i', 'j', 'k', 'l', 'm', 'n'], 
 ['o', 'p', 'q', 'r', 's', 't', 'u'], 
 ['v', 'w', 'x', 'y', 'z', 'a', 'b'], 
 ['c', 'd', 'e', 'f', 'g', 'h', 'i'], 
 ['j', 'k', 'l', 'm', 'n', 'o', 'p'], 
 ['q', 'r', 's', 't', 'u', 'v', 'w']],
 [['a']]
    ]
    for i in range(len(qs)):
        print(myown(qs[i]))
    for i in range(len(qs)):
        if myown(qs[i]) != intersection(qs[i]):
            return f'''
failed testcas: {i+1}

Correct answer: {myown(qs[i])}
Your answer: {intersection(qs[i])}

array: {qs[i]}
'''
    return "You passed"


if __name__ == "__main__":
    print(check())