//@Author Sean Nash De Andrade
//@Login C00217019
// Matrix Vector Port
#ifndef GAME
#define GAME
#include "Matrix3.h"
#include <SFML\Graphics.hpp>



class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();


	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

};

#endif // !GAME

