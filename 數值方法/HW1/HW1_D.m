clear all
clc

xi=[-1.0000,-0.9511,-0.8090,-0.5878,-0.3090,0.0000,0.3090,0.5878,0.8090,0.9511,1.0000];
yi=[0.0385,0.0424,0.0576,0.1038,0.2952,1.0000,0.2952,0.1038,0.0576,0.0424,0.0385];
n=size(xi',1);
A=zeros(n,n);
R=zeros(n,1); #A*sov=R
for i=1:n
   if (i==1 | i==n)
   A(i,i)=1;
   R(i)=0;
   continue
   endif
   A(i,i-1)=(xi(i)-xi(i-1))/6;
   A(i,i)=(xi(i+1)-xi(i-1))/3;
   A(i,i+1)=(xi(i+1)-xi(i))/6;
   R(i)=(yi(i+1)-yi(i))/(xi(i+1)-xi(i))-(yi(i)-yi(i-1))/(xi(i)-xi(i-1));
endfor
sov=A\R #second order value

figure(1)
x=[];
y=[];
for i=1:n-1
  x_now=xi(i):0.01:xi(i+1);
  di=xi(i+1)-xi(i);
  y_now=sov(i)/6 *((xi(i+1)-x_now).^3/di-di*(xi(i+1)-x_now))...
  + sov(i+1)/6 *((x_now-xi(i)).^3/di-di*(x_now-xi(i)))...
  + yi(i)*(xi(i+1)-x_now)/di + yi(i+1)*(x_now-xi(i))/di;
  x=[x,x_now];
  y=[y,y_now];
  if (i==1)
    hold on;
  elseif (i==n-1)
    hold off;
  endif
endfor
plot(x,y,xi,yi,"b+")
xlabel("x");
ylabel("f(x)");
legend("f(x)","(x0,y0)");
title("cubic spline");
print("-djpg","D_cubic spline");