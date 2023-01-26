%This script calculates the volume of a cylinder
%Author: Dee Bao

diameter = 3; %meter 
height = 5; %meter
volume = pi * (diameter/2)^2 * height;
disp(volume);
fprintf('The volue of a cylinder diameter %d m, and height %d m is %.2f m^3.\n',diameter, height, volume);
