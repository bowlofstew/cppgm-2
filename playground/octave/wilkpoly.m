function y=wilkpoly(s)
    x = sym("x");
    f=1;
    for i=1:20
        f=f*(x-i);
    end
    f=collect(f,x);
    y=subs(f,x,s);
endfunction
