clear all
clc


function [y]=lagrange(x,x0,y0)
  #x0,y0:已知數據點 
  n=size(x0',1); 
  y=0;
  for j=1:n
    Lj=1;
    Ljx0=1;
    for i=1:n
      if i==j #避免除以零的情況
        continue
      endif
      Lj.*= (x-x0(i))/(x0(j)-x0(i));
      Ljx0.*= (x0-x0(i))/(x0(j)-x0(i));
    endfor
    figure(j)
    plot(x,Lj,x0,Ljx0,"b+")
    xlabel("x");
    ylabel("Lj(x)");
    legend("Lj(x)","(x0,Lj(x0))");
    title(["L",dec2base(j, 10),"(x)"]);
    print ("-djpg",["A_L",dec2base(j, 10),".jpg"]);
    Lj*=y0(j);
    y+=Lj;
  endfor
endfunction
xi=[-1:0.2:1];
yi=[0.0385,0.0588,0.1000,0.2000,0.5000,1.0000,0.5000,0.2000,0.1000,0.0588,0.0385]; 
x=[-1:0.01:1];
y=lagrange(x,xi,yi);
figure(12)
plot(x,y,xi,yi,"b+")
xlabel("x");
ylabel("f(x)");
legend("f(x)","(x0,y0)");
title("Lagrange polynomial");
print("-djpg","A_Lagrange polynomial");