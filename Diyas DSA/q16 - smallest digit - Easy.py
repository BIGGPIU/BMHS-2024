'''
you are given an unsorted list of numbers 
you must go through the list and return the smallest number in the list
you are not allowed to sort the list
I will be checking
Yes this is the exact same question but with smallest instead of largest
2 in one :)
'''


def largestDigit(testList:list[int]) -> int:
    pass


























































































































#end

def myanswer(testlist):
    ans = testlist[0]
    for i in testlist:
        ans = min(i,ans)
    return ans

def check():
    testcases = [
        [0, -1, -2, -3],
        [1000000, 999999, 1000001, 500000],
        [5, 5, 5, 5, 5],
        [7],
        [4, 8, 8, 2, 8, 5],
        [12, -5, 0, -10, 25, 3],
        [-10, -3, -5, -1, -7],
        [3, 1, 7, 5, 9, 2]
    ]
    # for i in testcases:
    #     print(myanswer(i.copy()))
    for i in range(len(testcases)):
        if largestDigit(testcases[i].copy()) != myanswer(testcases[i].copy()):
            return f'''
failed testcase {i}+1

testList:
{testcases[i]}

Your answer: 
{largestDigit(testcases[i].copy())}

Correct answer:
{myanswer(testcases[i].copy())}
'''
    return "You passed!"





if __name__ == "__main__":
    print(check())