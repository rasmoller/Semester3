close all; clc; clear;

%Vi skal spørge om hvorvidt lyden af vores signal efter filtret hh er
%korrekt, og hvordan man skal tolke graferne fra xcorr og autocorr. Spørg
%også om det er korrekt om DFT-metodens amplitude på grafen skal være så
%lille.

load('DTMF_noisy_signal.mat');

soundsc(s_total, f_sample)

figure; clf
plot(s_total)
title("s\_total")

% 41 89 32 74
% 41: 770 + 1209, 697 + 1209, 
% 89: 852 + 1239, 852 + 1477, 
% 32: 698 + 1477, 697 + 1336,
% 74: 852 + 1209, 770 + 1209

s_fft = fft(s_total, f_sample);

% Frekvens spektret linært og log
figure; clf
subplot(1,2,1)
semilogx( (1:8000), 20*log10( abs( ( 2/length(s_fft) ) * s_fft(1:8000) ) ) )

subplot(1,2,2)
plot( (1:8000), s_fft(1:8000) )
title("s\_total\_FFT")

%% Del 2: Filtrer signalet

s_filter = s_fft .* [ ones(1, 2000) zeros(1, length(s_fft) - 2000) ];

figure; clf
plot(abs(s_filter));

%% Del 2: Design og benyttelse af FIR og/eller IIR filtre

low = [697 770 852 941];
high = [1209 1336 1477 1633];

band = [-5 -1 +1 +5];

fcuts = [low(1)+band low(2)+band low(3)+band low(4)+band high(1)+band high(2)+band high(3)+band high(4)+band];
mags = [0 repmat([1 0],1,8)];
devs = [0.05 repmat([0.01 0.05],1,8)];
[n,Wn,beta,ftype] = kaiserord(fcuts,mags, devs,f_sample);
n = n + rem(n,2);

hh = fir1(n,Wn,ftype, kaiser(n+1,beta),'noscale');

figure; clf
freqz(hh, 1, 2^14,f_sample)

sig = filtfilt(hh, 1, s_total);

sig_fft = fft(sig,f_sample);

figure; clf
plot(sig)

figure; clf
plot( (1:8000), sig_fft(1:8000) )

soundsc(sig,f_sample)

%Skal spørge om hvorfor signal lyder fuckkkkkkkkked

%% Del 3: Analyse med auto- og/eller krydskorrelation

r11 = xcorr(s_total);
figure; clf
plot(r11)

r22 = xcorr(sig);
figure; clf
plot(r22)

%Skal spørge om xcorr og autocorr

%% Del 4: Filtrering vha. DFT-metoden

d = [1 zeros(1,27000)];
filter_imp = filtfilt(hh, 1, d);

plot(filter_imp)

k = nextpow2(length(s_total));
s_total_fft = fft(s_total,2^k);

filter_imp_fft = fft(filter_imp,2^k);

filter_ps = filter_imp_fft.*s_total_fft;

filter_ps_freq = real(ifft(filter_ps));
filter_ps_freq = filter_ps_freq(1:length(s_total));

plot(linspace(1,52800,52800), filter_ps_freq)
hold on
plot(linspace(1,52800,52800), sig,'r')
hold on
plot(linspace(1,52800,52800), s_total)

hold off

%soundsc(filter_ps_freq,f_sample)

%% Del 5: Frekvensanalyse vha. Short Time DFT

figure
stft(s_total, f_sample);

figure
stft(sig,f_sample);









