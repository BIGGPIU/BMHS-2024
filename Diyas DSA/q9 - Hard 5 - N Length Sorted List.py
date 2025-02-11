'''
You are given one larger list of presents to give out. you must return a sorted list of the Nth largest presents so you can give them out first.
It does not matter if the solution is sorted least to greatest or greatest to least.


EXAMPLE 1:

N = 3 
l = [1,2,3,4,5]

ANSWER:
[3,4,5]

EXAMPLE 2:
N = 1
l = [100,2,5,6]

ANSWER:
[100]

Restrictions

1 < N < 10
1 < l < 100
1 < len(l) < 20
The list will contain no duplicates

>> CHALLENGE <<
Complete this problem without using any pre made sorting algorithms 
ex: .sorted, natsort

Suggested Approaches:
Stack
'''




def nthlargestnumbers(N:int,l:list) -> list:
    return []






























































def myanswer(N,l) -> list:
    # this algo probably exists already but im gonna call it swapsort
    # or would stacksort be a better name
    # I thought of it while on kairos. Giving a man no leetcode will make him insane
    # The idea is that this iterates through the entire list less in exchange for more memory
    # It probably fails with larger datasets
    # wait is this just quicksort
    # SPACE COMPLEXITY
    # 0(N^log(M)) I think where M is the length of the original list and N is the required size
    # according to chatgpt this is O(N^2) yeah I wasnt cooking anything
    newlist = []
    
    for i in range(N):
        newlist.append(0)

    max = len(l)
    i = 0
    nlp = 0 #newlistpointer
    while i != max:
        if l[i] > newlist[nlp]:
            l.append(newlist[nlp])
            newlist[nlp] = l[i]
            max += 1
            i += 1
            nlp = 0
            continue
        elif l[i] <= newlist[nlp]:
            nlp+=1
            if nlp == N:
                nlp = 0 
                i += 1

    return newlist


def check():
    x = [
        [10,[5,1,2,6,3,7,8,9,12,10,15,21,16,20,17]],
         [1,[1]],
         [3,[1,2,3,4,5]],
         [2,[100,2,5,6]],
         [6,[30,4,29,32,37,19,31,21,29]],
         [7,[33,27,9,2,6,26,38,49,13,4,17,13]],
         [3,[20,9,3,18,34,14]]
         ]
    z = 0 
    for i in x:
        z+=1
        if myanswer(i[0],i[1].copy()) != nthlargestnumbers(i[0],i[1].copy()):
            if myanswer(i[0],i[1].copy()) != nthlargestnumbers(i[0],i[1].copy()).reverse():
                return f'''
Failed Testcase {z}

N: {i[0]}
l: {i[1]}

Your Answer:
{nthlargestnumbers(i[0],i[1])}

Correct Answer:
{myanswer(i[0],i[1])}
            '''

    return "You passed"



if __name__ == "__main__":
    print(check())