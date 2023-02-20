.PHONY: all  clean test  s21_matrix_oop.a objects build_lib rebuild clean_obj
CC=gcc
CFLAGS=-Wall -Werror -Wextra -lstdc++
TST_CFLAGS:= -g $(STDFLAGS) -g
GCOV_FLAGS?=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose


all: test

s21_matrix_oop.a: build_lib clean_obj

build_lib: objects
	@ar rc s21_matrix_oop.a s21_matrix_oop.o
	@ranlib s21_matrix_oop.a

objects:
	@$(CC) $(CFLAGS) -c s21_matrix_oop.cpp

test: s21_matrix_oop.a test.cpp
	@$(CC) $(CFLAGS) -lgtest test.cpp s21_matrix_oop.a -o test
	@./test

check:
	# cp ../materials/linters/CPPLINT.cfg .
	# python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp
	@CK_FORK=no leaks --atExit -- ./test

clean_obj:
	@rm -rf *.o

clean:
	@rm -rf *.a ./test CPPLINT.cfg
	# @rm -rf ./test
	# @rm -rf CPPLINT.cfg

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) ${TEST_SRC} ${SRC} -o test $(LIBS)

endif
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	$(OPEN_CMD) ./report/index.html


rebuild: clean all
