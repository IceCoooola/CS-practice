% exam review
% exam review
clear;clc;

% 6
fid = fopen("home.txt",'r');
if fid == -1
    disp("failed open file");
else
    line1 = fgetl(fid);
    line2 = fgetl(fid);
    line3 = fgetl(fid);
    yearArr = split(line1);
    incomeArr = split(line2);
    homePriceArr = split(line3);
    year = [];
    ratio = [];
    for i = 1:length(yearArr)
        year(i) = str2num(yearArr{i})
        ratio(i) = str2num(homePriceArr{i}) / str2num(incomeArr{i});
    end
    mat = [year ; ratio]
    save newHome.txt mat -ascii
    fc = fclose(fid);
    if fc == -1
        disp("close failed.");
    else
        disp("file closed.")
    end
end


% some provided variables.

fid = fopen("sales.txt",'r');
if fid == -1
    disp("failed open file");
else
    data = textscan(fid, "%d %d");
    profit = data{:, 2} - data{:, 1};
    ttlQuater = length(profit);
    netProfit = sum(profit);
    profitable = profit((profit > 0));
    len = length(profitable);
    fprintf("Records collected from the last %d quarters show that the company \n" + ...
        "has been profitable only in %d quarters. \n" + ...
        "The total net profit was equal to: $%d dollarAmount\n",ttlQuater,len, netProfit);

end

W = 100;
lc = 2;
lp = 2;
% set up the equation
d = 0.3;
minimumT = W*lc*lp/d/sqrt(lp^2-d^2);
minimum_d = 0.3;
while d <= 1.8
    T = W*lc*lp/d/sqrt(lp^2-d^2);
    if T < minimumT
        minimum_d = d;
        minimumT = T;
    end
    d = d + 0.1;
end
fprintf("the minimum tension distance is : %.2f, Tension is %.2f\n",minimum_d,minimumT);


clear;clc;
fid = fopen("cars.txt","r");
if fid == -1
    disp("Open file failed!");
else
    Aline = fgetl(fid);
    Aline = fgetl(fid);
    fw = fopen("Wewcars.txt","w");
    if fw == -1
        disp("open file failed.")
        exit(-1)
    end
    while Aline ~= -1
        data = split(Aline)';
        mile = str2num(data{3});
        cost = str2num(data{5});
        accident = str2num(data{4});
        if mile > 90000
            cost = cost - 2000;
        end
        if mile < 30000
            cost = cost + 4000;
        end
        cost = cost - accident * 1000;
        % write into file
        fprintf(fw,"%s, %s, %d, %d, %d\n",data{1},data{2},mile,accident,cost);


        Aline = fgetl(fid);
    end
    fcd = fclose(fid);
    if fcd == -1
    else
        disp("file closed.");
    end
    fc2 = fclose(fw);
end

clear;clc;
fid = fopen("cars.txt","r");
if fid == -1
    disp("Open file failed!");
else
    fgetl(fid);
    data = textscan(fid,'%s %d %d %d %d');
    % make year mileage accidents cost
    make = data{1};
    year = data{2};
    mile = data{3};
    accidents = data{4};
    cost = data{5};
    for i = 1 : length(mile)
        if mile(i) < 30000
            cost(i) = cost(i) + 4000;
        end
        if mile(i) > 90000
            cost(i) = cost(i) - 2000;
        end
        cost(i) = cost(i) - accidents(i) * 1000;
    end
    % close file
    fc = fclose(fid);
    if fc == -1
        disp("close file failed!");
    else
        disp("file closed.");
    end
%     % save into new files.
%     newMat = [year, mile, accidents, cost]
%     save newcars.txt make -ascii
    fid = fopen("newcars.txt","w");
    if fid == -1
        disp("Open file failed!");
    else
        for i = 1 : length(make)
        fprintf(fid, "%s, %d, %d, %d, %d\n",make{i}, year(i), mile(i),accidents(i),cost(i));
        end
        fclose(fid);
    end
end


clear;clc;

[nums, txt] = xlsread("cars.xls.xlsx")
title = txt(1, :)
year = nums(:,1);
mile = nums(:,2);
accident = nums(:,3);
price = nums(:,4);

make = txt(:, 1);
make(1) = [];

