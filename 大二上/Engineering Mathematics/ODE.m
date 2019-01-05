clear all
clc
t = [-5:0.01:5];
c1=[-2:1:2];
c2 = [-2:1:2];
figure(1);
hold on
for i=c1
  for j=c2
    y1 = 3*i*cos(t/3)+3*j*sin(t/3);
    y2 = -1*i*sin(t/3)+j*cos(t/3);
    plot(y1,y2,"b");
  endfor
endfor
hold off

