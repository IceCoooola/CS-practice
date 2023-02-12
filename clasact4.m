function info = hollowSphere(data)
%this function receives a n x 3 array first column inner diameter 2nd
%column outter diameter and densities returns these three columns of data
%plus a column of weight

inRadius = data(:,1) / 2;
outRadius = data(:,2) / 2;
density = data(:,3);

volume = 4 / 3 * pi * (outRadius .^3 - inRadius.^3);

mass =  volume .* density;

info = [data, mass];

end
