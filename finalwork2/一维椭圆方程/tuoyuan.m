U=solvetuoyuan(2,4,1000)



function y = f(x)
    %f - Myfun
    %
    % Syntax: y = f(x)
    %
    % My function
    y = cos(x) + sin(x);
end

function U = solvetuoyuan(a1, b1, N)
    %solve - solvetuoyuan
    %
    % Syntax: U = solve(a1,b1,N)
    %
    % a1 for left value, b1 for right value, N for grid number
    U = zeros(N - 1, 1);
    A = zeros(N - 1, N - 1);
    F = zeros(N - 1, 1);
    h = 1 / N;

    for m = 1:N - 1

        if (m == 1)
            A(m, m) = -2;
            A(m, m + 1) = 1;
        elseif (m == N - 1)
            A(m, m - 1) = 1; A(m, m) = -2;
        else
            A(m, m) = -2;
            A(m, m - 1) = 1;
            A(m, m + 1) = 1;
        end

    end

    for m = 1:N - 1

        if (m == 1)
            F(m) = -a1 + h*h * f(m * h);
        elseif (m == N - 1)
            F(m) = -b1 + h*h * f(m * h);
        else
            F(m) = h*h * f(m * h);
        end

    end

    U=A^(-1)*F;
    x=1:N-1;
    plot(x,U);

end
