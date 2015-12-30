all:
	g++ -pg -std=c++14 -o main main.cpp
	./main
	gprof main gmon.out > report.txt

optimize0:
	g++ -pg -std=c++14 -o main main.cpp -O0 -pg
	./main
	gprof main gmon.out > report0.txt

optimize3:
	g++ -pg -std=c++14 -o main main.cpp -O3 -pg
	./main
	gprof main gmon.out > report3.txt