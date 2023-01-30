function modifiedReadings = CalibrateReadings(originalReadings, adjustVal)
% originalReadings: Array of temperature readings 
% adjustVal: Value added to each element in the array of temperature readings

   % Add adjustVal to each element of array originalReadings
   modifiedReadings = originalReadings + adjustVal;
   
end
CalibrateReadings([51, 53, 61, 62], 5)
  
