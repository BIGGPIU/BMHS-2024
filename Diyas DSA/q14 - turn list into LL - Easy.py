'''
You are given a list of testcases which are also lists. 
You must create your own linked list functionality from scratch and turn the lists into linked lists

Your answer will be checked with a solution to a problem in the past that uses a linked list
'''

def CreateLLfromTree(List):
    pass



































































































def myanswer(head:TreeNode):
    answer = []
    while head.value:
        answer.append(head.value)
        head = head.next
    print(answer)
    return answer

def main() -> str:
    qs = [
        CreateLLfromTree([1,2,3,4,5]),
        CreateLLfromTree([6,2,4,21,6]),
        CreateLLfromTree([8,5,4,3,2,5,9,278,6,8]),
    ]
    answers = [
        [1,2,3,4,5],
        [6,2,4,21,6],
        [8,5,4,3,2,5,9,278,6,8]
    ]

    for i in range(len(qs)):
        if myanswer(qs[i]) != answers(qs[i]):
            return f'''
Failed testcase {i}

Your Answer:
{answers(qs[i])}

Correct Answer:
{myanswer(qs[i])}
            '''

    return "you passed"

if __name__ == "__main__":
    print(main())