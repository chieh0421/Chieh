clear all
clc
#--------draw L(x) function-----------------
function [y_ref] = lagrange (x_ref, x, y, nsize)
  y_ref = 0;
  #the definition of L(x)
  for j = 1:nsize
    Lj = 1;
    for i = 1:nsize
      if i == j 
        continue
      endif
      Lj .*= (x_ref - x(i)) / (x(j) - x(i));
    endfor
    figure(j)
    plot(x_ref,Lj)
    xlabel("x");
    lname = strcat("L", dec2base(j, 10), "(x)"); #create name of Lj(x)
    ylabel(lname);
    legend(lname);
    y_ref += Lj * y(j);
  endfor
endfunction
#--------------------------------------

#-----------GET DATA-------------------
xi=[-1:0.2:1];
yi=[0.0385,0.0588,0.1000,0.2000,0.5000,1.0000,0.5000,0.2000,0.1000,0.0588,0.0385]; 
#--------------------------------------

#-------------draw P(x)----------------
x_ref = xi(1) : 0.01 : xi(11);
px = lagrange(x_ref, xi, yi, 11);
figure(12)
plot(x_ref, px)
xlabel("x");
ylabel("P(x)");
legend("P(x)");
#-------------------------------------