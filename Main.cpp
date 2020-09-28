#include <iostream>
#include <ctime>
#include <boost/foreach.hpp>
#include "SimulatorConfiguration.h"
#include "Simulator.h"
#include "JSONFileCreator.h"

using namespace std;

int drive2() {
	SimulatorConfiguration config;
	config.breakEvenDecimal = 0.25;
	cout << "According to the config, the break-even rate is: " << config.breakEvenDecimal << endl;
	return 0;
}

void drive3(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}

	SimulatorConfiguration config;
	config.principal = atof(argv[1]);
	config.riskDecimal = atof(argv[2]);
	config.rewardDecimal = atof(argv[3]);
	config.winDecimal = atof(argv[4]);
	config.lossDecimal = atof(argv[5]);
	config.breakEvenDecimal = atof(argv[6]);
	config.numOfTrades = atof(argv[7]);
	config.numOfSimulations = atof(argv[8]);
	
	Simulator s(config);
	s.runSimulations();
}

// Driver code...unfortunately
void drive4() {
	map<string, double> sampleSimulationOutput;
	sampleSimulationOutput.insert(pair<string, double>("minPortfolioAmount", 40000));
	sampleSimulationOutput.insert(pair<string, double>("maxPortfolioAmount", 90000));

	cout << sampleSimulationOutput["minPortfolioAmount"] << endl;
	cout << sampleSimulationOutput["maxPortfolioAmount"] << endl;

	JSONFileCreator jfc(sampleSimulationOutput);
	jfc.createJSONFile("target.json");
}

int main(int argc, char *argv[]) {
	srand(time(0));
	drive3(argc, argv);
}
