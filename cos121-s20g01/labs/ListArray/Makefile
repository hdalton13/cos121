TEST = test3
CLASS = ListArray
CPP = g++
TESTOBJS = $(TEST).o

mesg:
	@echo "Make targets are 'test3', 'runcxx', and 'clean'"
	@echo "E.g., type 'make test3'"

test3: $(TESTOBJS)
	@#echo "Not currently enabled"
	g++ -Wall -o $(TEST) $(TESTOBJS)
	@echo "Test executable is \"$(TEST)\""

# *.dSYM are OS X debugging files
clean:
	rm -f $(TEST) $(TESTDNA) *.o listrunner*
	@rm -rf *.dSYM

$(TEST).o: $(TEST).cpp
$(CLASS).o: $(CLASS).cpp $(CLASS).h

#LISTTEST = __instructor_listarray_base_test.h
LISTTEST = __instructor_listarray_test_full.h
LISTFILES = ListArray.cpp ListArray.h
runcxx: listrunner
	./listrunner
listrunner:	listrunner.cpp $(LISTFILES)
	g++ -o listrunner listrunner.cpp ListArray.cpp
listrunner.cpp: $(LISTFILES) $(LISTTEST)
	cxxtestgen.pl --error-printer -o listrunner.cpp $(LISTTEST)

