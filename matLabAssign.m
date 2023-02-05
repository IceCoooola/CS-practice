function modifiedReadings = CalibrateReadings(originalReadings, adjustVal)
% originalReadings: Array of temperature readings 
% adjustVal: Value added to each element in the array of temperature readings

   % Add adjustVal to each element of array originalReadings
   modifiedReadings = originalReadings + adjustVal;
   
end

function countValues = CreateArray(endValue)
% endValue: Ending value of array countValues
countValues = (1:endValue)
    % Construct a row array countValues from 1 to endValue, 
    % using the colon operator
 

end

function attendanceValues = ShiftValues(attendanceValues)
% attendanceValues: Array contains 4 elements recording attendence for the last 4 shows
    attendanceValues(end + 1) = attendanceValues(end);
    % Change indexing values
   attendanceValues(1) = [];
    
end

function overweightBaggage = CheckWeight(baggageWeight, maximumWeight)
% baggageWeight: Array of baggage weights in pounds
% maximumWeight: Maximum baggage weight in pounds
overweightBaggage = baggageWeight > maximumWeight;
    % Assign overweightBaggage with true wherever baggageWeight 
    % is above maximumWeight


end

function totalYen = ConvertToYen(totalDollars)
% totalDollars: Amount to convert in dollars
    totalYen = floor(totalDollars * 119.771);
    % Assign totalYen with the amount of yen distributed given totalDollars 
    % Exchange rate is 119.771 Japanese yen for 1 US dollar


end

function highScores = GetHighScores(gameScores, minScore)
% gameScores: Array contains all player scores
% minScore: Scores greater than minScore are added to highScores

    meetsThreshold = (gameScores > minScore);  % Logic array indicates which 
                                               % elements are greater than minScore

    % Construct a row array highScores containing all player scores greater than minScore
    highScores = gameScores(meetsThreshold);
   
end
