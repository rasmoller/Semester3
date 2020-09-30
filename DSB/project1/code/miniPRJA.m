clear;
clc;
% Loading files into arrays of samples
[y(1).sample, ~] = audioread('Signal_s1.wav');
[y(2).sample, ~] = audioread('Signal_s2.wav');
[y(4).sample, Fs] = audioread('Signal_s3.wav');

%Splits signal 2 into its own channels
y(3).sample = y(2).sample(:,2);
y(2).sample = y(2).sample(:,1);

%Defines the resampling of signal 1 to 5

y(5).sample = downsample(y(1).sample, 4);

y(1).name = "Signal\_s1.wav";
y(2).name = "Signal\_s2.wav - channel 1";
y(3).name = "Signal\_s2.wav - channel 2";
y(4).name = "Signal\_s3.wav";
y(5).name = "Resampling of " + y(1).name;


%Exercise 3 & 4
for i = 1:length(y)
    y(i).sample = y(i).sample';
    % number of Samples 1, 2, 3
    y(i).nS = length(y(i).sample);
    %Calculating x axis for signals
    y(i).time = [0:y(i).nS-1]*(1/Fs);
    %Find max, min, mean, rms & effect
    y(i).max = max(y(i).sample);
    y(i).min = min(y(i).sample);
    y(i).mean = mean(y(i).sample);
    y(i).rms = rms(y(i).sample);
    y(i).effect = sum(y(i).sample.^2);
    %Calculating Crest value
    y(i).crest = 20*log10(y(i).max/y(i).rms);
end
f1 = figure;
%Exercise 2
for i = 1:length(y)-1
    subplot(2,2,i)
    plot(y(i).time, y(i).sample)
    title(y(i).name)
    xlabel("Time(s)")
    ylabel("Amplitude(~)")
end

% Plot exercise 5
figure
subplot(1,2,1)
plot(y(1).time, y(1).sample)
title(y(1).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")
subplot(1,2,2)
plot(y(5).time, y(5).sample)
title(y(5).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")
%Listen to exercise 5 uncomment for sound
soundsc(y(5).sample, Fs/4);

% Exercise 7
figure
subplot(1,2,1)
plot(y(2).time, y(2).sample)
title(y(2).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")
subplot(1,2,2)
plot(y(3).time, y(3).sample)
title(y(3).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")

%Exercise 8
%Using BB function to quantize to 4 bits
y(6).sample = quantizeN(y(2).sample, 4);
%soundsc(y(6).sample) % uncomment for sound
figure
plot(y(2).time, y(6).sample)
title("Kvantisering af s2 kanal 2, 4 bit")
xlabel("Time(s)")
ylabel("Amplitude(~)")

% Exercise 9
t = y(4).time(1:y(4).nS/3+1);
% a = (y2/y1)^1/(x2-x1)
a = (0.05/1)^(1/(t(end)-t(1)));
%a = 0.9;
e = a.^t; %from 1 to 0.05
figure
plot(t,e)

y(7).sample = y(4).sample;

y(7).sample(length(y(7).sample)*2/3:end) = e.*y(7).sample(length(y(7).sample)*2/3:end);
figure
plot(y(4).time, y(7).sample)
soundsc(y(7).sample)
