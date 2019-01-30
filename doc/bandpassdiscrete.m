close all;
s=tf('s');
z=tf('z');
opts = bodeoptions;
opts.FreqUnits = 'Hz';
fc=1e3;
wn = 2*pi*fc;
fs=10e3;
Ts=1/fs;
%% Filtro segundo orden
Q=12;
zeta = 1/(2*Q);
F2th = (2*zeta/wn)*s/[(s/wn)^2 + 2*zeta*(s/wn) + 1]

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

%%Calculo de ganancia en wn
num_in_wn=exp(i*wn*Ts)-1
den_in_wn=a0*exp(i*2*wn*Ts)+a1*exp(i*wn*Ts)+a2
gain_in_wn=1;
K1=gain_in_wn/abs(num_in_wn/den_in_wn);

Ffinal=(K1*(z-1))/(a0*z^2+a1*z+a2)
Ffinal.Ts=Ts;
figure;
bode(F2thD,Ffinal,opts)

input=ones(1,100);
output=filter(cell2mat(Ffinal.Numerator),cell2mat(Ffinal.Denominator),input);
output(1:20)


