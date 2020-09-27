clear;
clc;

% Define samples
s1 = 1;
s2left = 2;
s2right = 3;
s3 = 4;

% Loading files into arrays of samples
[y(s1).sample, ~] = audioread('Signal_s1.wav');
[y(s2left).sample, ~] = audioread('Signal_s2.wav');
[y(s3).sample, Fs] = audioread('Signal_s3.wav');

%Splits signal 2 into its own channels
y(s2right).sample = y(s2left).sample(:,2);
y(s2left).sample = y(s2left).sample(:,1);

%Defines the resampling of signal 1 to 5
s1reS = 5;
y(s1reS).sample = decimate(y(s1).sample, 4);

y(s1).name = "Signal\_s1.wav";
y(s2left).name = "Signal\_s2.wav - channel 1";
y(s2right).name = "Signal\_s2.wav - channel 2";
y(s3).name = "Signal\_s3.wav";
y(s1reS).name = "Resampling of " + y(s1).name;

length(y(s1).sample)
length(y(s2left).sample)
length(y(s2right).sample)
length(y(s3).sample)


%% Exercise 3 & 4
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


%% Exercise 2
f1 = figure;

for i = 1:length(y)-1
    subplot(2,2,i)
    plot(y(i).time, y(i).sample)
    title(y(i).name)
    xlabel("Time(s)")
    ylabel("Amplitude(~)")
end

%% exercise 5
y(s1reS).time = [0:y(s1reS).nS-1]*(1/(Fs/4));
figure
subplot(1,2,1)
plot(y(s1).time(1:500), y(s1).sample(1:500))
title(y(s1).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")
subplot(1,2,2)
plot(y(s1reS).time(1:500/4), y(s1reS).sample(1:500/4))
title(y(s1reS).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")

% Listen to exercise 5 uncomment for sound
%soundsc(y(s1).sample, Fs);
%soundsc(y(s1reS).sample, Fs/4);

%% Exercise 7

figure
subplot(1,2,1)
plot(y(s2left).time(20000:30000), y(s2left).sample(20000:30000))
title(y(s2left).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")
subplot(1,2,2)
plot(y(s2right).time(20000:30000), y(s2right).sample(20000:30000))
title(y(s2right).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")

%% Exercise 8
%Using BB function to quantize to 4 bits
s2quan = 6;
y(s2quan).sample = quantizeN(y(s2left).sample, 4);
%soundsc(y(s2right).sample, Fs) % uncomment for sound
figure
subplot(1,2,1)
plot(y(s2left).time(200000:205000), y(s2left).sample(200000:205000))
xlabel("Time(s)")
ylabel("Amplitude(~)")
title("s2 - Left channel");
subplot(1,2,2)
plot(y(s2left).time(200000:205000), y(s2quan).sample(200000:205000))
xlabel("Time(s)")
ylabel("Amplitude(~)")
title("s2 kvantifiseret 4bit - Left Channel");

%% Exercise 9
% Tage sidste tredjedel af s3
t = y(s3).time(1:y(s3).nS/3+1);
% Eksponentielt aftagende: b*a^x
% b = Skæring med y i (0,1)
% a = (y2/y1)^1/(x2-x1)
a = (0.05/1)^(1/(t(end)-t(1)));
% Matrice der er eksponentielt aftagenende
% Starter i 1 og går til 0.05 ved 1/3 af time
e = 1*a.^t;

% s3fade
s3fade = 7;
y(s3fade).sample = y(s3).sample;
y(s3fade).time = y(s3).time;
% Påfør e på sidste 1/3 af samples
y(s3fade).sample(length(y(s3fade).sample)*2/3:end) = e.*y(s3fade).sample(length(y(s3fade).sample)*2/3:end);

figure
subplot(1,2,1)
plot(y(s3fade).time, y(s3fade).sample)
title("s3 med fade effekt")
xlabel("Time(s)")
ylabel("Amplitude(~)")
subplot(1,2,2)
plot(y(s3).time, y(s3).sample)
title("s3")
xlabel("Time(s)")
ylabel("Amplitude(~)")
soundsc(y(s3fade).sample, Fs)
