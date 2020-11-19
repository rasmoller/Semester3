clc; clear;

d = [352 372 392 412 432 452 471 570 669 767 867 966 1066 1268 1465 1661 1861 2059 2258];

a = @(x) 1.9853 * x + 272.5;
b = @(x) 1.9885 * x + 275.19;

x1 = [0 : 10 : 100];
x2 = [150 : 50 : 400];
x3 = [500 : 100 : 1000];
x = [x1, x2, x3];
xx = [40, 50, 60, 70, 80, 90, 100, x2, x3]


figure
hold on
plot(x, a(x), '-o')
plot(x, b(x), '-o')
axis([0 40 270 300])
title("Plot af drift forskel")
xlabel("Weight(kg)")
ylabel("signal(~)")
legend('Uden drift', 'med drift')

f = polyfit(xx, d, 1);
g = polyval(f,xx);


figure
hold on
plot(xx,d,'*')
plot(xx,g)
title("Plot af signal  ud fra vægt - med tendens linje")
xlabel("Weight(kg)")
ylabel("signal(~)")

