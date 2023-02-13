##Program set 1: Lottery program
##The program randomly generates a two-digit number, prompts the user to enter a single two-
##digit number, and determines whether the user wins according to the following rules. Write a loop to let the user 
##play as many times as the user wanted. Use a sentinel or flag to quit out of the loop. You must pick the correct 
##loop for this question. Each time the user continues to play, the program will generate a new two-digit random 
##number until the user enters -999 to quit. 

import random


win = random.randint(10,100)
firstDig = win // 10
secondDig = win % 10
guess = int(input('Enter your lottery pick ( 2 digits) or -999 to quit:'))
while guess != -999:
    # check user input is valid
    if guess > 99 or guess < 10:
        print('invalid input! \n')
    # determine whether user's data match the win number
    else:
        # if guess match exactly win number
        if guess == win:
            print(win,'\n')
            print('Exact match:  You win $10,000!')
            #check if the first digit of check match the win number
        elif guess // 10 == firstDig or guess // 10 == secondDig:
            #since the exact match checked, if the first number match
            #it will only match one number
            if guess // 10 == firstDig:
                print(win,'\n')
                print('Match one digit:  You win $1,000')
            else:
                if guess % 10 == firstDig:
                    print(win,'\n')
                    print('Match all digits :  You win $3,000')
                else:
                    print(win,'\n')
                    print('Match one digit:  You win $1,000')
            #since first number checked, so if second number match
            #it will only match one number
        elif guess % 10 == firstDig or guess % 10 == secondDig:
            print(win,'\n')
            print('Match one digit:  You win $1,000')
        else:
            print(win,'\n')
            print('Sorry no match')
    guess = int(input('Enter your lottery pick ( 2 digits) or -999 to quit:'))
    win = random.randint(10,100)
    firstDig = win // 10
    secondDig = win % 10
                
                        
                        
                
        
        
