clc; clear;

%% Opgave 1

wind    = 1;
fan     = 2;

% Definerer navne til plots
%sound(wind).name = 'Wind Turbine Noise.mp3';
sound(wind).name = 'Wind turbine sound - high quality audio.mp3';
sound(fan).name = 'Computer Fan - Sound Effect.mp3';

%Indlæser samples og frekvens af vind og computer
[sound(wind).samples,sound(wind).freq_sample] = audioread(sound(wind).name);
[sound(fan).samples,sound(fan).freq_sample] = audioread(sound(fan).name);

for i = 1:length(sound)
% Udvælger kanal af signal
sound(i).samples = sound(i).samples(:,1);

% Opstiller sample-værdier og tids-værdier
sound(i).interval = sound(i).samples((sound(i).freq_sample * 20):(sound(i).freq_sample * 30)-1);
sound(i).interval_N = length(sound(i).interval);
sound(i).time_interval = [0:sound(i).interval_N-1]*(1/sound(i).freq_sample);

% Plotter
figure(i)
plot(sound(i).time_interval,sound(i).interval) 
title(sound(i).name)
xlabel("Time(s)")
ylabel("Amplitude(~)")
end

%% Opgave 2

for i = 1:length(sound)
sound(i).sample_fft = fft(sound(i).samples,sound(i).freq_sample);

sound(i).fft_axis = [0:sound(i).freq_sample/length(sound(i).sample_fft):sound(i).freq_sample-1];

figure(i+2)
semilogx(sound(i).fft_axis, 20*log10(abs((2/length(sound(i).sample_fft))*sound(i).sample_fft)))
title(sound(i).name)
xlabel("samples")
ylabel("Amplitude(dB)")
end

%% Opgave 3

for i = 1:length(sound)
sound(i).fft_sort_high = sound(i).sample_fft(81:end);
sound(i).fft_sort_low = sound(i).sample_fft(1:80);

sound(i).effect_high = sum(sound(i).fft_sort_high.^2);
sound(i).effect_low = sum(sound(i).fft_sort_low.^2);

abs(sound(i).effect_high)
abs(sound(i).effect_low)
end

%% opgave 4
for i = 1:length(sound)
sound(i).freq_res = sound(i).freq_sample / length(sound(i).samples);
end

%% opgave 5
dial_up = 3;
sound(dial_up).name = "moller.mp4";
[sound(dial_up).samples, sound(dial_up).freq_sample] = audioread(sound(dial_up).name);
% only left channel
sound(dial_up).samples = sound(dial_up).samples( :, 1 );
%sound(dial_up).samples = sound(dial_up).samples(sound(dial_up).freq_sample*8:end);

figure(5)
plot(sound(dial_up).samples)

% Fourier på dial up tone
sound(dial_up).sample_fft = fft(sound(dial_up).samples);

sound(dial_up).fft_axis = [0 : ...
    sound(dial_up).freq_sample / length(sound(dial_up).sample_fft) : ...
    sound(dial_up).freq_sample-1];

figure(9)
semilogx(20*log10(abs(sound(dial_up).sample_fft)), "b")
hold on

% dialed number 15 96 24 80
% 1=697+1209, 5=770+1336, 
tones = [697, 770, 852, 941, 1209, 1336, 1477, 1633];
for i = 1:4
    for j = 5:8
    xline(tones(i)*tones(j),"r");
    end
end

title(sound(dial_up).name)
xlabel("samples")
ylabel("Amplitude(dB)")

















