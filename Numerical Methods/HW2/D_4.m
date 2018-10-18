clear all
clc

N=100;
n=[0:1:N/2];
kh=2*pi*n/N;
kph_D1=2-2*cos(kh);
kph_D3=(12-12*cos(kh))./(cos(kh)+5);
figure(1);
hold;
xlim([0,pi]);
plot(kh,kh.^2,"k",kh,kph_D1,"b",kh,kph_D3,"r");
legend("Exact","D1","D3","location","northwest");
xlabel("kh");
ylabel("k'h");
title("D.4");
print("-djpg","D_4");