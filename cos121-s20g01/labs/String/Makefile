# Makefile: controls compilation (and running) of the cxxtest runner.
#
#
FILES = String.cpp StringWrapper.cpp

run_tests: runner
	./runner
runner: runner.cpp $(FILES)
	g++ -o runner runner.cpp $(FILES)
runner.cpp: $(FILES) __instructor_test.h
	cxxtestgen.pl --error-printer -o runner.cpp __instructor_test.h

help:
	@echo 'Make options are: clean, run_tests (run cxx tests)'
	@echo E.g. \"make run_tests\"
clean:
	rm -f $(TEST) *.o runner* runner*.cpp

