
all:main

main: main.o forward_euler.o backward_euler.o modif_euler.o r_k_4.o opeMatriz.o opeEstado.o pred_corr.o matriz.o
	g++ main.o  forward_euler.o backward_euler.o r_k_4.o modif_euler.o opeMatriz.o opeEstado.o pred_corr.o matriz.o -o main


main.o: main.cpp headers/Funcao.hpp headers/Funcao_carros.hpp headers/Funcao_01.hpp headers/Funcao_02.hpp headers/Funcao_03.hpp headers/Funcao_04.hpp headers/forward_euler.hpp headers/backward_euler.hpp headers/modif_euler.hpp headers/r_k_4.hpp headers/pred_corr.hpp
	g++ -c main.cpp 




forward_euler.o: src/forward_euler.cpp headers/forward_euler.hpp headers/Funcao_S.hpp headers/estado.hpp headers/opeEstado.hpp headers/opeMatriz.hpp headers/matriz.hpp
	g++ -c src/forward_euler.cpp

backward_euler.o: src/backward_euler.cpp headers/backward_euler.hpp headers/Funcao_S.hpp headers/estado.hpp headers/matriz.hpp headers/opeEstado.hpp headers/opeMatriz.hpp
	g++ -c src/backward_euler.cpp

modif_euler.o: src/modif_euler.cpp headers/modif_euler.hpp headers/Funcao_S.hpp headers/estado.hpp headers/opeEstado.hpp headers/opeMatriz.hpp headers/matriz.hpp
	g++ -c src/modif_euler.cpp

r_k_4.o: src/r_k_4.cpp headers/r_k_4.hpp headers/Funcao_S.hpp headers/estado.hpp headers/opeEstado.hpp headers/opeMatriz.hpp headers/matriz.hpp headers/forward_euler.hpp
	g++ -c src/r_k_4.cpp

pred_corr.o: src/pred_corr.cpp headers/pred_corr.hpp headers/r_k_4.hpp headers/Funcao_S.hpp headers/estado.hpp headers/opeEstado.hpp headers/opeMatriz.hpp headers/matriz.hpp headers/r_k_4.hpp
	g++ -c src/pred_corr.cpp

opeMatriz.o: src/opeMatriz.cpp headers/opeMatriz.hpp headers/matriz.hpp
	g++ -c src/opeMatriz.cpp 

opeEstado.o: src/opeEstado.cpp headers/opeEstado.hpp headers/estado.hpp headers/matriz.hpp
	g++ -c src/opeEstado.cpp

matriz.o: src/matriz.cpp headers/matriz.hpp
	g++ -c src/matriz.cpp 




clean:
	 rm -rf *.o *~ main

