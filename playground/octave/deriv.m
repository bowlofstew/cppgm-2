function y=deriv(f,x0,h=0.00001)
    y0=f(x0);   
    y1=f(x0+h);
    y=(y1-y0)/h; 
endfunction
