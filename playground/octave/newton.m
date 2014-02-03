function y=newton(f,x0,k)
    h = 0.00001
    x(1) = x0;
    y(1) = f(x0);

    for i=1:k
        slope = (f(x(i)+h)-y(i))/h; 
        x(i+1) = x(i) - y(i)/slope; 
        y(i+1) = f(x(i+1));
    end 

    disp([x ; y]');
    y=y';
endfunction
