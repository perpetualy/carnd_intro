#include <iostream>
#include "gaussian.h"
#include "engine.h"
#include "car.h"
#include "matrix.h"

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

	    // assign a 7x5 matrix to the variable initial_grid
    // all values in the matrix are 0.4
	std::vector <std:: vector <float> > 
	    initial_grid (7, std::vector <float>(5, 0.4));

    Matrix matrixa(initial_grid);
    // TODO: Use the initial grid variable to instantiate a matrix object
    // The matrix object should be called matrixa
    
    matrixa.matrix_print();
    // TODO: Use the matrix_print() method to print out matrixa
    
    std::cout << matrixa.getRows() << std::endl;
    // TODO: Print out the number of rows in matrixa. You will need
    // to use the getRows() function and std::cout
    
    std::cout << matrixa.getCols() << std::endl;
    // TODO: Print out the number of columns in matrixa 
    
    // Now you will use another 7x5 matrix called matrixb to 
    // give the results of the matrix_addition function
    
    // 7x5 2-dimensional vector with values 0.2
	std::vector <std:: vector <float> > 
	    second_grid (7, std::vector <float>(5, 0.2));
    
    Matrix matrixb(second_grid);
    // TODO: Instantiate an object called matrixb. Use the second_grid
    // variable as the input to initialize matrixb
    
    Matrix matrixsum = matrixa.matrix_addition(matrixb);
    // TOOD: Add matrixa and matrixb. Store the results in a new matrix
    // variable called matrixsum
    
    matrixsum.matrix_print();
    // TODO: Print out the matrix contained in the matrixsum variable

	return 0;
}