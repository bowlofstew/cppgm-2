all: recog

# build posttoken application
recog: recog.cpp pptoken.cpp posttoken.cpp ctrlexpr.cpp macro.cpp preproc.cpp code.cpp
	g++ -g -std=gnu++0x -DPA6 -Wall -o recog recog.cpp

gram: gram_gen.cpp
	g++ -g -std=gnu++0x -DPA6 -Wall -o gram_gen gram_gen.cpp


# test posttoken application
test: all
	scripts/run_all_tests.pl recog my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl recog-ref ref

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

clean:
	rm -rf a.out recog pptoken posttoken ctrlexpr macro preproc