for i = 1 : length(mile)
    if mile(i) < 30000
        price(i) = price(i) + 4000;
    end
    if mile(i) > 90000
        price(i) = price(i) - 2000;
    end
    price(i) = price(i) - accident(i) * 1000;
end
xlswrite("newCar.xlsx",title,1,'A1:E1')
xlswrite("newCar.xlsx",make,1,'A2:A5')
xlswrite("newCar.xlsx",year,1,'B2:B5')
xlswrite("newCar.xlsx",mile,1,'C2:C5')
xlswrite("newCar.xlsx",accident,1,'D2:D5')
xlswrite("newCar.xlsx",price,1,'E2:E5')

% exam review
clear;clc;
% 1. 

[nums, txt] = xlsread("cars.xls.xlsx")

year = nums(:,1)'
mile = nums(:,2)'
accident = nums(:,3)'
price = nums(:,4)'

make = txt(:, 1)
make(1) = []

for i = 1 : length(mile)
    fprintf('i = %d\n',i)
    fprintf('mile = %d\n',mile(i))
    if mile(i) < 30000
        fprintf('price = %d\n',price(i))
        price(i) = price(i) + 4000
    end
    if mile(i) > 90000
        price(i) = price(i) - 2000
    end
    price(i) = price(i) - accident(i) * 1000
end


    

% for i = 1:100
% %    writeDigitalPin(a, 'D10', 1)
%     writeDigitalPin(a, 'D13', 1)
%     pause(0.1)
%     writeDigitalPin(a, 'D9', 1)
%     pause(0.2)
% %    writeDigitalPin(a, 'D10', 0)
%     writeDigitalPin(a, 'D13', 0)
%     pause(0.2)
%     writeDigitalPin(a, 'D9', 0)
%     pause(0.1)
% end

step = 1/20;

writeDigitalPin(a, 'D9', 0);
for i = 1:20
    writePWMDutyCycle(a, 'D9', i * step);
    writePWMDutyCycle(a, 'D11', i * step);
    pause(0.1);
end

for i = 1:20
    writePWMDutyCycle(a, 'D9', 1 - i * step);
    writePWMDutyCycle(a, 'D11', 1 - i * step);
    pause(0.1);
end

v = readVoltage(a, 'A0');

tempK = SteinhartVoltagetoTemp5V(v);
tempC = tempK - 273.15;
tempF = 9/5 * tempC +32;
disp(tempF);

function tempK = SteinhartVoltagetoTemp5V(voltage)
    seriesResist = 10000;
    thermistorResist = 10000;
    resistance = seriesResist * voltage ./ (5-voltage);
    A1 = 3.354016E-03;
    B1 = 2.569850E-04;
    C1 = 2.620131E-06;
    D1 = 6.383091E-08;

    resRatio = log(resistance ./ thermistorResist);
    tempK = 1./ (A1 + B1.* resRatio + C1 .* resRatio.^ 2 + D1.*resRatio.^3);
end


plot(1, 2, 'r*');
ylabel = [2 4 6 8 9 12];
plot(ylabel);
x = [2,7,8,10,15,22];
plot(x, ylabel);

clc;clear;clf;
angle = 45;
v = 35;
g = 9.8;
t = (0:0.1:5);
x = v * cosd(angle) * t;
y = v * sind(angle) * t - 0.5 * g * t.^ 2;
plot(x, y);
hold on;
xlabel('haha')
ylabel('heihei')
plot(x, y, 'rd');
plot(x, y, 'm*');
grid on;
hold off;

clc;clear;clf;

for i = 1:2
    x = linspace(0, 2*pi, 10 * i);
    y = sin(x);
    subplot(1,2,i);
    plot(x, y, 'ko');
    ylabel('sin(x)');
    title(sprintf('%d Points',10*i));
end
    




plot(2,3,'r*');

y = [2 4 9 10 12];
plot(y);

x = [2 4 6 8 10];
plot(x,y);


% class act 4
% classmatesInfo.m
% Author: Dee Bao


% how many classmates info need to add
classmatesNo = 3;
% open the file with writting mode
f = fopen('classmates_formatted.dat', 'w');
% check if file opened
if f == -1
    disp("File open failed!");
