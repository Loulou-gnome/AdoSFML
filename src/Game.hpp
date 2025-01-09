#include <SFML/Graphics.hpp>

class Game {
public:
	Game(sf::String);
	~Game();

	void OnClosed();
	void OnKeyPress(const sf::Event::KeyPressed& keyPressed);
	static void Run(Game& game);
private:
	sf::RenderWindow m_window;
};