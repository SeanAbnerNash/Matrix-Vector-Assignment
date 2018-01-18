//@Author Sean Nash De Andrade
//@Login C00217019
// Matrix Vector Port

#include "Game.h"
#include <iostream>

void vector3Tests();
void vectorCreation();
void vectorAddition();
void vectorSubtraction();
void vectorMultiplication();
void vectorInvert();
void vectorLength();
void vectorNormalize();

void matrix3Tests();
void matrixCreation();
void matrixMultiplication();
void matrixTranspose();
void matrixAddSub();
void matrixRowCol();
void matrixDeterimantInverse();
void matrixRotation();
void matrixScaleTranslate();


Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Matrix Test" },

	m_exitGame{false} //when true game will exit
{
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	vector3Tests();
	matrix3Tests();
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		//for (int i = 0; i < 3; i++)
		//{
		//	Matrix3 scalingMatrix = scalingMatrix.Scale(1.5, 1.5);
		//	//m_trianglePos[i] = m_trianglePos[i] * scalingMatrix;
		//	m_triangleArray.append(m_triangleVertice[i]);
		//}	
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
//	m_window.draw(m_triangleArray);
	m_window.display();
}



void vector3Tests()
{
	vectorCreation();
	vectorAddition();
	vectorSubtraction();
	vectorMultiplication();
	vectorInvert();
	vectorNormalize();
	system("PAUSE");
}

void vectorCreation()
{
	Vector3 vectorA;
	std::cout << "-------- default constructor --------------" << std::endl;
	std::cout << vectorA.toString() << std::endl; //Converting vector to string
	std::cout << "[ 0, 0, 0 ]" << std::endl; //What the Answer should be
	std::cout << "========================================" << std::endl;
	system("Pause");
}

void vectorAddition()
{
	std::cout << "-------- Addition --------------" << std::endl;
	Vector3 vectorA(2.2, 3.3, 4.4);
	Vector3 vectorB(1.1, 1.1, 1.1);
	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	std::cout << "Vector B is " << vectorB.toString() << std::endl;
	vectorA = vectorA + vectorB; //Calculation
	std::cout << "Answer is " << vectorA.toString() << std::endl;
	std::system("pause");
}

void vectorSubtraction()
{
	std::cout << "-------- Subtraction --------------" << std::endl;
	Vector3 vectorA(2.2, 3.3, 4.4);
	Vector3 vectorB(1.1, 1.1, 1.1);
	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	std::cout << "Vector B is " << vectorB.toString() << std::endl;
	vectorA = vectorA - vectorB;
	std::cout << "Answer is " << vectorA.toString() << std::endl;
	std::system("pause");
}

void vectorMultiplication()
{
	// Vector created for test
	std::cout << "-------- Multiplication --------------" << std::endl;
	Vector3 vectorA(2.0, 5.0, 2.5);
	double scalarValueD = 2.0; //Value that multiplies the vector
	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	vectorA = vectorA * scalarValueD;
	std::cout << "Vector A times " << scalarValueD << " (Double) Scalar is " << vectorA.toString() << std::endl; //Output result and scalar

	Vector3 vectorB(2.0, 5.0, 2.5);
	int scalarValueI = 2; //Value that multiplies the vector
	std::cout << "Vector B is " << vectorB.toString() << std::endl;
	vectorB = vectorB * scalarValueI;
	std::cout << "Vector B times " << scalarValueI << " (int) Scalar is " << vectorA.toString() << std::endl; //Output result and scalar
	std::system("pause");

	Vector3 vectorC(2.0, 5.0, 2.5);
	float scalarValueF = 2.0; //Value that multiplies the vector
	std::cout << "Vector C is " << vectorC.toString() << std::endl;
	vectorB = vectorB * scalarValueF;
	std::cout << "Vector C times " << scalarValueF << " (float) Scalar is " << vectorA.toString() << std::endl; //Output result and scalar
	std::system("pause");

	Vector3 vectorD(2.0, 5.0, 2.5);
	Vector3 vectorE(2.0, 2.0, 2.0);
	double vectorResult = 0;
	std::cout << "Vector D is " << vectorC.toString() << std::endl;
	std::cout << "Vector E is " << vectorC.toString() << std::endl;
	vectorResult = vectorD * vectorE;
	std::cout << "The Double product of Vector D times Vector E equals " << vectorResult << std::endl;
	std::system("pause");

	Vector3 vectorF(3.0, 5.0, 2.5);
	Vector3 vectorG(2.0, 3.0, 3.0);
	std::cout << "Vector F is " << vectorC.toString() << std::endl;
	std::cout << "Vector G is " << vectorC.toString() << std::endl;
	vectorD = vectorD ^ vectorE;
	std::cout << "The Vector product of Vector D times Vector E equals " << vectorD.toString() << std::endl;
	std::system("pause");
}