else
    disp("File opened successfully.")
    % loop to write the file
    for i = 1:classmatesNo
        % input the data
        first = input("enter the first name>: ", "s")
        last = input("enter the last name>: ", "s")
        numSibling = input("enter the number of siblings>: ")
        favorAct = input("enter the favorite sport / activitys>: ", "s")
        % write it into the file
        fprintf(f, '%s %s %d %s\n', first, last, numSibling, favorAct);
    end
    % close the file
    cf = fclose(f);
    % check if file closed successfully
    if cf == -1
        disp("File closed failed!");
    else
        disp("File closed.");
    end
end

% class act 5
% patientFromExcel.m
% Author: Dee Bao
% read the excel sheet
[nums, txt] = xlsread('patientFromExcel.xlsx');
% extract the age
age = nums(:,1);
%extract the weight
weight = nums(:,2);
% calculate the average age
avgAge = sum(age) / length(age);
% calculate the average weight
avgWeight = sum(weight) / length(weight);
% write the header into the excel sheet
xlswrite("patientFromExcel.xlsx",{"Average Age"}, 1, 'F1');
xlswrite("patientFromExcel.xlsx", {"Average Weight"}, 1, 'G1');
% write the data into the excel sheet
xlswrite("patientFromExcel.xlsx", avgAge, 1, 'F2');
xlswrite("patientFromExcel.xlsx", avgWeight, 1, 'G2');


% class act 3
% phoneNumbers.m
% Author: Dee Bao

% open the file
f = fopen('phones.dat', 'r');

% check if file opended 
if f == -1
    disp("File did not open.");
else
    disp("File opened successfully.");
    % get each line of the file
    aline = fgetl(f);
    % read all the data from the file
    while aline ~= -1      % while feof(fid) == 0
        % check if it is a valid number
        if length(aline) ~= 10
            disp("%s is Not A valid Phone Number!!", aline)
        else
        % print it into correct format, 3 numbers - 3 numbers - 4 numbers
        fprintf("%s-%s-%s\n", aline(1:3), aline(4:6), aline(7:10));
        end
        % read another line
        aline = fgetl(f);
    end
    % close the file
    cf = fclose(f);
    % check if file closed successfully
    if cf == -1
        disp("File closed failed!");
    else
        disp("File closed successfully.");
    end
end

% class act 1
% convertTempFileIO.m
% Author: Dee Bao

% create new matrix
newMat = [8,55;10,70;12,78;14,76;16,70;18,63;20,55]
% save it.
save tempF.dat newMat -ascii

% load the data
tempF = load('tempF.dat')
% convert F to C
tempC = [tempF(:,1) ,(tempF(:,2) - 32) ./ 9 .* 5]
% save the temp C data
save tempC.dat tempC -ascii


% class act 1
% convertTempFileIO.m
% Author: Dee Bao

% create new matrix
newMat = [8,55;10,70;12,78;14,76;16,70;18,63;20,55]
% save it.
save tempF.dat newMat -ascii

% load the data
tempF = load('tempF.dat')
% convert F to C
tempC = [tempF(:,1) ,(tempF(:,2) - 32) ./ 9 .* 5]
% save the temp C data
save tempC.dat tempC -ascii

function TimeHrMin = SetTimeConstruct( hoursVal, minutesVal)

    % Your code goes here %
    if (hoursVal >= 0 && hoursVal <= 24)
        TimeHrMin.hours = hoursVal;
    else
        TimeHrMin.hours = 0;
    end
    if (minutesVal >= 0 && minutesVal <= 60)
    TimeHrMin.mins = minutesVal;
    else
        TimeHrMin.mins = 0;
    end
        
end

function floorNumber = FindFloor(lastName)

    lastName = lower(lastName);
    % Your code goes here
    switch lastName
        case 'lovelace'
            floorNumber = 1;
        case 'hooper'
            floorNumber = 2;
        case 'snyder'
            floorNumber = 2;
        case 'mcNulty'
            floorNumber = 3;
        otherwise
            floorNumber = -1;
    end
    
end

function TimeHrMin = SetTimeConstruct( hoursVal, minutesVal)

    % Your code goes here %
    if (hoursVal >= 0 && hoursVal <= 24)
        TimeHrMin.hours = hoursVal;
    else
        TimeHrMin.hours = 0;
    end
    if (minutesVal >= 0 && minutesVal <= 60)
    TimeHrMin.mins = minutesVal;
    else
        TimeHrMin.mins = 0;
    end
        
end

