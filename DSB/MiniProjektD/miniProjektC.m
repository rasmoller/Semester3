clc; clear; close all;
%Case: Kodning af musik -og talesignaler

%% Opgave 1

[aud,freq_sample] = audioread("Freddie-Mercury-Bohemian-Rhapsody.mp3");

aud1 = aud(:,1)';
aud2 = aud(:,2)';

figure
plot(aud1)

figure
plot(aud2)

aud_fft = fft(aud1);

figure
fft_axis = [0:freq_sample/length(aud_fft):freq_sample-1];
semilogx(fft_axis(1:length(aud_fft)/2), 20*log10(abs((2/length(aud_fft))*aud_fft(1:length(aud_fft)/2))))


a = quantizeN(aud_fft,16);
figure
semilogx(fft_axis(1:length(aud_fft)/2), 20*log10(abs((2/length(a))*a(1:length(aud_fft)/2))))

%save("aud_data",aud_fft)


%% Opgave 2

samples_per_Hz = length(aud_fft)/freq_sample;



aud_fft_1_100 = quantizeN(aud_fft(1:100*samples_per_Hz),4);
aud_fft_10001_20000 = quantizeN(aud_fft(10000*samples_per_Hz+1:20000*samples_per_Hz),4);
aud_fft_101_500 = quantizeN(aud_fft(100*samples_per_Hz+1:500*samples_per_Hz),6);
aud_fft_6001_10000 = quantizeN(aud_fft(6000*samples_per_Hz+1:10000*samples_per_Hz),6);
aud_fft_501_1500 = quantizeN(aud_fft(500*samples_per_Hz+1:1500*samples_per_Hz),12);
aud_fft_3001_6000 = quantizeN(aud_fft(3000*samples_per_Hz+1:6000*samples_per_Hz),12);

figure
hold on
b = [aud_fft_1_100, aud_fft_101_500, aud_fft_501_1500, aud_fft(1501*samples_per_Hz:3000*samples_per_Hz), aud_fft_3001_6000, aud_fft_6001_10000, aud_fft_10001_20000];
fft_axis = [1:freq_sample/length(aud_fft):freq_sample-1];

%figure
%plot(fft_axis(1:length(b)),b)
%title("penis")

f = ifft(b);

%soundsc(abs(f),freq_sample)
figure
semilogx(fft_axis(1:length(b)), 20*log10(abs((2/length(b))*b(1:length(b)))))
title("DFT af signalet efter bit-filter")
xlabel("Frekvens(Hz)")
ylabel("Amplitude(~)")

figure
plot(real(f))
title("real")

figure
plot(imag(f))
title("Bohemian Rhapsody efter bit-filter")
xlabel("Time(s)");
ylabel("Amplitude(~)")

soundsc(imag(f),0.5*freq_sample)
%% Opgave 3

bits = 22050 * 16
bits2 = 100 * 4 + (20000-10000) * 4 + (500-100) * 6 + (10000-6000) * 6 + (1500-500) * 12 + (6000-3000) * 12 + (3000-1500) * 16 + (22050-20000)*16
bits2/bits*100

%% Opgave 4





%% Opgave 3.13

M = 6;              %Orden af filter
fs = 24000;         %Frekvens

cutoff1 = 3000;     %Cutoff 1
cutoff2 = 4000;     %Cutoff 2

filt = designfilt('bandpassiir','FilterOrder',M,'HalfPowerFrequency1',cutoff1,'HalfPowerFrequency2',cutoff2,'SampleRate',fs);
h = fvtool(filt);   %Magnitude respons
freqz(filt);        %Faserespons
grpdelay(filt);     %Group delay

%% Opgave 3.14

a = [1 -0.36];
b = [0.872 -0.488];

Ts = 10^-3;
fs = 1/Ts;

[h,w] = freqz(b,a);
plot(w*fs/(2*pi),20*log10(abs(h)))
title("Frekvensrespons")
xlabel("Frekvens(Hz)")
ylabel("amplitude(dB)")

