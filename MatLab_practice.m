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


