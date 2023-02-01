import random
print('Three doors ahead ...') 
print('A ghost behind...') 
print("Which door do you open?") 
guess = int(input('1, 2, or 3? :>'))
ghost = random.randint(1,3)
score = 0
while ghost != guess:
    ghost = random.randint(1,3)
    print('\nThree doors ahead ...') 
    print('A ghost behind...') 
    print("Which door do you open?") 
    guess = int(input('1, 2, or 3? :>'))
    score+=1
print('\nGhost!')
print('your score is',score)
