clc; clear;

%% Opgave 3.1

x = randn(1,200);

bLP = 0.125*[1 1 1 1 1 1 1];
bHP = [1 -1 1 -1];

yLP = filter(bLP,1,x);
yHP = filter(bHP,1,x);



