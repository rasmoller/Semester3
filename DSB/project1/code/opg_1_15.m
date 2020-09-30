clear;
clc;

Fs = 5000; %Samplingsfrekvens
Ts = 1/Fs; % Tid per sampling

length = 1; % Længde i sekunder
Ns = Fs*length; % Antallet af samples
t = [0:Ns-1]*Ts; % Tiden over samplingen

%Tone beskrivelse
f0 = 2350; %440 Hz tone
A = 3; % Amplitude er 3
tone = A * sin(f0*2*pi*t); %Tonen som funktion

e.delay = 300; %ekko med 150 ms forsinkelse
e.Ns = e.delay * (Fs/1000); %Antallet af samples i ekkoet

tone_ekko = [zeros(1,e.Ns), tone]; %Forsinker ved at smide 0'er ind foran
tone_ext = [tone, zeros(1,e.Ns)]; % Forlænger ved at smide 0'er ind bagved

tone_sum = tone_ekko + tone_ext
ekko_t = [0:Ns+e.Ns-1]*Ts;

figure
plot(t, tone);
title("Original tone");
xlabel("Tid - sekunder");
ylabel("Amplitude - ~");

figure
plot(ekko_t, tone_ekko);
title("Ekko");
xlabel("Tid - sekunder");
ylabel("Amplitude - ~");

figure
plot(ekko_t, tone_sum);
title("Ekko + Original");
xlabel("Tid - sekunder");
ylabel("Amplitude - ~");

soundsc(tone_sum)