function tempVal = ConvertToDecadesAndYears( totalYears)
   tempVal.decades = floor(totalYears ./ 10);
   tempVal.years = rem(totalYears, 10);
   % your solution goes here %;
    
end
TimeDecadesYears = []; 
TimeDecadesYears = ConvertToDecadesAndYears(24)
function pizzasInStore = CreateArrayOfStructure(numberCalofBBQ)
 %  Barbecue pizza, the ingredients are Beef, chicken, bacon, barbecue sauce ....
 %   and the calories equals an integer variable.  
 % pizzasInStore.name(1) = "Barbecue";
  %pizzasInStore.name(2) = "Carbonara";
  %pizzasInStore.name(3) = "Ham and Cheese";
  %pizzasInStore.ingredients(1) = "Beef, chicken, bacon, barbecue sauce";
 % pizzasInStore.ingredients(2) = "Mushrooms, onion, creamy sauce";
 % pizzasInStore.ingredients(3) = "Ham, cheese, bacon";
  %pizzasInStore.calories(1) = numberCalofBBQ;
  %pizzasInStore.calories(2) = 25;
  %pizzasInStore.calories(3) = 30;
 
  % pizzasInStore.name = "Barbecue";
  % pizzasInStore.ingredients = "Beef, chicken, bacon, barbecue sauce";
  % pizzasInStore.calories = numberCalofBBQ;
 
 pizzasInStore = repmat(struct("name", "Barbecue", "ingredients", "Beef, chicken, bacon, barbecue sauce", "calories", numberCalofBBQ),1,3);
 %  Carbonara pizza, the ingredients are Mushrooms, onion, creamy sauce ...
 %   and the calories equals 5 calories less that the Barbecue pizza. 
 pizzasInStore(1) = struct("name", "Barbecue", "ingredients", "Beef, chicken, bacon, barbecue sauce", "calories", 30); 
 
 pizzasInStore(2) = struct("name", "Carbonara", "ingredients", "Mushrooms, onion, creamy sauce", "calories", 25); 
 %  Ham and Cheese pizza, the ingredients are Ham, cheese, bacon ...
 %   and the calories equals that of the Barbecue pizza
 pizzasInStore(3) = struct("name", "Ham and Cheese", "ingredients", "Ham, cheese, bacon", "calories", 30);
    
%  Your code goes here % 

end

clear;clc;
%input and create a structure
studentInfo.firstname = input("Please enter the first name:>","s");
studentInfo.lastname = input("Please enter the last name:>","s");
studentInfo.studentNo = input("Please enter the studnet ID number:>","s");
studentInfo.GPA = input("Please enter the GPA:>");
disp(studentInfo)

clear;clc;
% create a cell array
cellArr = cell(2,2);
% assign value to cell array
cellArr = {1 "abc" ; "def" 4}

clear;clc;
% create the cell array
exclaimCell = {'Bravo! ', "Fantastic job! ", 'Great job! ', "Way to go! "};
% get the length of the cell arr
len = length(exclaimCell);
% pick a random number from 1 to len and display it.
num = randi(len);
disp(exclaimCell{num});

% input informations
clear;clc;
parts(3) = struct("partno", 106, "quantity", 20, "costper", 7.5);
parts(2) = struct("partno", 142, "quantity", 1, "costper", 150);
parts(1) = struct("partno", 123, "quantity", 4, "costper", 33);

for i = 1:length(parts)
    if i == 1 
        fprintf('Part No    Total Cost (USD)\n');
    end
    totalCost = parts(i).quantity .* parts(i).costper;
    fprintf("%d        %.2f\n",parts(i).partno, totalCost);
end

function s2 = RemoveConsonants(s1)
    s1 = char(s1);
    isFound = ismember(['a', 'i', 'u', 'e', 'o'], lower(s1));
    % strfind(lower(s1), ['a', 'i', 'u', 'e', 'o']);
    ret = strcmpi(['a', 'i', 'u', 'e', 'o'],lower(s1));
    s2 = s1(ret);
    % Your solution goes here %
    
end



function multResult = MultiplyString(inputString)
    inputString = erase(inputString, 'times');
    inputString = split(inputString);
    inputString = str2double(inputString); 
    multResult = inputString(1) * inputString(2);
   % Your solution goes here
   
end

