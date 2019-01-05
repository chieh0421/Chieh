clear all
clc

function value=f_B1(x)
  value = sin(3*x)+3*cos(6*x);
endfunction

function exact_diff = df_B1(x)
  exact_diff = 3*cos(3*x)-18*sin(6*x);
endfunction

function value=f_B2(x)
  value = 6*x-3*x.^2;
endfunction

function exact_diff = df_B2(x)
  exact_diff = 6-6*x;
endfunction

x_N16 = [0:2*pi/16:2*pi];
x_N32 = [0:2*pi/32:2*pi];
xin_N16 = [x_N16(2:16)];
xin_N32 = [x_N32(2:32)];
x16 = x_N16(1:16);
x32 = x_N32(1:32);

#Fourier
fft_B1_16 = fft(f_B1(x16));
fft_B1_32 = fft(f_B1(x32));
fft_B2_16 = fft(f_B2(x16));
fft_B2_32 = fft(f_B2(x32));
fft_dfB1_16 = real(ifft(fft_B1_16.*[0:1:7,-8:1:-1]*j));
fft_dfB1_32 = real(ifft(fft_B1_32.*[0:1:15,-16:1:-1]*j));
fft_dfB2_16 = real(ifft(fft_B2_16.*[0:1:7,-8:1:-1]*j));
fft_dfB2_32 = real(ifft(fft_B2_32.*[0:1:15,-16:1:-1]*j));

#central
i_16 = [2:1:16];
i_32 = [2:1:32];
cen_B1_16 = (f_B1(x_N16(i_16+1))-f_B1(x_N16(i_16-1)))/(2*2*pi/16);
cen_B1_32 = (f_B1(x_N32(i_32+1))-f_B1(x_N32(i_32-1)))/(2*2*pi/32);
cen_B2_16 = (f_B2(x_N16(i_16+1))-f_B2(x_N16(i_16-1)))/(2*2*pi/16);
cen_B2_32 = (f_B2(x_N32(i_32+1))-f_B2(x_N32(i_32-1)))/(2*2*pi/32);

#exact
i = [0:0.01:2*pi];
exa_B1 = df_B1(i);
exa_B2 = df_B2(i); 

figure(1);
plot(i,exa_B1,"-b",x16,fft_dfB1_16,"sk",x_N16(i_16),cen_B1_16,"^r");
legend("exact","FFT","central");
xlabel("x");
ylabel("f'(x)");
title("B1 for N=16");
print("-djpg","B1_N16");

figure(2);
plot(i,exa_B1,"-b",x32,fft_dfB1_32,"sk",x_N32(i_32),cen_B1_32,"^r");
legend("exact","FFT","central");
xlabel("x");
ylabel("f'(x)");
title("B1 for N=32");
print("-djpg","B1_N32");

figure(3);
plot(i,exa_B2,"-b",x16,fft_dfB2_16,"sk",x_N16(i_16),cen_B2_16,"^r");
legend("exact","FFT","central");
xlabel("x");
ylabel("f'(x)");
title("B2 for N=16");
print("-djpg","B2_N16");

figure(4);
plot(i,exa_B2,"-b",x32,fft_dfB2_32,"sk",x_N32(i_32),cen_B2_32,"^r");
legend("exact","FFT","central");
xlabel("x");
ylabel("f'(x)");
title("B2 for N=32");
print("-djpg","B2_N32");
