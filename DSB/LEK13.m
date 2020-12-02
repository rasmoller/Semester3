clc; clear;

%% Opgave 4.6 og 4.7

[s,fs] = audioread('Music_sample_48kHz.wav');

s = s(:,1)';

[b,a] = butter(4,2*[800 3000]/fs,'stop');

d = [1 zeros(1,999)];
h = filter(b,a,d);

tic
sfilt_time = filter(b,a,s);
toc

tic
k = nextpow2(length(s));
S = fft(s,2^k);
toc

H = fft(h,2^k);

Sfilt_freq = S.*H;

sfilt_freq = real(ifft(Sfilt_freq));
sfilt_freq = sfilt_freq(1:length(s));

VSTF(STF(s,fs,256,220));



%plots
%figure
%plot(s)
%title("s")

%figure
%plot(h)
%title("impulsrespons")

%figure
%plot(S)
%title("s - DFT")

%figure
%plot(H)
%title("h - DFT")

%figure
%plot(sfilt_time)
%title("filter")

%% Opgave 4.7