function out = isPassCode(passCode)
    if length(find(isstrprop(passCode, 'upper'))) > 0 & length(find(isstrprop(passCode, 'lower'))) > 0 & length(find(isstrprop(passCode, 'punct'))) > 0 & length(find(isstrprop(passCode, 'digit'))) > 0
        out = true;
    else 
        out = false;
    end
 % You code goes here
 
end

user_score = 0;
simon_pattern = 'RRGBRYYBGY';
user_pattern  = 'RRGBBRYBGY';

for i=1:10
    if simon_pattern(i) == user_pattern(i)
          user_score =  user_score+1;
        
          % Your code goes here
    else
        break;
    end
end
fprintf('User score:   %d \n',user_score)



function outputMatrix = timesTable( sizeOfTable)

    % Insert code to determine the size of the times table
    sizeOfTable = round(abs(sizeOfTable));
    % Insert code to initialize the table by filling all entries with zeros
    outputMatrix = zeros(sizeOfTable);
    % Insert code to fill the first column and first row with consecutive integers 
    % starting with 1
    outputMatrix(:, 1) = 1:sizeOfTable';
    i = 2;
    while i <= sizeOfTable
        outputMatrix(:, i) = outputMatrix(:, 1) .* i;
        i = i + 1;
    end
    % Use a loop structure to fill the remaining entries in the times table
    
end

student = 1:20
test1 = [68 83 61 70 75 82 57 5 76 85 62 71 96 78 76 68 72 75 83 93 201 42 402]
std(test1)
var(test1)
mean(test1)
mean([12 12 12])

test1(rem(test1, 2) == 0 & rem(test1, 3) ==0 & test1 < 200)
max(test1(mod(test1, 5) == 0))

num = 2
switch num
    case -1
        disp('f3')
    case 0
        disp('f2')
    case 1
        disp('f2')
    case 2
        disp('f2')
    case 3
        disp('f4')
    otherwise
        disp('f1')
end

if num < -2 || num > 4
    disp('f1')
else
    if num <= 2
        if num >= 0
        disp('f2')
        else
        disp('f3')
        end
    else
        disp('f4')
    end
end


% problem 6
x = linspace(0,25,100)
linspace(0,3,5)
sum([1,2,3,4,5])
x = exp(x)

sum(x)


num = input('enter number:>')
if num == 0
    disp('Goodbye!')
elseif num == 4444
    disp('welcome')
else 
    disp('incorrect')
end

num = input('enter number:>')
while num ~= -999
switch num
    case 0
    disp('Goodbye!')
    case 4444
    disp('welcome')
    otherwise
    disp('incorrect')
end
num = input('enter number:>')
end

inMat = [8 19 8 11;17 6 12 16;12 16 2 19;11 16 2 3]

sorted = sort(inMat(:))

outMat = reshape(sorted, 8 ,2)'

% problem 4
A = [3 7 5 3 9; 3 11 19 5 -10; 5 20 5 -11 13; 2 4 0 7 12; 14 2 6 7 -12]

find(A > 2 & mod(A, 2) == 0)
A(A > 2 & mod(A, 2) == 0)

arr = [1,2,3,4,;7,8,-1,-2;2,1,-3,-4];
arr(arr > 3)  % create a column array 
max(arr(:)) % return the largest in whole matrix
max(arr) % return the largest in each column



arr = [10 20 0 4 5 6 0 8 9 10]
arr = arr'
reshape(arr, 2, 5)
logArr = arr > 5;
find(logArr) % giving non zeros in arr and find index


arr = [1,2,3,4,;7,8,-1,-2;2,1,-3,-4];
arr(arr > 3)  % create a column array 


arr = [1,2,3,4,5,6,7,8,-1,-2,-3,-4];
arr = [2 0 1 7 6 -9];
[r a] = returnOddPosNums(arr)

function [odds idx] = returnOddPosNums(arr)

index = 1:1:length(arr);
idx = index(arr > 0 & mod(arr,2) ~= 0);
odds = arr(arr > 0 & mod(arr,2) ~= 0);

end


arr = [1,2,3,4,5,6,7,8,-1,-2,-3,-4];
r = returnOddPosNums(arr)

function ret = returnOddPosNums(arr)

ret = arr(arr > 0 & mod(arr,2) ~= 0);


end


a = [2;4;6];
b = [1;-4;3];
c = [-2;0;8];

mat = [a,b,c]

