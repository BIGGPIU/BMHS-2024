r'''
Imagine this: You are the president of your coding club and you are creating a problem
that nobody will do nor will anyone listen to you explain. Just to have n##### in your ear about how you dont teach anything.
Now you must sit there and think is it even worth trying to teach half of the midwits that show up or should I just give up 
and go work on my own projects because it feels like you're talking to a brick wall.
Seriously why come to the club if you have no passion, like at all. 
If you cant even be bothered to even pretend to like coding for 45 minutes then being completely honest
You wont make it. You're setting yourself up for failure, and you're wasting your time.
Please do yourself a favor and either focus up or get out.

You must create a function that creates a graph where each element is connected to eachother via the top, bottom, left and right.
Then you must place the gold in the position that that is given to you with goldposition.
your code will be tested with a solution to q12


A graph is similar to a linked list. 
unlike a linked list. graphs are not restricted to only having two connections to each node

for example: if you were to make a doubly linked list you would have each node in the linked list 
have both a Next value and a previous value creating something that would look liked this


/  address: 0XFFF  \      /  address: 0XFFE  \     /  address: 0XFFX  \
|  value: 2        | --\  |  value: 3        | --\ |  value: 4        | 
|  Next: 0XFFE     | --/  |  Next: 0XFFX     | --/ |  Next: 0XFFF     | 
\  previous: 0XFFX /      \  previous: 0XFFF /     \  previous: 0XFFE / 

but for a graph you do not have that restriction. You could have any node connect to any other node you want.
In essence its a linked list with no restrictions.

I know this is a terrible example but I hope it gets the point across at least somewhat well
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


def createGraphfrom2Darray(Array:list,goldposition:list) -> Node:
    pass




























































































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


def myown2(newhead:Node) -> list[Node,int]:
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
        y = myown2(qs[i])
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