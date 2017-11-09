all:main

main: main.o NC_F_P1.o NC_A_P0.o NC_A_P1.o NC_A_P2.o NC_F_P2.o NC_A_P3.o NC_F_P3.o NC_A_P4.o NC_F_P4.o gCHEBSHEV.o IntegralDupla.o IntegralDupla_q5.o gLEGENDRE_02.o gLEGENDRE_03.o gLEGENDRE_04.o gLAGUERRE_02.o gLAGUERRE_03.o gLAGUERRE_04.o gHERMITE_02.o gHERMITE_03.o gHERMITE_04.o quad_exp_simples.o quad_exp_dupla.o
	g++ main.o NC_F_P1.o NC_A_P0.o NC_A_P1.o NC_A_P3.o NC_A_P4.o NC_A_P2.o NC_F_P2.o NC_F_P3.o NC_F_P4.o gCHEBSHEV.o IntegralDupla.o IntegralDupla_q5.o gLEGENDRE_02.o gLEGENDRE_03.o gLEGENDRE_04.o gLAGUERRE_02.o gLAGUERRE_03.o gLAGUERRE_04.o gHERMITE_02.o gHERMITE_03.o gHERMITE_04.o quad_exp_simples.o quad_exp_dupla.o -o main


main.o: main.cpp headers/Funcao.hpp headers/Funcao_01.hpp headers/Funcao_02.hpp headers/Funcao_03.hpp headers/Funcao_04.hpp headers/NC_F_P1.hpp headers/NC_F_P3.hpp headers/NC_F_P4.hpp headers/NC_A_P0.hpp headers/NC_A_P1.hpp headers/NC_A_P2.hpp headers/NC_A_P3.hpp headers/NC_A_P4.hpp headers/NC_F_P2.hpp headers/gCHEBSHEV.hpp headers/gLEGENDRE_02.hpp headers/gLEGENDRE_03.hpp headers/gLEGENDRE_04.hpp headers/gLAGUERRE_02.hpp headers/gLAGUERRE_03.hpp headers/gLAGUERRE_04.hpp headers/gHERMITE_02.hpp headers/gHERMITE_03.hpp headers/gHERMITE_04.hpp headers/Integracao.hpp headers/quad_exp_simples.hpp headers/Funcao_sqrt.hpp headers/xSobreTan.hpp headers/X_q5.hpp headers/Y_q5.hpp headers/constant.hpp headers/Funcao_semiesfera.hpp headers/IntegralDupla_q5.hpp headers/Funcao_R2.hpp
	g++ -c main.cpp



NC_A_P0.o: src/NC_A_P0.cpp headers/NC_A_P0.hpp headers/Integracao.hpp
	g++ -c src/NC_A_P0.cpp

NC_A_P1.o: src/NC_A_P1.cpp headers//NC_A_P1.hpp headers//Integracao.hpp
	g++ -c src/NC_A_P1.cpp

NC_A_P2.o: src/NC_A_P2.cpp headers/NC_A_P2.hpp headers/Integracao.hpp
	g++ -c src/NC_A_P2.cpp

NC_A_P3.o: src/NC_A_P3.cpp headers/NC_A_P3.hpp headers/Integracao.hpp
	g++ -c src/NC_A_P3.cpp

NC_A_P4.o: src/NC_A_P4.cpp headers/NC_A_P4.hpp headers/Integracao.hpp
	g++ -c src/NC_A_P4.cpp




NC_F_P1.o: src/NC_F_P1.cpp headers/NC_F_P1.hpp headers/Integracao.hpp
	g++ -c src/NC_F_P1.cpp

NC_F_P2.o: src/NC_F_P2.cpp headers/NC_F_P2.hpp headers/Integracao.hpp
	g++ -c src/NC_F_P2.cpp


NC_F_P3.o: src/NC_F_P3.cpp headers/NC_F_P3.hpp headers/Integracao.hpp
	g++ -c src/NC_F_P3.cpp


NC_F_P4.o: src/NC_F_P4.cpp headers/NC_F_P4.hpp headers/Integracao.hpp
	g++ -c src/NC_F_P4.cpp




gLEGENDRE_02.o:  src/gLEGENDRE_02.cpp headers/gLEGENDRE_02.hpp headers/Integracao.hpp
	g++ -c src/gLEGENDRE_02.cpp

gLEGENDRE_03.o:  src/gLEGENDRE_03.cpp headers/gLEGENDRE_03.hpp headers/Integracao.hpp
	g++ -c src/gLEGENDRE_03.cpp

gLEGENDRE_04.o:  src/gLEGENDRE_04.cpp headers/gLEGENDRE_04.hpp headers/Integracao.hpp
	g++ -c src/gLEGENDRE_04.cpp



gLAGUERRE_02.o: src/gLAGUERRE_02.cpp headers/gLAGUERRE_02.hpp headers/Integracao.hpp
	g++ -c src/gLAGUERRE_02.cpp

gLAGUERRE_03.o: src/gLAGUERRE_03.cpp headers/gLAGUERRE_03.hpp headers/Integracao.hpp
	g++ -c src/gLAGUERRE_03.cpp

gLAGUERRE_04.o: src/gLAGUERRE_04.cpp headers/gLAGUERRE_04.hpp headers/Integracao.hpp
	g++ -c src/gLAGUERRE_04.cpp



gHERMITE_02.o:  src/gHERMITE_02.cpp headers/gHERMITE_02.hpp headers/Integracao.hpp
	g++ -c src/gHERMITE_02.cpp

gHERMITE_03.o:  src/gHERMITE_03.cpp headers/gHERMITE_03.hpp headers/Integracao.hpp
	g++ -c src/gHERMITE_03.cpp

gHERMITE_04.o:  src/gHERMITE_04.cpp headers/gHERMITE_04.hpp headers/Integracao.hpp
	g++ -c src/gHERMITE_04.cpp


gCHEBSHEV.o: src/gCHEBSHEV.cpp headers/gCHEBSHEV.hpp headers/Integracao.hpp
	g++ -c src/gCHEBSHEV.cpp

quad_exp_simples.o: src/quad_exp_simples.cpp headers/quad_exp_simples.hpp headers/Funcao_exp_simples.hpp headers/NC_A_P2.hpp headers/Integracao.hpp
	g++ -c src/quad_exp_simples.cpp

quad_exp_dupla.o: src/quad_exp_dupla.cpp headers/quad_exp_dupla.hpp headers/Funcao_exp_dupla.hpp headers/NC_A_P3.hpp headers/Integracao.hpp
	g++ -c src/quad_exp_dupla.cpp



IntegralDupla.o: src/IntegralDupla.cpp headers/IntegralDupla.hpp headers/Integracao.hpp headers/X_R2.hpp headers/Y_R2.hpp
	g++ -c src/IntegralDupla.cpp

IntegralDupla_q5.o: src/IntegralDupla_q5.cpp headers/IntegralDupla_q5.hpp headers/Integracao.hpp headers/N2.hpp headers/N3.hpp headers/N4.hpp
	g++ -c src/IntegralDupla_q5.cpp

clean:
	 rm *.o *~ main

