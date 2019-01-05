clear all
clc

function value=f(x)
  value=sin(x)./x.^3;
endfunction

function value=df(x)
  value=cos(x)./x.^3-3*sin(x)./x.^4;
endfunction

h=[1,0.5,0.1,0.05,0.01,0.005];
figure(1);
hold on;

#first order
error = abs(df(4)- (f(4+h)-f(4))./h);
plot(log10(h),log10(error),"b+");
plot(log10(h),log10(error),"b",'HandleVisibility','off');

#second order
error = abs(df(4)- (f(4+h)-f(4-h))./(2*h));
plot(log10(h),log10(error),"r+");
plot(log10(h),log10(error),"r",'HandleVisibility','off');

#fourth order
error = abs(df(4)- (f(4-2*h)-8.*f(4-h)+8.*f(4+h)-f(4+2*h))./(12*h));
plot(log10(h),log10(error),"k+");
plot(log10(h),log10(error),"k",'HandleVisibility','off');

legend("first order","second order","fourth order","location","northwest");
xlabel("log(h)");
ylabel("log(error)");
title("A.2");
print("-djpg","A_2");