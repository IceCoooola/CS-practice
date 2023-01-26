%extra Problem

fahrenheit = input('enter fahrenheit degree:> ');
k = FtoK(fahrenheit);
fprintf('fahrenheit %.2f degree in kelvin is %.2f\n',fahrenheit,k);

function kelvin =  FtoK(F)
kelvin = 5/9*(F - 32) + 273.15;
end
