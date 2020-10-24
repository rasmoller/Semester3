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
%Foretager fourier-transformation ud fra sample-frekvens
sound(i).sample_fft = fft(sound(i).samples,sound(i).freq_sample);

%Opstiller sample-akse vi kan plotte ud fra
sound(i).fft_axis = [0:sound(i).freq_sample/length(sound(i).sample_fft):sound(i).freq_sample-1];

%Tegner figur på logaritmisk akse
figure(i+2)
semilogx(sound(i).fft_axis, 20*log10(abs((2/length(sound(i).sample_fft))*sound(i).sample_fft)))
xline(sound(i).freq_sample/2, "r")
title("DFT af " + sound(i).name)
xlabel("Frekvens (Hz)")
ylabel("Amplitude(dB)")
end

%% Opgave 3

for i = 1:length(sound)
    %Opstiller frekvenser over 80 H< og under 80Hz
    sound(i).freq_res = sound(i).freq_sample/length(sound(i).samples);
    sound(i).fft_sort_high = sound(i).sample_fft(81:end);
    sound(i).fft_sort_low = sound(i).sample_fft(1:80);

    %Bestemmer effekten at de to intervaller
    sound(i).effect_high = sum(sound(i).fft_sort_high.^2);
    sound(i).effect_low = sum(sound(i).fft_sort_low.^2);

    %Finder den absolute værdi for at få længden/størrelsen af effekten
    abs(sound(i).effect_high)
    abs(sound(i).effect_low)
end

%% opgave 4

for i = 1:length(sound)
%Bestemmer frekvens opløsningen
sound(i).freq_res = sound(i).freq_sample / length(sound(i).samples);
end

%% opgave 5

%Indlæser samples og frekvens af dial tone
dial_up = 3;
sound(dial_up).name = "dial tones.mp4";
[sound(dial_up).samples, sound(dial_up).freq_sample] = audioread(sound(dial_up).name);

%Bestemmer antal samples
sound(dial_up).N = length(sound(dial_up).samples);

% Indlæser vesntre kanal af lydsignalet
sound(dial_up).samples = sound(dial_up).samples( :, 1 );

sound(dial_up).time_interval = [0:sound(dial_up).N-1]*(1/sound(dial_up).freq_sample);
%Plotter samples
figure(5)
plot(sound(dial_up).time_interval, sound(dial_up).samples)
ylabel("Amplitude (~)")
xlabel("Tid (s)")
title(sound(dial_up).name)

% Fourier på dial up tone
sound(dial_up).sample_fft = fft(sound(dial_up).samples, sound(dial_up).N);

%Opstiller plotte-akse for fft af dial tone
sound(dial_up).delta_f = sound(dial_up).freq_sample / sound(dial_up).N;
sound(dial_up).f_axis = [0: sound(dial_up).delta_f: sound(dial_up).freq_sample-sound(dial_up).delta_f];

%Plotter dial tone på logaritmiske akser
figure
semilogx(sound(dial_up).f_axis(1:0.5*end), 20*log10( abs((2/sound(dial_up).N)*sound(dial_up).sample_fft(1:0.5*end)) ) );

hold on
%Plotter frekvenser vi forventer på plot
% dialed number 15 96 24 80
% DMTF tones
tones = [697, 770, 852, 941, 1209, 1336, 1477, 1633];
for i = 1:length(tones)
    xline(tones(i),"r");
end

title("DFT af " + sound(dial_up).name)
xlabel("Frekvens (Hz)")
ylabel("Amplitude(dB)")

%% Opgave 6

glass    = 4;
bike     = 5;
song     = 6;

% Definerer navne til plots
%sound(wind).name = 'Wind Turbine Noise.mp3';
sound(glass).name = 'Clinking Glasses.mp3';
sound(bike).name = 'Yamaha R6.mp3';
sound(song).name = 'SKRILLEX - Bangarang.mp3';

%Indlæser samples og frekvens af vind og computer
[sound(glass).samples,sound(glass).freq_sample] = audioread(sound(glass).name);
[sound(bike).samples,sound(bike).freq_sample] = audioread(sound(bike).name);
[sound(song).samples,sound(song).freq_sample] = audioread(sound(song).name);

for i = 4:6
    sound(i).N = length(sound(i).samples);
    
    sound(i).samples = sound(i).samples(:,1);
    
    sound(i).sample_fft = fft(sound(i).samples, sound(i).N);
    
    sound(i).delta_f = sound(i).freq_sample / sound(i).N;
    sound(i).f_axis = [0: sound(i).delta_f: sound(i).freq_sample-sound(i).delta_f];
    
    figure(10+i)
    semilogx(sound(i).f_axis(1:0.5*end), 20*log10( abs((2/sound(i).N)*sound(i).sample_fft(1:0.5*end)) ) );
    title("DFT af " + sound(i).name)
    xlabel("Frekvens (Hz)")
    ylabel("Amplitude(dB)")
    hold on
    
    [sound(i).freq_oct, sound(i).fft_freq] = oct_smooth(sound(i).sample_fft, sound(i).freq_sample, 18, [1 22000]);
    
    semilogx(sound(i).freq_oct, 20*log10(abs((2/sound(i).N)*sound(i).fft_freq)),'r','linewidth',1.5)
    hold off
    
end















