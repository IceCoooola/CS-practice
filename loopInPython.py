#input
start = int(input('enter the start number>: '))
end = int(input('enter the end number>: '))
#print header
print('Number','Square')
print('-'*13)
#loop
for start in range(start, end+1):
    print(format(start, '6'), format(start*start, '6'))

