clc; clear;
%Array of names of values
names = ["setPoint" "temp" "error" "controlSignal" "Kp" "Ki" "Kd" "proportionalPart" "integralPart" "derivativePart"];

for i = 1:3
    filename = sprintf('data%d.txt',i);
    importeddata = importdata(filename);
    data = struct('name', [], 'values', []);
    
    for d = 1:10
        data(d).name = names(d);
        data(d).values = importeddata(:,d);
    end
    
    %Plots of temp and setPoint
    figure
    x = linspace(1,length(data(2).values)/3,length(data(2).values));
    plot(x,data(2).values,'b','Linewidth',1)
    hold on
    plot(x, data(1).values,'r','Linewidth',1)
    title("Plot of temp. Kp = " + data(5).values(1) + ", Ki = " + data(6).values(1) + ", Kd = " + data(7).values(1))
    xlabel('Time(s)')
    ylabel('temperature(Celsius)')
    legend('Temp', 'setPoint', 'Location', 'best')
    hold off
    
    %Plots of Ki, Kp, Kd
    figure
    plot(x,data(8).values,'b','Linewidth',1)
    hold on
    plot(x, data(9).values,'r','Linewidth',1)
    plot(x, data(10).values, 'y', 'Linewidth',1)
    plot(x, data(4).values, 'g', 'Linewidth',1)
    title("Plot of Kp, Ki og Kd. Kp = " + data(5).values(1) + ", Ki = " + data(6).values(1) + ", Kd = " + data(7).values(1))
    xlabel('Time(s)')
    ylabel('Amplitude(~)')
    legend(data(5).name, data(6).name, data(7).name, data(4).name, 'Location', 'best')
    hold off

end