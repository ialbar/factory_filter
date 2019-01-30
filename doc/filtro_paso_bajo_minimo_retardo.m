close all;
clear all;
s=tf('s');
z=tf('z');
f0=0.1e3;
w0=2*pi*f0;
Hs=1/(1+(s/w0));
Fs=10e3;
Ts=1/Fs;
Hz=c2d(Hs,Ts)
a=exp(-w0*Ts)
HzMin=Hz*z % adding un zero en el origen busando el mínimo retardo del sistema.
figure;
opts = bodeoptions;
opts.FreqUnits = 'Hz';
bode(Hz,HzMin,opts);
figure;
step(Hz);
hold on;
step(HzMin);
a1=-exp(-2*pi*f0*Ts)
b0=1-exp(-2*pi*f0*Ts)
% input=ones(1,100);
% output=filter(cell2mat(HzMin.Numerator),cell2mat(HzMin.Denominator),input);
% output(1:20)



