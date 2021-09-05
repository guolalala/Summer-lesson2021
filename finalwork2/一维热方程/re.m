U = solveheat(40, 1000, 40)

function y = u0(x)
    %u0 - Myfun
    %
    % Syntax: y = u0(x)
    %
    % My function
    y = sin(pi * x);
end

function U = solveheat(N, T, M)
    %solveheat - solve function
    %
    % Syntax: U = solveheat(N,T,M)
    %
    % N and M for grid number; T for time
    h = 1 / N;
    tau = T / M;

    U = zeros(N + 1, M + 1);
    A = zeros(N - 1, N - 1);
    F = zeros(N - 1, 1);

    nu = tau / (2 * h * h);

    for i = 0:N
        U(i + 1, 1) = u0(i * h);
    end

    for m = 1:N - 1

        if (m == 1)
            A(m, m) = 1 + 2 * nu;
            A(m, m + 1) = -nu;
        elseif (m == N - 1)
            A(m, m) = 1 + 2 * nu;
            A(m, m - 1) = -nu;
        else
            A(m, m) = 1 + 2 * nu;
            A(m, m - 1) = -nu;
            A(m, m + 1) = -nu;
        end

    end

    A1 = A^(-1);

    for n = 0:M - 1

        for j = 1:N - 1
            F(j, 1) = (1 - 2 * nu) * U(j + 1, n + 1) + nu * U(j, n + 1) + nu * U(j + 2, n + 1);
        end

        U(2:N, n + 2) = A1 * F;
    end

    x = 0:h:1;

    for n = 0:M
        plot(x, U(:, n + 1));
        axis([0, 1, 0, 1]);
        drawnow;
    end

end
