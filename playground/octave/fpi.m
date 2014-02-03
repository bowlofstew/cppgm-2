# fixed point iteration
function y=fpi(f, x0, k)
    x = x0;
    xv(1) = x;
    for i=1:k
        x = f(x);
        xv(i+1) = x;
    end 
    xv = xv';

    # format long;
    # disp(xv);
    for i=1:k+1
        printf("%d  %g\n",i,xv(i));
    end

    y=xv(k+1);
endfunction
