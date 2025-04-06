 Tum:derle bagla calistir 
 
 derle:
	g++ -g -c -I "./include" ./src/Main.cpp -o ./lib/Main.o
	g++ -g -c -I "./include" ./src/GenDugumu.cpp -o ./lib/GenDugumu.o
	g++ -g -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o
	g++ -g -c -I "./include" ./src/Islemler.cpp -o ./lib/Islemler.o
	g++	-g -c -I "./include" ./src/Populasyon.cpp -o ./lib/Populasyon.o
	g++ -g -c -I "./include" ./src/DNAoku.cpp -o ./lib/DNAoku.o
	g++ -g -c -I "./include" ./src/AnaMenu.cpp -o ./lib/AnaMenu.o

bagla:
	g++ -g ./lib/GenDugumu.o ./lib/Kromozom.o ./lib/Islemler.o ./lib/Populasyon.o ./lib/DNAoku.o ./lib/AnaMenu.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program