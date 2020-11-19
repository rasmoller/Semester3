clc; clear;
%Array of names of values
names = ["Voltage"];

for i = 1:3
    filename = sprintf('data%d.txt',i);
    importeddata = importdata(filename);
    
    data = struct('name', [], 'values', []);
    
    data(i).name = names(1);
    data(i).values = importeddata(:,2);
    
    %Plots of temp and setPoint
    figure
    x = linspace(1,5,length(data(i).values));
    plot(x,data(i).values,'b','Linewidth',1)
    title("Plot of " + data(i).name)
    xlabel('Weight(kg)')
    ylabel('Voltage(V)')
    legend('Voltage')
end