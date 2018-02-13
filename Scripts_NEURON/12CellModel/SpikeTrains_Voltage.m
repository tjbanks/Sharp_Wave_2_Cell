close all;
clear all;
load voltage;
load data;

Trace_1 = voltage(:,1);
Trace_2 = voltage(:,2);

hold all
plot(Trace_1,'r');
plot(Trace_2,'b');
legend('pyramidal','chandelier')
hold off

figure
plot(data(:,1),data(:,2),'.')