void vectorInvert()
{
	std::cout << "-------- Inversion --------------" << std::endl;
	Vector3 vectorA(1.1, 1.1, 1.1);
	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	vectorA = -vectorA; //Calculation
	std::cout << "Answer is " << vectorA.toString() << std::endl;
	std::system("pause");

}

void vectorLength()
{
	std::cout << "-------- Length --------------" << std::endl;
	Vector3 vectorA(1.1, 1.1, 1.1);
	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	double length = vectorA.length(); //Calculation
	std::cout << "The Length is " << length << std::endl;
	std::system("pause");

	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	double lengthSquared = vectorA.lengthSquared(); //Calculation
	std::cout << "The Length Squared is " << lengthSquared << std::endl;
	std::system("pause");
}

void vectorNormalize()
{
	std::cout << "-------- Normalize --------------" << std::endl;
	Vector3 vectorA(1.1, 1.1, 1.1);
	std::cout << "Vector A is " << vectorA.toString() << std::endl;
	vectorA.normalise();
	double length = vectorA.length(); //Calculation
	std::cout << "The Length is " << length << std::endl;
	std::system("pause");
}

void matrix3Tests()
{
	matrixCreation();
	matrixMultiplication();
	matrixTranspose();
	matrixAddSub();
	matrixRowCol();
	 matrixDeterimantInverse();
	 matrixRotation();
	 matrixScaleTranslate();
}

