%class acativity, 2-9-2023
% Author: Dee Bao

a = [15,3,22; 3,8,5; 14,3,82];
disp(a);
b = [1;5;6];
disp(b);
c = [12, 18, 5, 2];
disp(c);

%part 1 - create matrix d from the third column of a
d = a(:,3);
disp(d);

%part 2 - Combine matrix b and matrix d to create matrix e
e = [b,d];
disp(e);

%part 3 - Combine matrix b and matrix d to create matrix f
f = [b;d];
disp(f);

%part 4 - Create a matrix g from matrix a and the first three elements of matrix c
g = [a;c(1:3)];
disp(g);

%part 5 - Create a matrix h with the first element equal to 𝑎1,3, the second element equal 
%to 𝑐1,2, and the third element equal to 𝑏2,1.
h = [a(1,3),c(1,2),b(2,1)];
disp(h);
