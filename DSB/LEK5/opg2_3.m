clc;
clear;

load result22


%figure(2)
%semilogx(20*log10(abs((1/N1)*S1(1:0.5*fsample))))
%hold on
%semilogx(20*log10(abs((1/N2)*S2(1:0.5*fsample))),'r')



semilogx(20*log10(abs((1/12000)*a1(1:0.5*12000))))