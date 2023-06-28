
clear;clc;
num = 7;
fib(num)

function result = fib(n)
    if n == 1
        result = 1;
        return;
    end
    if n == 2
        result = 1;
        return;
    end
    result = (fib(n - 1) + fib(n - 2));
end



% % ask user to input a string, remember to input a string, a second argument
% % 's' is needed.
% str = input("enter a string>: ", 's');
% % convert every character to lower case
% str = lower(str);
% % convert the first character to upper case.
% str(1) = upper(str(1));
% % display the string.
% disp(str);

% number = [2 3 4 5 6 8 9];
% if number == int8(number)
%     disp("integer!");
% else
%     disp("not integer!");
% end
clear;clc;
% open file
fid = fopen("Countries.dat",'r');
% check if the file open successfully
if fid == -1
    disp('open file failed.')
else
    disp('file open successfully');

    % read file into data
    data = textscan(fid, '%s %f %f %d');
    % display a menu
    while 1
        choice = menu('40 largest countries in the world', ...
            'a. Find the countries with the minimum and maximum life expectancy', ...
            'b. Find the countries with the minimum and maximum number of people per television', ...
            'c. Find the countries with the minimum and maximum number of people per physician.', ...
            'd. Find all the information about a specific country.', ...
            'e. Exit');
        % check which one user choose
        switch choice
            case 1
                findMinMaxLifeExpectancy(data);
            case 2
                findMinMaxTelevision(data);
            case 3
                findMinMaxPhysician(data);
            case 4
                target = input('Plesae enter the name of the country you want to search>:','s');
                infomation = findRecord(data, target);
            otherwise
                disp('goodbye!');
                break;
        end
    end
    % close file
    f = fclose(fid);
    if f == -1
        disp('file close failed!');
    else
        disp('file closed.');
    end
end

function [minLifeCountry, maxLifeCountry] = findMinMaxLifeExpectancy(data)
    % this function returns the minimum life expectancy and maximum life
    % expectancy country, and display these two country with correspoding
    % life expectancy

    % save the name and life expectancy into arrays.
    name = data{1};
    lifeExp = data{2};
    
    % find max life expectancy
    maxLife = max(lifeExp);

    % create a logic array
    logicMax = lifeExp == maxLife;

    % find max life expectancy country
    maxLifeCountry = name{logicMax};

    % find min life expectancy
    minLife = min(lifeExp);  

    % create a logic array
    logicMin = lifeExp == minLife;

    % find min life expectancy country
    minLifeCountry = name{logicMin};
    %display the data
    fprintf('Country |  Life Expectancy\n');
    fprintf('%s | %.1f\n',minLifeCountry,minLife);
    fprintf('%s | %.1f\n',maxLifeCountry,maxLife);

end


function [minTVsetCountry, maxTVsetCountry] = findMinMaxTelevision(data)
    % this function returns the country of minimum TV set per person and country of 
    % maximum TV set per person, and display these two country with correspoding
    % TV set per person
    
    % save the name and TV set per person into array
    name = data{1};
    peoplePerTVset = data{3};

    % find the max TV set 
    maxTV = max(peoplePerTVset);
    % create a logic array
    logicMax = peoplePerTVset == maxTV;
    % find max television set country
    maxTVsetCountry = name{logicMax};
    
    % find the max TV set 
    minTV = min(peoplePerTVset);
    % create a logic array
    logicMin = peoplePerTVset == minTV;
    % find max television set country
    minTVsetCountry = name{logicMin};
    % display the data 
    fprintf('Country |  People per TV\n');
    fprintf('%s | %.1f \n',minTVsetCountry, minTV);
    fprintf('%s | %.1f \n',maxTVsetCountry, maxTV);
end

function [minPhysician, maxPhysician] = findMinMaxPhysician(data)
    % save the name and people per physician data into array
    name = data{1};
    peoplePerPhysician = data{4};

    % find the max physician 
    maxNum = max(peoplePerPhysician);
    % create a logic array
    logicMax = maxNum == peoplePerPhysician;
    % find max physician country
    maxPhysician = name{logicMax};

    % find the min physician 
    minNum = min(peoplePerPhysician);
    % create a logic array
    logicMin = minNum == peoplePerPhysician;
    % find max physician country
    minPhysician = name{logicMin};
    % display the data
    fprintf('Country |  People per physician\n');
    fprintf('%s | %d \n',minPhysician, minNum);
    fprintf('%s | %d \n',maxPhysician, maxNum);

end

function info = findRecord(data, target)
    % save the name, life expectancy, people per TV set, people per
    % physician into arrays.
    name = data{1};
    lifeExp = data{2};
    peoplePerTVset = data{3};
    peoplePerPhysician = data{4};
    
    % create a loop to check all the element in name
    for i = 1:length(name)
        % save ith element into tmp
        tmp = name{i};
        % check if tmp name is the target name
        if strcmp(tmp, target)
            % save that country's data into a cell array
            info = {name{i}, lifeExp(i), peoplePerTVset(i), peoplePerPhysician(i)};
            break;
        end
    end
    fprintf('Country | Life Expectancy | People per TV | People per Physician\n');
    fprintf('%s | %.1f | %.1f | %d\n',info{1}, info{2}, info{3}, info{4});

end