zplane(a,b)

%% Opgave 3.15

M1 = 4;
M2 = 12;
cutoff = 0.05;

[b1, a1] = butter(M1, cutoff, "high");
[b2, a2] = butter(M2, cutoff, "high");

HP_filter1 = filter(b1,a1,[zeros(1,99)]);
HP_filter2 = filter(b2,a2,[zeros(1,99)]);

figure
impz(b1,a1,100)
title("High-pass filter, 4. orden");

figure
impz(b2,a2,100)
title("High-pass filter, 12. orden");

figure
zplane(b1,a1)
title("4. Orden")

figure
zplane(b2,a2)
title("12. Orden")

%% IIR-filter

[y,fs] = audioread("Freddie-Mercury-Bohemian-Rhapsody.mp3");
y_l = y(:,1);

N = length(y_l);
freq_res = fs/N;
T = N/fs;
Y = fft(y_l,N);
t = [0:length(y_l)-1/fs];
f_axis = [0:freq_res:fs-freq_res];

%Plot
figure
plot(t,y_l)
xlabel("Time(s)");
ylabel("Amplitude(~)")
title("Bohemian Rhapsody")

figure
plot(f_axis(1:0.5*end),abs((2/N)*Y(1:0.5*end)))
xlabel("Frekvens(Hz)")
ylabel("Amplitude(dB)")
title("DFT af signal på normale akser")

figure
semilogx(f_axis(1:0.5*end),20*log10(abs((2/N)*Y(1:0.5*end))))
xlabel("Frekvens(Hz)")
ylabel("Amplitude(dB)")
title("DFT af signal på logaritmiske akser")

%IIR-filter

%Design af filter
f_cutoff0 = 0.5;
f_cutoff60 = 1;
f_cutoff200 = 500;
f_cutoff1000 = 1000;
f_cutoff8000 = 8000;

M = 8;

filt60_200 = designfilt('bandpassiir','FilterOrder',M,'HalfPowerFrequency1',f_cutoff60,'HalfPowerFrequency2',f_cutoff200,'SampleRate',fs);
h1 = fvtool(filt60_200);
freqz(filt60_200)
grpdelay(filt60_200)
impz(filt60_200)
zplane(filt60_200)

%% Kode for FIR-filter

freq_cutoff1 = 2000;
freq_cutoff2 = 4000;
freq_sample = 48000;

M = 600;

freq_res = freq_sample/M;

freq_bin1 = freq_cutoff1 / freq_res;
freq_bin2 = freq_cutoff2 / freq_res;

freq_bin1_round = round(freq_bin1);
freq_bin2_round = round(freq_bin2);

H_left  = [zeros(1,freq_bin1_round-1) ones(1,freq_bin2_round-freq_bin1_round+1) zeros(1,(M/2)-freq_bin2_round)];
H_right = fliplr(H_left(2:end));

H = [H_left H_right];

h = fftshift(real(ifft(H)));

w_hanning = hanning(M-1)';
h_win = h.*w_hanning;

H_without_win = fft(h,freq_sample);
H_with_win = fft(h_win,freq_sample);

figure(1); clf
stem(H_left)
title("Ideel overføringsfunktion")

figure(2); clf
plot(h)
axis([1 M-1 -inf inf])
hold on
plot(w_hanning*max(abs(h)),'g','linewidth',2)
plot(h_win,'r','linewidth',2)
title('Impulsrespons med vinduesfunktion')
legend("Impulsrespons uden filter", "Hanning-vindue", "Impulsrespons med filter")

figure(3); clf
plot(abs(H_without_win(1:freq_sample/2)))
hold on
plot(abs(H_with_win(1:freq_sample/2)),'r','linewidth',2)
grid on
title('Resulterende overføringsfunktion')
legend("Uden FIR-filter","Med FIR-filter")







