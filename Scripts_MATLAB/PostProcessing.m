close all;
clear all;
clc;

%Ben Latimer 2018
%Code to analyze model outputs

spikes = load('../Data_Output/data');
figure
plot(spikes(:,1),spikes(:,2),'.')



PlotVoltages([1878:1:1879],'../Data_Output/Voltage/')

vclamp = load('../Data_Output/current');

figure
plot(vclamp(:,1));

PlotVoltages([1877:1:1884],'../Data_Output/Voltage/')

pause(20)

