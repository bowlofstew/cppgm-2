all: nsdecl

# build posttoken application
nsdecl: nsdecl.cpp pptoken.cpp posttoken.cpp ctrlexpr.cpp macro.cpp preproc.cpp
	g++ -g -std=gnu++0x -DPA7 -Wall -o nsdecl nsdecl.cpp

gram: gram_gen.cpp
	g++ -g -std=gnu++0x -DPA6 -Wall -o gram_gen gram_gen.cpp

# test posttoken application
test: all
	scripts/run_all_tests.pl nsdecl my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl nsdecl-ref ref

pa1-test:
	g++ -g -std=gnu++0x -Wall -DPA1 -o pptoken pptoken.cpp
	cp pptoken ../pa1
	cd ../pa1; make test

pa2-test:
	g++ -g -std=gnu++0x -Wall -DPA2 -o posttoken posttoken.cpp
	cp posttoken ../pa2
	cd ../pa2; make test

pa3-test:
	g++ -g -O2 -std=gnu++0x -Wall -DPA3 -o ctrlexpr ctrlexpr.cpp
	cp ctrlexpr ../pa3
	cd ../pa3; make test

pa4-test:
	g++ -g -std=gnu++0x -Wall -DPA4 -o macro macro.cpp
	cp macro ../pa4
	cd ../pa4; make test

pa5-test:
	g++ -g -std=gnu++0x -Wall -DPA5 -o preproc preproc.cpp
	cp preproc ../pa5
	cd ../pa5; make test

pa6-test: recog.cpp pptoken.cpp posttoken.cpp ctrlexpr.cpp macro.cpp preproc.cpp pa6_code.cpp
	g++ -g -std=gnu++0x -DPA6 -Wall -DPA6 -o recog recog.cpp
	cp recog ../pa6
	cd ../pa6; make test



clean:
	rm -rf a.out recog pptoken posttoken ctrlexpr macro preproc




