'''
You are given two sorted lists. 
You must merge the two lists while making sure that they stay sorted then return the result.


You are NOT allowed to use any built in sorting functions

Example 1:
list1: [1, 3, 5, 7]
list2: [2, 4, 6, 8]

answer: [1,2,3,4,5,6,7,8]

Restrictions:
lists will never have two of the same number.
'''

def mergeSortedLists(list1:list[int],list2:list[int]) -> list[int]:
    pass















































































































def myown(list1:list[int],list2:list[int]):
    ans = []
    l = 0
    r = 0
    list1.append("X")
    list2.append("X")
    while True:
        if list1[0] == list2[0]:
            break
        

        if list1[0] == "X":
            ans.append(list2.pop(0))
            continue
        if list2[0] == "X":
            ans.append(list1.pop(0))
            continue
        if list1[l] > list2[r]:
            ans.append(list2.pop(0))
        else:
            ans.append(list1.pop(0))
    return ans


def check():
    testcases:list[list[int]] = [
    [[1, 3, 5, 7], [2, 4, 6, 8]],  # Standard merge
    [[4,5,6], [1, 2, 3]],  # One empty list
    [[4, 5, 6], [7,8,9]],  # Other empty list
    [[1, 2, 3], [10, 11, 12]],  # Non-overlapping ranges
    [[-5, -3, -1], [-4, -2, 0]],  # Negative numbers
    [[100, 200, 300], [150, 250, 350]],  # Large numbers
    [[1], [2]],  # Single element lists
    [[99], [42]],  # Single element lists, out of order
    [[10, 30, 50], [20, 40, 60]],  # Alternating elements
    [[-100, 0, 100], [-50, 50, 150]],  # Wide range of numbers
    [[1, 5, 9], [2, 6, 10]],  # Interleaved elements
    [[-10, -5, 0, 5, 10], [-8, -3, 2, 7, 12]],  # Mix of negatives and positives
    [[1, 100, 1000], [50, 500, 5000]],  # Large gaps between numbers
    ]
    for i in range(len(testcases)):

        if mergeSortedLists(testcases[i][0].copy(),testcases[i][1].copy()) != myown(testcases[i][0].copy(),testcases[i][1].copy()):
            pass


if __name__ == "__main__":
    check()