#include <iostream>
#include "gaussian.h"
#include "engine.h"
#include "car.h"

using namespace std;

int main ()
{

	Gaussian mygaussian(30.0,20.0);
	Gaussian othergaussian(10.0,30.0);
	
	std::cout << "average " << mygaussian.getMu() << std::endl;
	std::cout << "evaluation " << mygaussian.evaluate(15.0) << std::endl;

	std::cout << "mul results sigma " << mygaussian.mul(othergaussian).getSigma2() << std::endl;
	std::cout << "mul results average " << mygaussian.mul(othergaussian).getMu() << std::endl;

	std::cout << "add results sigma " << mygaussian.add(othergaussian).getSigma2() << std::endl;
	std::cout << "add results average " << mygaussian.add(othergaussian).getMu() << std::endl;

	Engine enginelarge("4L");
	Engine enginesmall("2.5L");

	Car carone("red", 5);
	Car cartwo("green", 4);


	cout << "Small engine size "  << enginesmall.getSize() << endl;
	cout << "Large engine size " << enginelarge.getSize() << endl;
	cout << "Car one doors " << carone.getDoors() << endl;
	cout << "Car two doors " << cartwo.getDoors() << endl;

	cout << "Car one engine size " << carone.getEngine() << endl;
	carone.setEngine(enginelarge.getSize());
	cout << "Car one engine size new " << carone.getEngine() << endl;

	return 0;
}