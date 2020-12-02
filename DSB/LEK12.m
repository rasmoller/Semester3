clc; clear;

%% Opgave 4.1

s1 = randn(1,2000);
s2 = rand(1,2000);

s3 = sin(2*pi*65*[0:0.001:2-0.001]);

[s4, fs] = audioread('Tale of the Meatball Man Sing Along A Little Runmo Sing Along.mp3');
[s5, fs] = audioread('Voice_sample_male.wav');
s4 = s4(:,1)';
s5 = s5(:,1)';

figure(1); clf
subplot(1,2,1)
histogram(s1, 15) %<--Fuck you
subplot(1,2,2)
histogram(s1, 40)

figure(2); clf
subplot(1,2,1)
histogram(s2, 15)
subplot(1,2,2)
histogram(s2, 40)

figure(3); clf
subplot(1,2,1)
histogram(s3, 15)
subplot(1,2,2)
histogram(s3, 40)

figure(4); clf
subplot(1,2,1)
histogram(s4, 15)
subplot(1,2,2)
histogram(s4, 40)

figure(5); clf
subplot(1,2,1)
histogram(s5, 15)
subplot(1,2,2)
histogram(s5, 40)

%% Opgave 4.2

r11 = xcorr(s1);
figure(6); clf
plot(r11)

r22 = xcorr(s2);
figure(7); clf
plot(r22)

r33 = xcorr(s3);
figure(8); clf
plot(r33)

r44 = xcorr(s4(1:60000));
figure(9); clf
plot(r44)

r55 = xcorr(s5(1:60000));
figure(10); clf
plot(r55)

s6 = [zeros(1,2000), s5(1:60000)];
r56 = xcorr(s5(1:60000), s6);
figure(11); clf
plot(r56)

%% Opgave 4.3

S4 = fft(s4, 3*fs);
S44 = fft(r44, 3*fs);

figure(12); clf
semilogx(20*log10(abs(S4(1:3:0.5*end))))
hold on 
semilogx(20*log10(abs(S44(1:3:0.5*end))))
semilogx(20*log10(abs(S4(1:3:0.5*end)).^2),'g')
title("Plot af Moller")
xlabel("Moller")
ylabel("Moller")

%% Opgave 4.4

w = [-1 -0.5 0 0.5 1];
Pw = [0.1 0.17 0.4 0.21 0.12];

y = [6 7 8 9 10 11];
Py = [0.13 0.26 0.14 0.009 0.11 0.27];

mean_value_w = mean(w);
mean_value_y = mean(y);

std_deviat_w = sqrt(sum(((w-mean_value_w).^2).*Pw))
std_deviat_y = sqrt(sum(((y-mean_value_y).^2).*Py))

%% Opgave 4.5

s0 = ones(1,200);

figure(13)
subplot(3,1,1)
r1 = xcorr(s0,s0);
plot(r1)
subplot(3,1,2)
r2 = xcorr(s0,s0,'normalized');
plot(r2)
subplot(3,1,3)
r3 = xcorr(s0, s0, 'unbiased');
plot(r3)










