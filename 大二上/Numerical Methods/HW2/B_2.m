clear all
clc

N=100;
n=[0:1:N/2];
#k=2*pi*n/L  h=L/N
kh=2*pi*n/N;
kph_second=sin(kh);
kph_fourth=(-1*sin(2*kh)+8*sin(kh))/6;
kph_pade=3*sin(kh)./(2+cos(kh));

figure(1);
xlim([0,pi]);
ylim([0,pi]);
hold;
plot(kh,kh);
plot(kh,kph_second,"--");
plot(kh,kph_fourth,":");
plot(kh,kph_pade,"-.");
legend("Exact", "2nd O Central","4th O Central", "4th O Pade","location","northwest");
xlabel("kh");
ylabel("k'h");
title("B.2");
print("-djpg","B_2");