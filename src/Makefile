.PHONY: all  clean test  s21_matrix_oop.a objects build_lib rebuild clean_obj
CC=gcc
CFLAGS=-Wall -Werror -Wextra -lstdc++

all: test gcov_report

s21_matrix_oop.a: build_lib clean_obj

build_lib: objects
	@ar rc s21_matrix_oop.a s21_matrix_oop.o
	@ranlib s21_matrix_oop.a

objects:
	@$(CC) $(CFLAGS) -c s21_matrix_oop.cc

test: s21_matrix_oop.a unit_tests.cc
	@$(CC) $(CFLAGS) -lgtest unit_tests.cc s21_matrix_oop.a -o unit_tests
	@./unit_tests

check: test
	@CK_FORK=no leaks --atExit -- ./unit_tests

clean:
	rm -rf *.o *.out s21_matrix_oop.a unit_tests
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info

rebuild: clean all

gcov_report: clean
	gcc  --coverage unit_tests.cc s21_matrix_oop.cc -o gcov_report -lgtest -lstdc++
	./gcov_report
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html


