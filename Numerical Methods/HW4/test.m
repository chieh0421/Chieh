clear all
clc

N = 7;
PI = 3.1415926;
x_ref = -1:0.01:1;
x = cos(PI * [0:1:N] /N);
x = x';
function re = u(x)
  re = 4*(x.^2 - x.^4).*exp(x/-2);
endfunction
function re = du(x)
  re = (2*x.*(x.^3 - 8*x.^2 - x +4).*exp(x/-2));
endfunction
function re = ddu(x)
  re = -(x.^4 - 16*x.^3 + 47*x.^2 + 8*x -8).*exp(x/-2);
endfunction
uvec = u(x);

#---create matrix G---
G = zeros(N+1,N+1);
for i = 1:8
  for k = i+1:8
    if (rem(k+i,2) == 1)
      G(i,k) = 2*(k-1);
    endif
    if (i == 1)
      G(i,k) /= 2;
    endif
  endfor
endfor
#---

#---create matrix T---
T = zeros(N+1,N+1);
%% for chebyshev polynomial T_n(cos(theda)) = cos(n*theda)
%% T_n(x) = cos(n*arccos(x))
function re = chebyshev(n,x)
  re = cos(n*acos(x));
endfunction

for i = 1:(N+1)
  for k = 1:(N+1)
    T(i,k) = chebyshev(k-1,x(i));
  endfor
endfor

#---

#--create matrix T_hat---
T_hat = zeros(N+1,N+1);
for i = 1:(N+1)
  for k = 1:(N+1)
    T_hat(i,k) = 2*chebyshev(i-1,x(k))/N;
    if (k == 1 || k == (N+1))
      T_hat(i,k) /= 2;
    endif
    if (i == 1 || i == (N+1))
      T_hat(i,k) /= 2;
    endif
  endfor
endfor
#---

D = T*G*T_hat;

duvec = D*uvec
dduvec = D*D*uvec;
du_exact = du(x)
ddu_exact = ddu(x_ref);

