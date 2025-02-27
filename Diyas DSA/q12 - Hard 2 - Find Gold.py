'''
You are on an island looking for gold.
You must find and return where the gold is located.

Node Structure:
Class Node:
    self.up = Node | None
    self.down = Node | None
    self.right = Node | None
    self.left = Node | None
    self.gold = bool ( if the gold is here, True. If the gold is not here, False )
    self.nick = int ( used for debugging to identify the Node. You must return this value )

Restrictions:
There will always be gold present 

Every row of the linked list will have an equal amount of nodes
as an example this: 
[0,0]
[0]
will never be a test case

>CHALLENGE< 
1. You cannot visit the same node more than once.
2. Implement a X first Search (BFS,DFS) algorithm 
'''
from random import randint
class Node:
    def __init__(self):
        self.up = None
        self.down = None
        self.right = None
        self.left = None
        self.gold = False
        self.nick = randint(0,9999) 


def YARRRGHH11111(newhead:Node) -> Node|int:
    return 2

































































































































































































def createGraphfrom2Darray(Array:list,goldposition:list) -> Node:
    # cycles wasted on this function: 2 hours
    '''
    please enter the goldposition list as an [x,y] list
    '''
    x = Array.copy()
    x[0][0] = Node()
    l = 0
    u = 0
    canmove = False
    # I think this is O(N) complexity well.. without the prints and stuff
    while u != len(Array):
        head:Node = x[u][0]
        # for z in Array:
        #     print(z)

        for i in range(len(Array[u])):
            canmove = False
            if i+1 < len(Array[0]):
                if isNode(x[u][i+1]): #if true
                    head.right = x[u][i+1]
                else:
                    head.right = Node()
                    head.right.left = head
                    x[u][i+1] = head.right
                canmove = True
            if u+1 < len(Array):
                if isNode(x[u+1][i]):
                    head.down = x[u][i+1]
                else:
                    head.down = Node()
                    head.down.up = head
                    x[u+1][i] = head.down
            
            if [i,u] == goldposition:
                head.gold = True
                # print(f"gold node is {head.nick}")
            
            if canmove:
                head = x[u][i+1]
            # if i-1 > 0: I think I dont need these anymore since my code above now just fills in itself for the nodes it creates
            #     head.left = x[u][i-1]
            # if u-1 > 0:


            # canmove = False
            # for z in Array:
            #     print(z)
            # if i+1 < len(Array[0]): # if i + 1 exists
            #     if head.right != Node:
            #         head.right = Node()
            #         head.right = x[u][i+1]
            #     x[u][i+1] = head.right
            #     canmove = True
            # if u+1 < len(Array):
            #     if head.down != Node:
            #         head.down = Node()
            #         head.down = x[u+1][i]
            #     x[u+1][i] = head.down
            # if i-1 > 0:
            #     # head.left = Node() I just realized this backtracks
            #     head.left = x[u][i-1]
            #     x[u][i-1] = head.left
            # if u-1 > 0:
            #     # head.up = Node()
            #     head.up = x[u-1][i]
            #     x[u-1][i] = head.up
            # print("\n")
            
            # if canmove:
            #     head = x[u][i+1]
        u+=1 
    checklist = []
    for z in range(len(Array)):
        checklist.append([])
        for f in range(len(Array[z])):
            checklist[z].append(Array[z][f].nick)
    # for i in checklist:
    #     print(i)
    # print("\n")
    return Array[0][0]

def isNode(check) -> bool:
    try:
        check.gold = check.gold
        return True    
    except:
        return False

def myown(newhead:Node) -> list[Node,int]:
    head = newhead
    visited = [None]
    queue = [head]
    while True:
        head = queue.pop(0)
        if head.gold == True:
            return [head,head.nick]
        else:
            visited.append(head)
            if head.right not in visited:
                queue.append(head.right)
            if head.down not in visited:
                queue.append(head.down)
            if head.left not in visited:
                queue.append(head.left)
            if head.up not in visited:
                queue.append(head.up)
        if len(queue) == 0:
            break
    return "ERR"

        




def check():
    qs = [
        createGraphfrom2Darray(
            [
                [0]
            ],[0,0]
        ),
        createGraphfrom2Darray(
            [
                [1,2,3,4],
                [3,4,5,6],
                [9,2,4,6]
            ],[1,1]
        ),
        createGraphfrom2Darray(
            [
                [0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0]
            ],[3,4] #you know this is my height as well cause im 6'5 I mean 6'4 femenist and also Chris brown listener
        ),
        createGraphfrom2Darray(
            [
                [0,0,0],
                [0,0,0],
                [0,0,0]
            ],[1,1]
        ),
        createGraphfrom2Darray(
            [
            [1, 2, 3, 4],
            [5, 6, 7, 8],
            [9, 10, 11, 12],
            [13, 14, 15, 16]
            ],[3,3]
        )]
    for i in range(len(qs)):
        x = myown(qs[i])
        y = YARRRGHH11111(qs[i])
        if y[0] not in x and y[1] not in x:
            return f'''
Failed testcase {i+1}

Correct answer: {x}
Your answer: {y}
'''
    return "you passed"
    


if __name__ == "__main__":
    # x = createGraphfrom2Darray([
    #     [1,2,3,4],
    #     [3,4,5,6],
    #     [9,2,4,6]
    # ],[1,1])
    # print(myown(x))

    print(check())