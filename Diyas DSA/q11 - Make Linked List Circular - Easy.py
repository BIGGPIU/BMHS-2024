"""
For this problem you have to make a linked list circular

or to put it in simple terms make the first item in the linked list go to the last item in the linked list

this problems basically the same no matter what you do so theres only one test case

You can return any node of your answer once you are finished

"""

class TreeNode:
    def __init__(self, value=None,next=None):
        self.value = value
        self.next = next

def circular(head:TreeNode) -> list[int]:
    pass



















































































































































































































































































































































































''' my answer
first_head = head
    while head.next.value != None:
        print(head.next)
        print(head.value)
        head = head.next
    head.next = first_head
    return first_head
'''


def CreateLLfromTree(List):
    head = TreeNode(List[0])
    pointer = TreeNode()
    head.next = pointer
    i = 1 
    while i != len(List):
        pointer.value = List[i]
        pointer.next = TreeNode()
        pointer = pointer.next
        i+=1
    return head

def myanswer(head:TreeNode):
    visited = []
    while head.next != None:
        visited.append(head)
        head = head.next
        if head in visited:
            return True
    return False

def main() -> str:
    qs = [
        CreateLLfromTree([1,2,3,4,5])
    ]
    x = circular(qs[0])
    if not myanswer(x):
        return f'''
Failed testcase {1}
        '''

    return "you passed"

if __name__ == "__main__":
    print(main())