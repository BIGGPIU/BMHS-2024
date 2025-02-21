'''
You are given a string, you musts return True if it is a palindrome, otherwise return false

A palindrome is a string that reads the same forwards and backwards. 
It also ignores all spaces

EXAMPLE 1

String = Was it a car or a cat I saw
Answer:
True

EXAMPLE 2

String = tab a cat

Answer:
False


Credits to Neetcode.io for providing the question and example
'''
def Palindrome(string:str):
    pass














































































































































































def check():
    testcases = [
        "repaper",
        "deed",
        "peep",
        "wow",
        "noon",
        "civic",
        "racecar",
        "level",
        "mom",
        "bird rib",
        "taco cat",
        "ufo tofu",
        "borrow or rob",
        "Never odd or even",
        "we panic in a pew.",
        "wont lovers revolt now",
        "ma is a nun as I am",
        "Dont nod",
        "Sir I demand I am a maid named Iris",
        "Was it a car or a cat I saw?",
        "Yo Banana Boy",
        "Eva can I see bees in a cave",
        "Madam in Eden Im Adam",
        "A man a plan a canal Panama",
        "Never a foot too far even" 
        "Red roses run no risk sir on Nurses order" 
        "He lived as a devil eh"
        "Ned, I am a maiden"
        "Now sir a war is won"
        "Evade me Dave"
        "Dennis and Edna sinned" 
        "Step on no pets",
        "Hello world",
        "BMHS",
        "java sucks",
        "firefox",
        "How much does neovim cost",
        "I just think vscode is better man",
        "ubuntu",
        "nice try nerd dont just return true every time",
        "XXX"
    ]
    y = 0
    for i in testcases:
        y+=1
        x = i.lower()
        if myown(i) != Palindrome(i):
            return f'''
            Failed Testcase {y}

            Tastcase:
                String = {i}

            Your Answer: 
            {Palindrome(i)}

            Correct Answer:
            {myown(i)}
            '''





def myown(string):
    string.replace(" ","")
    for i in range(len(string)):
        hold = string[i]
        hold2 = string[-i-1]
        if string[i] == string[-i-1]:
            pass
        else:
            return False
    return True



if __name__ == "__main__":
    print(check())