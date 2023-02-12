function outMat = CustomSort(inMat)
% takes an n x m array inMat with random integers between
% -100 and 100 (inclusive), and produces an n x m array 
% called outMat. 
% Author: Dee Bao

sz = size(inMat);
sortedArr = sort(inMat(:));
outMat = reshape(sortedArr, sz(2), sz(1))';

end
