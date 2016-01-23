
spice_parser : main.cpp pproc.h subckt.h
	g++ -g main.cpp -o spice_parser 

clean:
	rm -rf spice_parser *.o

test:
	cd regression; \
	../fs3qc 0.fs3 -out 0.rc3; \
	../fs3qc 0.fs3 -out 0.cap; \
	diff g0.rc3 0.rc3; \
	diff g0.cap 0.cap; \
	../fs3qc 0.fs3 -out 1.cap -trap 2; \
	../fs3qc 0.fs3 -out 1.rc3 -trap 2; \
	diff g1.rc3 1.rc3; \
	diff g1.cap 1.cap;

diff_test:
	cd test_diff; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff done; \
	cd ../; \
	cd test_diff2; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff2 done; \
	cd ../; \
	cd test_diff3; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff3 done; \
	cd ../; \
	cd test_diff4; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff4 done; \
	cd ../; \
	cd test_diff5; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff5 done; \
	cd ../; \
	cd test_diff6; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff6 done; \
	cd ../; \
	cd test_diff7; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff7 done; \
	cd ../; \
	cd test_diff8; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff8 done; \
	cd ../; \
	cd test_diff9; \
	../fs3qc 0.fs3 -diff 1.fs3 -shiftx 0.005 -shifty 0.005 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff9 done; \
	cd ../; \
	cd test_diff10; \
	../fs3qc 0.fs3 -diff 1.fs3 -shiftx 0.005 -shifty 0.005 > diff.log; \
	diff golden.log diff.log; \
	echo test_diff10 done; \
	cd ../;


update:
	cd regression; \
	cp 0.rc3 g0.rc3; cp 0.cap g0.cap; \
	cp 1.rc3 g1.rc3; cp 1.cap g1.cap;
	cd test_diff5; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	cd ../; \ 
	cd test_diff6; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	cd ../ ; \
	cd test_diff7; \
	../fs3qc 0.fs3 -diff 1.fs3 > diff.log; \
	diff golden.log diff.log; \
	cd ../ 

