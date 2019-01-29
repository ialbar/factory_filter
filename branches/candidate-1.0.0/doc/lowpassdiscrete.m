close all;
s=tf('s');
z=tf('z');
opts = bodeoptions;
opts.FreqUnits = 'Hz';
fc=100;
wn = 2*pi*fc;
fs=10e3;
Ts=1/fs;
%% Filtro segundo orden
Q=4;
zeta = 1/(2*Q);
F2th = 1/[(s/wn)^2 + 2*zeta*(s/wn) + 1]

bode(F2th);
F2thD=c2d(F2th,Ts)
figure;
step(F2th,F2thD);

polos=pole(F2th)
r1=-((wn/Q)+sqrt((wn/Q)^2 - 4*(wn^2)))/2
r2=-((wn/Q)-sqrt((wn/Q)^2 - 4*(wn^2)))/2

%% Cálculos para parametrizar el filtro de segundo orden en C
close all;
a0=1
a1=-(exp(r1*Ts)+exp(r2*Ts));
a2=exp(r1*Ts)*exp(r2*Ts);

K=a0+a1+a2;

Hz_estimada= (K)/(a0*z^2+a1*z^1+a2)
Hz_estimada.Ts=Ts;
bode(F2thD,Hz_estimada,opts)

input=ones(1,100);
output=filter(cell2mat(Hz_estimada.Numerator),cell2mat(Hz_estimada.Denominator),input);
output(1:20)

F2thD
Hz_estimada
