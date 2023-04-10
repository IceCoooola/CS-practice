clear;clc;
% open file
fid = fopen("Countries.dat",'r');
% check if the file open successfully
if fid == -1
    disp('open file failed.')
else
    disp('file open successfully');
    % display a menu
    choice = menu('40 largest countries in the world', ...
        'a. Find the countries with the minimum and maximum life expectancy', ...
        'b. Find the countries with the minimum and maximum number of people per television', ...
        'c. Find the countries with the minimum and maximum number of people per physician.', ...
        'd. Find all the information about a specific country.', ...
        'e. Exit');
    % read file into data
    data = textscan(fid, '%s %f %f %d');
    % check which one user choose
    switch choice
        case 1
            [minLifeCountry, maxLifeCountry] = findMinMaxLifeExpectancy(data);
            fprintf('Name, ');
        case 2
            [minTVCountry, maxTVCountry] = findMinMaxTelevision(data);
        case 3
            [minPhysician, maxPhysician] = findMinMaxPhysician(data);
        case 4
            infomation = findRecord(data, 'Ethiopia');
        otherwise

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
end


function [minTVsetCountry, maxTVsetCountry] = findMinMaxTelevision(data)
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

end

function [minPhysician, maxPhysician] = findMinMaxPhysician(data)
    % save the name and people per physician data into array
    name = data{1};
    peoplePerPhysician = data{4};

    % find the max physician 
    maxPhysician = max(peoplePerPhysician);
    % create a logic array
    logicMax = maxPhysician == peoplePerPhysician;
    % find max physician country
    maxPhysician = name{logicMax};

    % find the min physician 
    minPhysician = min(peoplePerPhysician);
    % create a logic array
    logicMin = minPhysician == peoplePerPhysician;
    % find max physician country
    minPhysician = name{logicMin};

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

end
