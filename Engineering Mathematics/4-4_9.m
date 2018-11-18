clear all
clc
t = [-1:0.1:1];
c1=[-2:1:2];
c2 = [-2:1:2];
figure(1);
hold on
for i=c1
  for j=c2
    y1 = 3*i*exp(2*t)+j*exp(3*t);
    y2 = -4*i*exp(2*t)-j*exp(3*t);
    plot(y1,y2);
  endfor
endfor
hold off

