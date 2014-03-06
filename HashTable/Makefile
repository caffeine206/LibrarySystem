all:
	g++ -Wall -I../Catch/include test.cpp -o assoc.out && valgrind --tool=callgrind --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes ./assoc.out