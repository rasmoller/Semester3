clc;
clear;

f_0 = 400;
A = 1;
t1 = linspace(0,1,12000);%Samplefrekvens er 12kHz, ergo 12000 målinger per. sekund
a1 = A*sin(2*pi*f_0*t1);

dft1 = fft(a1,12000);
plot(abs(dft1))

hold on

t2 = linspace(0,0.1,1200);
a2 = 2 + A*sin(2*pi*f_0*t2);

dft2 = fft(a2,12000);
plot(abs(dft2),'r');

save result22

audiowrite('firstsine.wav', a1, 12000)