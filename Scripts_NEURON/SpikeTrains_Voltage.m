close all;
clear all;
load voltage;
load data;

Trace_1 = voltage(:,1);

hold all
plot(Trace_1,'r');
hold off

figure
plot(data(:,1),data(:,2),'.')



