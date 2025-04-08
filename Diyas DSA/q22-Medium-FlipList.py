'''
You are given a list.

You must reverse the list 
thats it 

You CANNOT use any pre made reversing algorithms

Challenge:
Complete This problem without creating a new list
'''

#I just said YOU cant use reversed im gonna use it lmao



def reverselist(listToReverse:list[int]):
    pass
























































































































def r109032olsjgewjgowebownopwfwjllbjwgoiwjglnlkjwgsgdsgIamjustmakingithardforyoutotypethismanuallyyoucouldprobablyusethevscodethingthatlikeautofillsvariablesbutIdontknowifitiwillworkforvariablesthislongidkmanitsworthashot(testlist):
    testlist.reverse()
    return testlist



def myanswer(testlist:list[int]):
    return r109032olsjgewjgowebownopwfwjllbjwgoiwjglnlkjwgsgdsgIamjustmakingithardforyoutotypethismanuallyyoucouldprobablyusethevscodethingthatlikeautofillsvariablesbutIdontknowifitiwillworkforvariablesthislongidkmanitsworthashot(testlist)




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
        if reversed(testcases[i].copy()) != myanswer(testcases[i].copy()):
            return f'''
failed testcase {i}+1

testList:
{testcases[i]}

Your answer: 
{reverselist(testcases[i].copy())}

Correct answer:
{myanswer(testcases[i].copy())}
'''
    return "You passed!"





if __name__ == "__main__":
    print(check())