rowA = mat(1,:)
rowB = mat(2,:)
rowC = mat(3,:)


F = input('please enter the fahrenheit temp');
CK = degF_toCK(F);
fprintf('%d F is equal to %d C and %d K.',F,ceil(CK(1)),ceil(CK(2)));

function CK = degF_toCK(tempF)

C = (tempF - 32) * 5 / 9;
K = C + 273.15;
CK = [C K];

end



x = randi(5, 2, 1)

% arr1 = 1:5
% arr2 = 9:-2:1
% arr3 = [arr1 arr2]
% arr4 = [arr1 ; arr2]
% [a,b] = max(arr2)
% arr5 = arr2((arr2 == 9) | (arr2 == 3))
% 
% % specific the second argument as string
% name = input('Please enter your name:>','s');
% name2 = input("Please enter your name:>",'s');
% %d exponential  %c char, %s string
% wid = input('enter the value:> ')
% aa = calcArea(1234,23)
% 
% function area = calcArea(wid, hei)
% 
% area = wid * hei;
% 
% end


% specific the second argument as string
name = input('Please enter your name:>','s');
name2 = input("Please enter your name:>",'s');
%d exponential  %c char, %s string
wid = input('enter the value:> ')
aa = calcArea(1234,23)

function area = calcArea(wid, hei)

area = wid * hei;

end


% this script creates a meny for getting an order from a pizza menu

clear;clc;

choice = menu("Please pick a pizza from this menu:", "Cheese Lover", "Vegie Lover", "Meat Lover", "Cancel My Order");

switch choice
    case 1
        disp("Excellent choice!");
    case 2
        disp("Healthy Choice!");
    case 3
        disp("Delicous Choice");
    otherwise
        disp("Sorry to see you leave.");
end
% 
% if choice == 1
%      disp("Excellent choice!");
% elseif choice == 2
%      disp("Healthy choice!");
% elseif choice == 3
%     disp("Delicous Choice");
% else 
%     disp("Sorry to see you leave.");
% end

%this script will calculate the cost of sending a package by delivery
% $15 for 1st 2 ounds 
% $2 for every extra ound
% $15 extra for over 70 pounds
% over 100 pounds package is not acceptable
% written by Dee Bao

clear;clc;

weight = input('Please enter the weight of the packages:>');

cost = costOfMailingPackage(weight);

if cost ~= 99999 && cost ~= -99999
    fprintf("The cost of shipping a %.2f pounds package is %.2f\n",weight, cost);
end

function cost = costOfMailingPackage(weight)

cost = 0;
max = 100;
baseCost = 15;
overCost = 15;
baseWeight = 2;
extraCost = 2;
overWeight = 70;
if weight > max
    fprintf('package over weight');
    cost = 99999;
elseif weight <= 0
    fprintf('invalid input!');
    cost = -99999;
else 
    if weight > overWeight
        cost = cost + overCost;
    end
    
    if weight - baseWeight > 0
        cost = cost + baseCost;
        cost = cost + (weight - baseWeight) * extraCost;
    else 
        cost = baseCost;
    end

end
end

function y = findY(x)
% this function returns a value for y based on the input of x
% y = 1 for x < -1
% y = x^2 for -1 <= x <= 2
% y = 4 for x > 2
% written by Dee Bao

if x < -1
    y = 1;
elseif x > 2
        y = 4;
else
    y = x.^2;
end

end
function root = findPositiveRoots(arr, type)
%this function finds the positive roots of an array depending on "type"
% the function will return the roots of only the even positive numbers,
% only the odd positive numbers, or all positive numbers. 
%author: Dee Bao

arr = arr(arr > 0);

num = nargin;

% if num == 2
%     if type == 'e' || type == 'E'
%         arr = arr(mod(arr, 2) == 0);
%         root = sqrt(arr);
%     elseif type == 'o' || type == 'O'
%         arr = arr(mod(arr, 2) ~= 0);
%         root = sqrt(arr);
%     else 
%         root = sqrt(arr);
%     end
% else 
%     root = sqrt(arr);
% end

switch num
    case 1
        root = sqrt(arr);
    case 2
        switch lower(type)
            case 'e'
                arr = arr(rem(arr,2) == 0);
                root = sqrt(arr);
            case 'o'
                arr = arr(rem(arr,2) ~= 0);
                root = sqrt(arr);
            otherwise
                disp('invalid type input!\n');
                root = 'invalid type input';
        end
    otherwise
        disp('invalid type input!\n');
        root = 'invalid type input';

