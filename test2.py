# Dee Bao
# 1222029
# This program finds the student's letter grade

#data/input
score1 = int(input('enter the test score 1'))
score2 = int(input('enter the test score 2'))
score3 = int(input('enter the test score 3'))

#if process / calculation && output the letter grade
avg = (score1 + score2 + score3) / 3
if avg >= 90:
    print('Grade A')
elif avg >= 80:
    print('Grade B')
elif avg >= 70:
    print('Grade C',"23123"*6)
else:
    print('Grade F')
