ans= Shrodinger(-5,5,20,5,0.1,1000000);

function y=psi0(x)
y=exp(-4*x^2+5*1i*x);
end

function psi = Shrodinger(xL,xR,R,T,h,M)
tau=T/M;
N1=R/h;
N2=(xR-xL)/h;
N=2*N1+N2;

psi=zeros(N+1,N+1);
x=zeros(N+1,1);
x(1)=xL-R;

for j=1:N
    x(j+1)=x(j)+h;
end

for j=0:N
    psi(j+1,0+1)=psi0(x(j+1));
end

mu=i*tau/h^2;
for n=0:M-1
    for j=1:N-1
        psi(j+1,n+1+1)=(1-2*mu)*psi(j+1,n+1)+mu*psi(j-1+1,n+1)+mu*psi(j+1+1,n+1);
    end
end

plot(x(N1+1:N1+N2+1),abs(psi(N1+1:N1+N2+1,M+1)));

end

