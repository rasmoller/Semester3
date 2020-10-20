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

























