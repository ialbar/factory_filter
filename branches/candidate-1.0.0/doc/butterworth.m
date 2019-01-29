close all;
Fs=8000;  % Sampling
fc=800;   % Cut off
fstop= 1600; % Fstop  
Rp=1; % Passban ripple in db
Rs=20; %stop band attenuation in db
Wp=2*fc/Fs;
Ws=2*fstop/Fs;

[N,Wn]=buttord(Wp,Ws,Rp,Rs);
[b,a]=butter(N,Wn);
[Z,P,K]=tf2zp(b,a);
[sos,G]=zp2sos(Z,P,K);

input=ones(1,100);
output=filter(b,a,input);
output(1:20)
plot(output)
