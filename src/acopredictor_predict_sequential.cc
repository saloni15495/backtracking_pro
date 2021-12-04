#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

#include "acopredictor.h"

/** \file acopredictor_predict_sequential.cc */

using std::cout;
using std::cerr;
using std::vector;
using std::string;
using std::unique_ptr;

struct ACOPredictor::Results ACOPredictor::predict(){
	for(int i = 0; i < dCycles; i++){
		vector<ACOSolution> antsSolutions; // Solutions generated by all ants
		unique_ptr<int[]> nContacts(new int[dNAnts]); // Their contacts

		perform_cycle(antsSolutions, nContacts.get());

		/*
		if(i%2 == 0){
			for(int j = 0; j < 5; j++){
				for(int i = 0; i < dNMovElems; i++)
					cout << pheromone(i, j) << " ";
				cout << "\n";
			}
			cout << "\n";
		}
		*/
	}

	Results res = {
		.solution = dBestSol,
		.contacts = dBestContacts
	};

	return res;
}