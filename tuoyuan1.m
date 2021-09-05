
u=ellipse1(0,1,0,0,100);
u1=[0;u;0];
x=zeros(100+1,1);
for i=1:100+1
    x(i)=i;
end

plot(x,u1);

function y = f(x)
y=10*sin(x);
end

function y = ellipse1(a,b,ua,ub,n)
A= zeros(n-1);
h=(b-a)/n;
b=zeros(n-1,1);

A(n-1,n-1)=-2;
for i=1:1:n-2
    A(i,i+1)=1;
    A(i,i)=-2;
    A(i+1,i)=1;
end


for i=1:1:n-1
    b(i,1)=h^2*f(i*h);
end
b(1,1)=b(1,1)-ua;
b(n-1,1)=b(n-1,1)-ub;

y=A^(-1)*b;
end
