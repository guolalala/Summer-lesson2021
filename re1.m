
solve=feat_explicit(20,0.5,100);

function y = u0(x)
y=sin(pi*x);
end

function U = feat_explicit(N,tau,M)
h=1/N;
U=zeros(N+1,M+1);

for j=0:N
    U(j+1,1)=u0(j*h);
end

for n=0:M
    for j=1:N-1
        U(j+1,n+1+1)=U(j+1,n+1)+tau/h^2*U(j-1+1,n+1)-2*U(j+1,n+1)+U(j+1+1,n+1);
    end
end

x=0:h:1;

for n=0:M
    plot(x,U(:,n+1));
    axis([0 1 0 1]);
    drawnow;
end
end