end

end
%this script will calculate the cost of sending a package by delivery
% $15 for 1st 2 ounds 
% $2 for every extra ound
% $15 extra for over 70 pounds
% over 100 pounds package is not acceptable
% written by Dee Bao

clear;clc;

weight = input('Please enter the weight of the packages:>');

cost = costOfMailingPackage(weight);

if cost ~= 99999 && cost ~= -99999
    fprintf("The cost of shipping a %.2f pounds package is %.2f\n",weight, cost);
end

function cost = costOfMailingPackage(weight)

cost = 0;
max = 100;
baseCost = 15;
overCost = 15;
baseWeight = 2;
extraCost = 2;
overWeight = 70;
if weight > max
    fprintf('package over weight');
    cost = 99999;
elseif weight <= 0
    fprintf('invalid input!');
    cost = -99999;
else 
    if weight > overWeight
        cost = cost + overCost;
    end
    
    if weight - baseWeight > 0
        cost = cost + baseCost;
        cost = cost + (weight - baseWeight) * extraCost;
    else 
        cost = baseCost;
    end

end
end

function safetyCheck = CargoLimit(passengerWeight, cargoWeight)
% passengerWeight: Total passenger weight (pounds)
% cargoWeight: Total cargo weight (pounds)

    maxWeight = 500;      % Maximum weight allowed
    if (cargoWeight + passengerWeight) <= maxWeight
        safetyCheck = 1;
    else 
        safetyCheck = 0;
    end
    % Assigns safetyCheck with 1 if the sum of passengerWeight and cargoWeight is less 
    % than or equal maxWeight. Otherwise, assign safetyCheck with 0
    
   
end

function decodedString  = DecoderMessage( userString )
  switch(userString)
      case 'LOL'
          decodedString = "laughing out loud";
      case 'IDK'
          decodedString = "I don't know";
      case 'BFF'
          decodedString = "best friends forever";
      case 'IMHO'
          decodedString = "in my humble opinion";
      case 'TMI'
          decodedString = "too much information";
      otherwise
          decodedString = "Unknown";
  end
    % Insert your code here % 
    
end


function greekLetter = ConvertAlphabet(origLetter)

    % Complete the switch statement to assign greekSymbol with 'Alpha',
    % 'Beta', or 'Unknown' based on origLetter
    switch ( origLetter ) 
        case 'a'
            greekLetter = 'Alpha';
        case 'A'
            greekLetter = 'Alpha';
        case 'b'
            greekLetter = 'Beta';
        case 'B'
            greekLetter = 'Beta';
        otherwise 
            greekLetter = 'Unknown';
    end

end

function finalValue = AssignValue(userValue)
    if userValue > 100
        finalValue  = userValue + 5;
    else
        finalValue = userValue + 3;
    end
    % Assign finalValue with userValue + 5 if userValue is greater than 100
    % Otherwise, assign finalValue with userValue + 3

end

function dosageAmount = CalculateDosage(userWeight)
% userWeight: User's weight in kg
    if userWeight < 50
        dosageAmount = 10;
    else if userWeight > 140
            dosageAmount = 30;
    else
        dosageAmount = 20;
    % Assign dosageAmount with the appropriate amount given userWeight
    end
end


function [B, C, D] = matrixFun(A);
%Enter the commands for your function below. Be sure to assign values 
%to each of the output variables defined in the function command on line 1.

sz = size(A);
B = [A(1,:);A(sz(1), :)];
C = [A(1,1), A(1, end); A(end, 1), A(end)];
A(1,:) = [];
A(:, 1) = [];
D = A;
end

function [outMat] = CustomSort( inMat )
% Takes a 2D array inMat with random integers between (inclusively) -100 and 100, 
% and produces a  n by m array outMat that  consists of sorts values 
% in inMat such that the lowest value in inMat is the (1,1) position 
% in outMat, and order the remaining elements left to right on 
% the first row till last column, starting with the next row and so on. 
    newMat = sort(inMat(:));
    sz = size(inMat);
    outMat = reshape(newMat, sz(2),sz(1)).';
   % Your code goes here % 
   
end

