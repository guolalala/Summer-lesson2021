
solve=feat_implicit(20,0.5,256);

function y = u0(x)
y=sin(pi*x);
end

function y = feat_implicit(N,T,M)
h=1/N;
tau=T/M;
mu=tau/(2*h^2);
 
U=zeros(N+1,M+1);
A=zeros(N-1,N-1);
F=zeros(N-1,1);

for m=1:N+1
    U(m,1)=u0((m-1)*h);
end

for m=1:N-1
    if (m==1)
        A(m,m)=1+2*mu;
        A(m,m+1)=-mu;
    elseif (m==N-1)
        A(m,m-1)=-mu;
        A(m,m)=1+2*mu;
    else
        A(m,m-1)=-mu;
        A(m,m)=1+2*mu;
        A(m,m+1)=-mu;
    end
end

for n=0:M-1
    for j=1:N-1
        F(j)=(1-2*mu)*U(j+1,n+1)+mu*U(j-1+1,n+1)+mu*U(j+1+1,n+1);
    end
    U(2:N,n+2)=A^(-1)*F;
end

xx=0:h:1;
for n=0:M
    plot(xx,U(:,n+1));
    axis([0 1 0 1]);
    drawnow;
end
y=0;
end
