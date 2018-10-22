clear all
clc

function value=f(x)
  value=sin(5*x);
endfunction

function value=df(x)
  value=5*cos(5*x);
endfunction

N=14;
L=3;
h=L/N;
x=[0:h:3];
A=zeros(15,15);
R=zeros(15,1);
A(1,1)=1;
A(1,2)=2;
A(15,14)=2;
A(15,15)=1;
R(1)=-5/2*f(x(1))+2*f(x(2))+1/2*f(x(3));
R(15)=5/2*f(x(15))-2*f(x(14))-1/2*f(x(13));
for i=2:14
  A(i,i-1)=1;
  A(i,i)=4;
  A(i,i+1)=1;
  R(i)=3*(f(x(i+1))-f(x(i-1)));
endfor
R/=h;
fov=A\R; #first order value
dx=[0:0.01:3]
plot(x,fov,"b+","markersize",10,dx,df(dx),"k");
legend("Computed Derivative","Exact Derivative","location","south");
xlabel("x");
ylabel("f'(x)");
title("C.2");
print("-djpg","C_2");