tabel = [99, 103, 99, 101, 102, 102, 100, 101, 102, 100];

correctVal = 102;
sysErr = mean(tabel) - correctVal;

% Find max Error
minErr = abs(min(tabel) - correctVal);
maxErr = abs(max(tabel) - correctVal);
maxRandErr = max([minErr, maxErr]);

% Calibrate tabel
calTabel = tabel - sysErr;


sigma = sqrt( sum( (tabel - mean(tabel) ).^2 ) / ( length(tabel)-1) );
z = (tabel - mean(tabel)) / sigma;
f = @func
F = integral( f, - 1000, 1.65)

function f = func(z)
f = ( 1 / sqrt(2*pi) ) * exp(1) .^ ( (-z.^2)/2 );
end