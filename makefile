proj:main.o create_input.o run_OJ.o judge_equal.o run_OJ.h create_input.h judge_equal.h
	g++ main.o create_input.o judge_equal.o run_OJ.o run_OJ.h create_input.h judge_equal.h -o proj
main.o:main.cpp
	g++ -c main.cpp -o main.o
create_input.o:create_input.cpp
	g++ -c create_input.cpp -o create_input.o
run_OJ.o:run_OJ.cpp
	g++ -c run_OJ.cpp -o run_OJ.o
judge_equal.o:judge_equal.cpp
	g++ -c judge_equal.cpp -o judge_equal.o
clean:
	rm *.o
	rm proj
