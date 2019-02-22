output: nature.o Map.o Grass.o Rabbit.o
	clang++ nature.o Map.o Grass.o Rabbit.o -o nature

nature.o: nature.C
	clang++ -c nature.C

Rabbit.o: Rabbit.C Rabbit.H
	clang++ -c Rabbit.C

Grass.o: Grass.C Grass.H
	clang++ -c Grass.C

Map.o: Map.C Map.H
	clang++ -c Map.C

clean:
	rm *.o nature
#target: dependencies
#    action