close all;
clear all;
s=tf('s');
z=tf('z');
opts = bodeoptions;
opts.FreqUnits = 'Hz';
f0=0.1;
w0=2*pi*f0;
Hs=(s/w0)/(1+(s/w0));
bode(Hs,opts);
Fs=10;
Ts=1/Fs;
num_in_w0=exp(i*w0*Ts)-1;
den_in_w0=exp(i*w0*Ts)-exp(-w0*Ts);
gain_in_w0=10^(-3/20); % -3db
K1=gain_in_w0/abs(num_in_w0/den_in_w0);
Hz=K1*c2d(Hs,Ts);
opts = bodeoptions;
opts.FreqUnits = 'Hz';
bode(Hs,Hz,opts);
% Depurar a nivel de muestra
input=ones(1,100);
output=filter(cell2mat(Hz.Numerator),cell2mat(Hz.Denominator),input);
output(1:20)


