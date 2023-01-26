%This script calculates the volume of a cylinder by enter the values for
%the diameter and height of the cylinder
%Author: Dee Bao


clear;clc;
%ask user to enter values for the diameter and height
diameter = input('please enter the value of the diameter>: ');
height = input('please enter the height of the height>: ');
volume = pi * (diameter/2)^2 * height;
% disp(volume);
disp('usiing %.2f output:');
fprintf('The volue of a cylinder with diameter %.2f m, and height %.2f m is %.2f m^3.\n',diameter, height, volume);
disp('usiing %.2e output:');
fprintf('The volue of a cylinder with diameter %.2e m, and height %.2e m is %.2e m^3.\n',diameter, height, volume);
disp('usiing %.2g output:');
fprintf('The volue of a cylinder with diameter %.2g m, and height %.2g m is %.2g m^3.\n',diameter, height, volume);

