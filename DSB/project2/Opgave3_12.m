clc;
for i = 1:3
    y(i).samples = (2*rand(5000,1))-1;
    y(i).length = length(y(i).samples);
    
    y(i).dft = fft(y(i).samples, y(i).length-1);
    y(i).dft_axis = [0:50000/length(y(i).dft):50000-1];
    
    abs(sum(y(i).dft))
    abs(y(i).length*y(i).samples(1))
end    
