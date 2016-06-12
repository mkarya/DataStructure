MYINCLUDES=/home/ec2-user/programming/data-structure/tree/src

tree : main.o Tree.o 
	g++ -I./ -o tree Tree.o main.o 

main.o : main.cpp tree.h
	g++ -I./ -g -c main.cpp

Tree.o : Tree.cpp tree.h
	g++ -I./ -g -c Tree.cpp

tree_debug : maind.o treed.o 
	gcc -o tree main.o tree.o

maind.o : main.cpp tree.h
	gcc -c -g main.cpp

treed.o : tree.cpp tree.h
	gcc -c -g tree.cpp

clean : 
	rm -rf *.o
	rm tree
