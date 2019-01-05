clear all
clc

exact = 2;
h1=pi/4;
h2=pi/8;
h3= pi/16;
h4= pi/32;
I_4=I_8=I_16=I_32=0;

for i=1:3
  I_4+=(h1^3/24+h1/2)*(sin(h1*(i))+sin(h1*(i+1)));
endfor

for i=1:7
  I_8+=(h2^3/24+h2/2)*(sin(h2*(i))+sin(h2*(i+1)));
endfor

for i=1:15
  I_16+=(h3^3/24+h3/2)*(sin(h3*(i))+sin(h3*(i+1)));
endfor

for i=1:31
  I_32+=(h4^3/24+h4/2)*(sin(h4*(i))+sin(h4*(i+1)));
endfor

I= [I_4,I_8,I_16,I_32];
h= [h1,h2,h3,h4];
error = exact-I;
log(h)
log(error)
plot(log(h),log(error),"*b")