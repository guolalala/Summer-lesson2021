U=solvexue(-3,3,10,2,0.25,500);

function y = u0(x)
%u0 - Myfun
%
% Syntax: y = u0(x)
%
% initial value
    y = 5*exp(2*1i*x-25*x*x/4);
end


function U = solvexue(xl, xr, R, T, h, M)
%solvexue - My solve func
%
% Syntax: U = solvexue(xl,xr,R,T,h,M)
%
% xl for left value, xr for right value, T for time, M for grid number
    tau = T / M;
    N = (xr - xl) / h + 2 * (R / h);
    mu = 1i * tau / (h*h);

    A = zeros(N + 1, N + 1);

    for m = 1:N + 1

        if (m == 1)
            A(m, m) = 1 - 2 * mu;
            A(m, m + 1) = mu;
        elseif (m == N + 1)
            A(m, m) = 1 - 2 * mu;
            A(m, m - 1) = mu;
        else
            A(m, m) = 1 - 2 * mu;
            A(m, m - 1) = mu;
            A(m, m + 1) = mu;
        end

    end

    ans = zeros(N + 1, M + 1);
    x = zeros(N + 1, 1);
    x(1) = xl - R;

    for v = 1:N
        x(v + 1) = x(v) + h;
    end

    for v = 0:N
        ans(v + 1, 1) = u0(x(v + 1));
    end

    for n = 1:M
        ans(:, n + 1) = A * ans(:, n);

    end

    t = xl:h:xr;
    plot(t, abs(ans((R/h + 1):(R/h + ((xr-xl)/h) + 1), M + 1)));

end
