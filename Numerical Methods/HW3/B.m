clear all
clc

#origin function f(x)=(x+0.5)^-2

function result=sec_central(x,h);
  result=((x+h+0.5).^-2-(x-h+0.5).^-2)/2/h;
endfunction

function exact=exact_dif(x);
  exact = (-2*(x+0.5).^-3);
endfunction

x = [1,5]

h0=0.5;
h1=h0/2;
h2=h1/2;
h3=h2/2;
exact = exact_dif(x)
I0 = sec_central(x,h0)
I1 = sec_central(x,h1)
I2 = sec_central(x,h2)
I3 = sec_central(x,h3)
I01 = (4*I1-I0)/3
I12 = (4*I2-I1)/3
I23 = (4*I3-I2)/3
I012 = (16*I12-I01)/15
I123 = (16*I23-I12)/15
I0123 = (64*I123-I012)/63
