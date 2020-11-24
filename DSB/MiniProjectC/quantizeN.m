function [x_quantz, k] = quantizeN(x, N)

% 
%
% 
% 

step_size = 1/2^(N-1);

% ***** Forward quantization stage
% Her findes det n�rmeste step, som kan repr�sentere x
%k = sign(x).*round(abs(x)/step_size + 0.5);
k = round(x/step_size);

% ***** Reconstruction stage
x_quantz = step_size*k;

