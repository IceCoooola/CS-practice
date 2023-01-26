%This script prompts the user to enter the inside diameter, outside
%diameter, and density of the sphere. It then passes these values to the
%massHollowSphere.m function and prints the mass of the sphere on
%the screen using the fprintf function.
%Author: Dee Bao

clear;clc;
innerD = input('Please enter the inner diameter of the sphere:> ');
outterD = input('Please enter the outter diameter of the sphere:> ');
density = input('Please enter the density of the sphere:> ');
mass = massHollowSphere(innerD, outterD, density);
fprintf('The mass of a hollow sphere with inner diameter %.2fm, outter diameter %.2fm, density %.2fkg/m^3, is %.2fkg.\n',innerD, outterD, density, mass);
