function info = SpringData(inputArr)
%this function receives a n x 2 array first line force and second line
%spring constant
%Author: Dee Bao
%E = 1 / 2 * k * x^2
springConst = inputArr(:,2);
force = inputArr(:,1);
compression = force ./ springConst;
energy = springConst ./ 2 .* compression .^ 2;

info = [force, springConst,compression, energy];

end
