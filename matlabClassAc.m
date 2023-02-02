array1 = [1,2,3,4,5]
array2 = 1:5
array3 = 3:-2:1
array4 = linspace(1,10,5)
array5 = 1:2:10
array5 = array5 + 5
array5(1) = 5
max(array5)
min(array4)
logicarr = array5 <= 11
logicarr2 = array2 == 2
logicarr3 = array1 ~= 4
array1
array5
arr1 = array1 .* array5
arr1 & array1
array1(1) = 0
array1(2) = 0
arr1(1) = 0
arr1 & array1
array1 | arr1
xor(arr1, array1)