void matrixCreation()
{
	Matrix3 matrixA;
	std::cout << " Default Matrix A is " << matrixA.toString() << std::endl;
	
	Matrix3 matrixB(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	std::cout << " Vector Matrix B is " << matrixB.toString() << std::endl;
	std::system("pause");
}

void matrixMultiplication()
{
	std::cout << " ---- Multiplication ----" << std::endl;
	Matrix3 matrixA(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	Vector3 vectorA(2, 2, 2);
	Vector3 vectorB = matrixA * vectorA;
	std::cout << " Vector Product of Matrix A " << matrixA.toString() << " and Vector A" << vectorA.toString() << " is "  << vectorB.toString() << std::endl;

	Matrix3 matrixB (Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	double scalarNum = 2;
	Matrix3 matrixC = matrixB * scalarNum;
	std::cout << " Matrix Product of Matrix B " << matrixB.toString() << " and Scalar " << scalarNum << " is " << matrixC.toString() << std::endl;

	Matrix3 matrixD(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	Matrix3 matrixE(Vector3(2, 2, 2), Vector3(2, 2, 2), Vector3(2, 2, 2));
	Matrix3 matrixF = matrixD * matrixE;
	std::cout << " Matrix Product of Matrix D " << matrixD.toString() << " and Matrix E " << matrixE.toString() << " is " << matrixF.toString() << std::endl;
	std::system("pause");


}

void matrixTranspose()
{
	std::cout << " ---- Transposition ----" << std::endl;
	Matrix3 matrixA(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	std::cout << " Matrix A before transposition is " << matrixA.toString() << std::endl;
	matrixA = matrixA.transpose();
	std::cout << " Matrix A after transposition is " << matrixA.toString() << std::endl;
	std::system("pause");
}

void matrixAddSub()
{
	std::cout << " ---- Addition ----" << std::endl;
	Matrix3 matrixA(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	Matrix3 matrixB(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	std::cout << " Matrix A is " << matrixA.toString() << " and Matrix B is " << matrixB.toString() << std::endl;
	matrixA = matrixA + matrixB;
	std::cout << " The Sum of the Two is " << matrixA.toString() << std::endl;

	std::cout << " ---- Subtraction ----" << std::endl;
	Matrix3 matrixC(Vector3(5, 5, 5), Vector3(5, 5, 5), Vector3(5, 5, 5));
	Matrix3 matrixD(Vector3(1, 1, 1), Vector3(2, 2, 2), Vector3(3, 3, 3));
	std::cout << " Matrix C is " << matrixC.toString() << " and Matrix D is " << matrixD.toString() << std::endl;
	matrixC = matrixC - matrixD;
	std::cout << " The Subtraction of the Two is " << matrixC.toString() << std::endl;


	std::cout << " ---- Inversion ----" << std::endl;
	Matrix3 matrixE(Vector3(1, 5, 3), Vector3(5, 3, 1), Vector3(3, 1, 5));
	std::cout << " Matrix E is " << matrixE.toString() << std::endl;
	matrixE = -matrixE;
	std::cout << " When Inverted is " << matrixE.toString() << std::endl;
	std::system("pause");
}

void matrixRowCol()
{
	std::cout << " ---- Row/Col ----" << std::endl;
	Matrix3 matrixA(Vector3(5, 5, 5), Vector3(3, 3, 3), Vector3(1, 1, 1));
	Vector3 vectorA = matrixA.Row(1);
	Vector3 vectorB = matrixA.Column(2);
	std::cout << " Row 2 of Matrix A is " << vectorA.toString() << " and Col 3 of Matrix A is  " << vectorB.toString() << std::endl;
	std::cout << " The Matrix A is  " << matrixA.toString() << std::endl;
	std::system("pause");
}

void matrixDeterimantInverse()
{

	std::cout << " ---- Determinant ----" << std::endl;
	Matrix3 matrixA(Vector3(5, 5, 5), Vector3(3, 3, 3), Vector3(1, 1, 1));
	double matrixDeterminant = matrixA.determinant();
	std::cout << " Matrix A is " << matrixA.toString() << std::endl;
	std::cout << " The Determinant of Matrix A is  " << matrixDeterminant << std::endl;

	std::cout << " ---- Inverse ----" << std::endl;
	Matrix3 matrixB(Vector3(2, 1, 2), Vector3(1, 3, 1), Vector3(3, 1, 3));
	Matrix3 matrixInverse = matrixB.Inverse();
	std::cout << " Matrix B is " << matrixB.toString() << std::endl;
	std::cout << " The Inverse of Matrix B is  " << matrixInverse.toString() << std::endl;

	std::system("pause");

}

void matrixRotation()
{
	std::cout << " ---- Rotation Matrix ----" << std::endl;
	Matrix3 matrixA = matrixA.rotation(90);
	std::cout << " Rotation Matrix A of 90 degrees is " << matrixA.toString() << std::endl;

	std::cout << " ---- Rotate X ----" << std::endl;
	Matrix3 matrixB = matrixB.RotationX(90);
	std::cout << " Rotation Matrix B of X Axis 90 degrees is " << matrixB.toString() << std::endl;

	std::cout << " ---- Rotate Y ----" << std::endl;
	Matrix3 matrixC = matrixC.RotationY(90);
	std::cout << " Rotation Matrix C of Y Axis 90 degrees is " << matrixC.toString() << std::endl;

	std::cout << " ---- Rotate Z ----" << std::endl;
	Matrix3 matrixD = matrixD.RotationZ(90);
	std::cout << " Rotation Matrix D of Z Axis 90 degrees is " << matrixD.toString() << std::endl;

	std::system("pause");
}

void matrixScaleTranslate()
{
	std::cout << " ---- Scale ----" << std::endl;
	Matrix3 matrixA = matrixA.Scale(20.5f, 20.5f);
	Vector3 vectorA = { 1,1,1 };
	 vectorA = matrixA * vectorA;
	std::cout << " Vector A is scaled up" << vectorA.toString() << std::endl;

	std::cout << " ---- Translate ----" << std::endl;
	Matrix3 matrixB = matrixB.Scale(2.0f, 2.0f);
	Vector3 vectorB = { 1,1,1 };
	 vectorB = matrixB * vectorB;
	std::cout << " Vector B is Translated up" << vectorB.toString() << std::endl;

	std::system("pause");
}
