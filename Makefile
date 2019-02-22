output: zootopia.o Map.o Grass.o Rabbit.o
	clang++ zootopia.o Map.o Grass.o Rabbit.o -o zootopia

nature.o: zootopia.C
	clang++ -c zootopia.C

Rabbit.o: Rabbit.C Rabbit.H
	clang++ -c -std=c++2a Rabbit.C

Grass.o: Grass.C Grass.H
	clang++ -c Grass.C

Map.o: Map.C Map.H
	clang++ -c Map.C

clean:
	rm *.o nature
#target: dependencies
#    action