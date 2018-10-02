clear all
clc


function [y]=lagrange(x,x0,y0)
  #x0,y0:�w���ƾ��I 
  n=size(x0',1); 
  y=0;
  for j=1:n
    Lj=1;
    Ljx0=1;
    for i=1:n
      if i==j #�קK���H�s�����p
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
    print ("-djpg",["C_L",dec2base(j, 10),".jpg"]);
    Lj*=y0(j);
    y+=Lj;
  endfor
endfunction
xi=[-1.0000,-0.9511,-0.8090,-0.5878,-0.3090,0.0000,0.3090,0.5878,0.8090,0.9511,1.0000];
yi=[0.0385,0.0424,0.0576,0.1038,0.2952,1.0000,0.2952,0.1038,0.0576,0.0424,0.0385]; 
x=[-1:0.01:1];
y=lagrange(x,xi,yi);
figure(12)
plot(x,y,xi,yi,"b+")
xlabel("x");
ylabel("f(x)");
legend("f(x)","(x0,y0)");
title("Lagrange polynomial");
print("-djpg","C_Lagrange polynomial");