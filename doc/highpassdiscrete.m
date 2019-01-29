close all;
s=tf('s');
opts = bodeoptions;
opts.FreqUnits = 'Hz';
fc=2e3;
wn = 2*pi*fc;
fs=10e3;
Ts=1/fs;
%% Filtro segundo orden
Q=20;
zeta = 1/(2*Q);
F2th = (s/wn)^2/[(s/wn)^2 + 2*zeta*(s/wn) + 1]

bode(F2th,opts);
F2thD=c2d(F2th,Ts)
figure;
bode(F2thD);

polos=pole(F2thD)
ceros=zero(F2thD)
r1=-((wn/Q)+sqrt((wn/Q)^2 - 4*(wn^2)))/2
r2=-((wn/Q)-sqrt((wn/Q)^2 - 4*(wn^2)))/2

%% Cálculos para parametrizar el filtro de segundo orden en C
close all;
a0=1
a1=-(exp(r1*Ts)+exp(r2*Ts));
a2=exp(r1*Ts)*exp(r2*Ts);

NumZ=((z-1)/wn)^2
zeros=zero(NumZ)
b0=1;
b1=-2;
b2=1;

%Calculo de ganancia
num_in_wn=(b0*exp(i*2*wn*Ts)+b1*exp(i*wn*Ts)+b2)
den_in_wn=a0*exp(i*2*wn*Ts)+a1*exp(i*wn*Ts)+a2
gain_in_wn=1/((2*zeta)*sqrt(1-zeta^2));

K1=gain_in_wn/abs(num_in_wn/den_in_wn);

Hz_estimada= (K1)*(b0*z^2+b1*z^1+b2)/(a0*z^2+a1*z^1+a2);
Hz_estimada.Ts=Ts;
bode(F2th,Hz_estimada,opts)

input=ones(1,100);
output=filter(cell2mat(Hz_estimada.Numerator),cell2mat(Hz_estimada.Denominator),input);
output(1:20)



