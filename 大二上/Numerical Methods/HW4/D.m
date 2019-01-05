clear all
clc

function value = u(x)
  value = 4*(x.^2-x.^4).*exp(-1*x/2);
endfunction

function value = du(x)
  value = 4*(2*x-4*x.^3).*exp(-1*x/2)-2*(x.^2-x.^4).*exp(-1*x/2);
endfunction

function value = d2u(x)
  value = 4*(2-12*x.^2).*exp(-1*x/2)-4*(2*x-4*x.^3).*exp(-1*x/2)...
  +(x.^2-x.^4).*exp(-1*x/2);
endfunction

function c = c(in)
  if in ==1 | in ==8
    c = 2;
  else
    c = 1;
  endif  
endfunction

it = [1:1:8];
j = [0:1:7];
x = cos(pi*j/7);
u = u(x);
D_matrix = zeros(8,8);
for i = it
  for k = it
    if i == k
      if i==1
        D_matrix(i,k) = (2*7*7+1)/6;
      elseif i==8
        D_matrix(i,k) = -1*(2*7*7+1)/6;
      else
        D_matrix(i,k) = -1*(x(i))/2 ./(1-x(i).^2);
      endif
    else
      D_matrix(i,k) = c(i)*((-1)^(i+k))/c(k)./(x(i)-x(k));
    endif
  endfor
endfor

Chebyshev_du = (D_matrix*u')';
D2 = D_matrix * D_matrix;
Chebyshev_d2u = (D2*u')';
xp = [-1:0.01:1];
figure(1);
plot(x,Chebyshev_du,"sk",xp,du(xp),"-b");
legend("Chebyshev","exact");
xlabel("x");
ylabel("u'(x)");
print("-djpg","D1");

figure(2);
plot(x,Chebyshev_d2u,"sk",xp,d2u(xp),"-b");
legend("Chebyshev","exact");
xlabel("x");
ylabel("u''(x)");
print("-djpg","D2");
