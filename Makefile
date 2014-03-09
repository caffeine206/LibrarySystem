all:
	# g++ -g -Wall -I${CURDIR}/Catch/include/ ${CURDIR}/HashTable/test.cpp -o ${CURDIR}/HashTable/assoc.out && valgrind --tool=callgrind --tool=memcheck --leak-check=full --show-reachable=yes --num-callers=20 --track-fds=yes ${CURDIR}/HashTable/assoc.out
	g++ -g -Wall -I${CURDIR}/Catch/include/ ${CURDIR}/HashTable/test.cpp -o ${CURDIR}/HashTable/assoc.out && ${CURDIR}/HashTable/assoc.out
