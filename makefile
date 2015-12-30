all:
		g++ -pg -std=c++14 -o main main.cpp

gprof:
		gprof main gmon.out > report.txt