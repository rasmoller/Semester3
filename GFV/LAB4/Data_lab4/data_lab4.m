clc; clear;

%Imports datasets
d1 = importdata('capture.txt');
d2 = importdata('captureP2I0.txt');
d3 = importdata('captureP10I0.txt');

%Array of names of values
names = ["setPoint" "temp" "error" "controlSignal" "Kp" "Ki" "Kd" "proportionalPart" "integralPart" "derivativePart"];

%Creatings structs
importdata1 = struct('name', [], 'values', []);
importdataP2I0 = struct('name', [], 'values', []);
importdataP10I0 = struct('name', [], 'values', []);

%Loading data into structs
for i = 1 : 10
    importdata1(i).name = names(i);
    importdata1(i).values = d1(:,i);
    
    importdataP2I0(i).name = names(i);
    importdataP2I0(i).values = d2(:,i);
    
    importdataP10I0(i).name = names(i);
    importdataP10I0(i).values = d3(:,i);
end

%plots
figure(1)
x = linspace(1,2*872,872);
plot(x,importdata1(2).values,'b','Linewidth',1)
title('Plot of temp')
xlabel('Time(s)')
ylabel('temperature(Celsius)')
legend('Temp', 'Location', 'northwest')

figure(2)
x = linspace(1,2*569,569);
plot(x,importdataP2I0(2).values,'r','Linewidth',1)
title('Plot of P2I0 temp')
xlabel('Time(s)')
ylabel('temperature(Celsius)')
legend('Temp', 'Location', 'northwest')

figure(3)
x = linspace(1,2*275,275);
plot(x,importdataP10I0(2).values,'black','Linewidth',1)
title('Plot of P10I0 temp')
xlabel('Time(s)')
ylabel('temperature(Celsius)')
legend('Temp', 'Location', 'northwest')

