clear all
clc

function value = f(x)
  value = sin(2*x)+0.1*sin(15*x);
endfunction

function value = g(x)
  value = sin(2*x) + 0.1*cos(15*x);
endfunction

function value = E(x)
  value = (sin(2*x)+0.1*sin(15*x)).*(sin(2*x)+0.1*cos(15*x));
endfunction

x = [0:2*pi/32:2*pi];
x= x(1:32);

#H
H = f(x).*g(x);
fft_H = fft(H);
sorted_fft_H = [fft_H(16:32),fft_H(1:15)]

#h
fft_f = fft(f(x));
fft_g = fft(g(x));
sorted_fft_f = [fft_f(16:32),fft_f(1:15)];
sorted_fft_g = [fft_g(16:32),fft_g(1:15)];
i = [1:1:32];

#E
fft_E = fft(E(x));
sorted_fft_E = [fft_E(16:32),fft_E(1:15)];