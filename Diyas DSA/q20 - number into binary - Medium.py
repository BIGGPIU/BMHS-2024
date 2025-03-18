'''
You are given a number
You must convert the number into binary.
your list should have a length of 8


EXAMPLE 1:

time = 137
answer = [1, 0, 0, 1, 0, 0, 0, 1, 0]

time = 416
answer = [0, 0, 0, 0, 0, 1, 0, 1, 1]

btw it should be formatted like this 
[1,2,4,16,32,64,128,256,512]

'''




def calculateTime(time:int) -> list[int]:
    binary = [0,0,0,0,0,0,0,0,0]





















































































from random import randint

def check():
    for i in range(10):
        x = randint(1,400)
        if calculateTime(x) != calculateTime2(x):
            print(f'''
failed testcase {i}

time: {x}
Your answer: {calculateTime(x)}
Correct answer: {calculateTime2(x)}            
''')

    print ("You passed!")
    return


def calculateTime2(time):
        timeStr = str(time)
        timecopy = time
        binary = [0,0,0,0,0,0,0,0,0]
        if int(timeStr[-1]) in [1,3,5,7,9]:
            binary[0] = 1
            timecopy += -1
        
        for i in range(len(binary)):
            ival = abs(i - len(binary))
            if i == 0:
                continue
            else:
                if timecopy == 0:
                    return binary
                if timecopy - (2**ival) >= 0:
                    binary[ival] = 1
                    timecopy += -(2**ival)
        return binary



if __name__ == "__main__":
    check()