function x=linearEqusLU(A,b)
    if (length(A) != length(A'))
        error("Takes only square matrix A");
    end

    len = length(A); 

    U = diag(ones(len,1));

    for j=1:len
        pivot = A(j,j);
        if (pivot == 0)
            error("pivot at A(%d,%d)",i,j);
        end
        for i=j+1:len
            factor = A(i,j)/pivot;
            A(i,:) = A(i,:) .- A(j,:)*factor;
            U(i,j) = factor;
            b(i) = b(i) - b(j)*factor;
        end 
    end

    disp(A); #L
    disp(U); #U
    disp(U*A);
    disp(b);

    for i=len:-1:1
        for j=i+1:len
            b(i) = b(i) - x(j)*A(i,j);
        end
        x(i) = b(i) / A(i,i);
    end

    x = x';
    disp(x);
endfunction
