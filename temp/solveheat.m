function U = solveheat(T,N,M)
%UNTITLED 此处显示有关此函数的摘要
%   此处显示详细说明
h=1/N;
tau=T/M;
mu=tau/(h^2);

U=zeros(N+1,M+1);

for j=0:N
    U(j+1,1)=u0(j*h);
end
for n=0:M-1
    for j=1:N-1
        U(j+1,n+2)=(1-2*mu)*U(j+1,n+1)+mu*U(j,n+1)+mu*U(j+2,n+1);
    end
end

x=0.1/h:1;

end

