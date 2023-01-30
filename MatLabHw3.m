function modifiedReadings = CalibrateReadings(originalReadings, adjustVal)
% originalReadings: Array of temperature readings 
% adjustVal: Value added to each element in the array of temperature readings

   % Add adjustVal to each element of array originalReadings
   modifiedReadings = originalReadings + adjustVal;
   
end
CalibrateReadings([51, 53, 61, 62], 5)
  
function countValues = CreateArray(endValue)
% endValue: Ending value of array countValues
countValues = (1:endValue)
    % Construct a row array countValues from 1 to endValue, 
    % using the colon operator
 

end
CreateArray(8)
function attendanceValues = ShiftValues(attendanceValues)
% attendanceValues: Array contains 4 elements recording attendence for the last 4 shows
    attendanceValues(end + 1) = attendanceValues(end);
    % Change indexing values
   attendanceValues(1) = [];
    
end
ShiftValues([25, 50, 75, 100])