function identifiedCars = selectCars(topSpeeds, carNames, lowerBound, upperBound)
% select cars that have top speed within a given range
% and display the names to the command line.  
% Inputs: column array topSpeeds with top speeds in mile/hour,
%            corresponding column string array carNames with the  car names
%            lowerBound and upperBound  in km/h
%.

%   Convert topSpeeds to km/h
    topSpeeds =  topSpeeds * 1.609;   %  complete code
%  Create a logical array to extract the indices to the desired cars 
    logicalIndexArray = topSpeeds > lowerBound & topSpeeds < upperBound;   %  complete code
    identifiedCars = carNames(logicalIndexArray,:);
    disp(identifiedCars)
end


function [ newMatrixA, deletedElems ] = DeleteRowColumn( origMatrixA, delRow, delCol )
% DeleteRowColumn: Delete the row and column specified by delRow
% and delCol from input matrixA and returns the modified matrix and
% the deleted elements as a column array.
%   Inputs: origMatrixA - input matrix
%           delRow - row to delete
%           delCol - column to delete
%
%   Outputs: newMatrixA - input matrix with specified row and column deleted 
%            deletedElems - deleted elements from input matrix
%                           returned as a column array

    % Assign newMatrixA with origMatrixA
    newMatrixA = origMatrixA;
    
    % Assign deletedElems with row of newMatrixA to be deleted 
    % (Hint: Use the transpose operator to convert a row to a column)
    deletedElems = newMatrixA(delRow, :);  % FIXME
    deletedElems = deletedElems.';
    % Remove row delRow from newMatrixA
    newMatrixA(delRow, :) = [];    % FIXME

    % Append deletedElems with the with column of newMatrixA to be deleted
    deletedElems = [deletedElems;newMatrixA(:, delCol)];  % FIXME
    
    % Remove column delCol from newMatrixA
    newMatrixA(:,delCol) = [];    % FIXME

end


%create new matrix
mat1 = [1,2,3;4,5,6]
mat2 = [1,3,5;2,4,6;7,8,9;10,11,12]
mat3 = [1:5;2:6]

%call the element in the matrix
mat1(1,3) % row, col
mat1(1,:) % calling entire row
mat1(:,1) % calling entire column
mat2([2,3],[1,2]) % number 2 and 3 rows, with column number 1 and 2

%changing values 
mat1(1,2) = 20
mat1(2,:) = 1:3

%concatenate two matrix

mat4 = [mat1, mat3] % horizontally
mat5 = [mat1; mat2] % vertically

%flattening a 2d array into a column array
mat1(:)

% delete element / entire row = assign [] to it
mat1(1) = []
mat1(1) = []

%logical array
log1 = mat2 >=5
mat2(log1) % create a flatten array

temp = [73, 75, 81; 85, 75, 69; 75, 81, 84]
tempHigherthan80 = temp(temp > 80)
apart = 1:9
apart(temp > 80)

% end keyword
mat2
mat2(end) % last element of the entire matrix
mat2(end, 1) % last element of first column
mat2(1, end) % last element of first row
mat2(:,end) % last element of every row
mat2(end, :) % last element of every column

%length returns  2x3 array's column length or row length whichever is
%larger
length(mat2)

%size return row and column
size(mat2)

% numel returns number of elements in it
numel(mat2)

mat2
%return the largest element in each column
max(mat2)
%return the smallest element in each column
min(mat2)
%flatten the array and then return the max in the flattened array
max(mat2(:))
[M, I] = min(mat2(:))

zeros(4)
zeros(2,3)
ones(2)
ones(2,3)
% identity matrix
eye(5)
eye(3,4)

mat2
%flip left to right
fliplr(mat2)
%flip up down
flipud(mat2)
%rotate 90 degree
rot90(mat2)
%return lower triangular matrix
tril(mat2)
%return upper triangular matrix
triu(mat2)

arr = [1,2,3,4,5,6]
t1 = reshape(arr, 2,3)
t2 = reshape(arr,3,2)
% reshape(arr,6,1)
%matrix multiplication
ret = t1 * t2
% arraymultiplication
ret .* reshape(mat1, 2,2)
mat2 = mat2 *20
mat2(3,2)  = 0
%return index of non zero num
find(mat2)
find(mod(mat2, 3) == 0)

%sort function sort in ascending order of each column

sort(mat2)
sort(mat2, "descend")


