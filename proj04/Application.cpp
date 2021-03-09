/*
 * Application.cpp defines the user interface
 * Student: Sebene Yi(ssy3) and Samuel Zeleke (sgz4)
 * Date: 4 Mar, 2019
 * Proj04: Matrix operations
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Application.h"

typedef double Item;

void Application::launch(){

while (true){
	cout << "Welcome to matrix calculator!\n" <<
			"\nThe program will make the desired calculation on matrix stored in files. \n"<<
			"Please input the character representing the operation with no additional whitespace (enter 'E' to exit):" <<
			"\n\t + \t - \t T \n>>>" << flush;

	//File directory containers
	string fileName1;
	string operation;
	string fileName2;

	cin >> operation;

		if (operation == "E") {break;}

		//If Transpose
		else if (operation == "T"){

			cout << "Transpose:\nPlease enter the directory of the file containing the matrix to be transposed (enter 'E' to exit): " <<flush;
			cin >> fileName1;
			if (fileName1 == "E"){break;}

			//Read matrix
			Matrix<Item> matrix1;
			matrix1.readFrom(fileName1);

			//Transpose
			matrix1 = matrix1.getTranspose();

			cout << "The transpose of the matrix is: " << endl;
			matrix1.writeTo(cout);
		}

		//If addition
		else if (operation == "+"){

			//Retrieve file location
			cout << "ADD:\n Please enter the directory of the file containing the first matrix (enter 'E' to exit): " <<flush;
			cin >> fileName1;
			if (fileName1 == "E"){break;}

			cout << "\n Please enter the directory of the file containing the second matrix: " <<flush;
			cin >> fileName2;

			//Read matrix
			Matrix<Item> matrix1;
			Matrix<Item> matrix2;
			matrix1.readFrom(fileName1);
			matrix2.readFrom(fileName2);

			//Display the sum of the matrices
			Matrix<Item> sum_matrix;
			sum_matrix = matrix1 + matrix2;
			cout << "The sum of the Matrices is: " << endl;
			sum_matrix.writeTo(cout);
		}

		//If subtruction
		else if (operation == "-"){

			//Retrieve file location
			cout << "SUBTRACTION:\n Please enter the directory of the file containing the first matrix (enter 'E' to exit): " <<flush;
			cin >> fileName1;
			if (fileName1 == "E"){break;}

			cout << "\n Please enter the directory of the file containing the second matrix: " <<flush;
			cin >> fileName2;

			//Read matrix
			Matrix<Item> matrix1;
			Matrix<Item> matrix2;
			matrix1.readFrom(fileName1);
			matrix2.readFrom(fileName2);

			//Display the sum of the matrices
			Matrix<Item> diff_matrix;
			diff_matrix = matrix1 - matrix2;
			cout << "The difference of the Matrices is: " << endl;
			diff_matrix.writeTo(cout);
		}
	}

	cout << "Goodbye!" << endl;
}

