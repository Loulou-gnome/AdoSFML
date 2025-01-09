#include "Game.hpp"

Game::Game(sf::String title) : m_window(sf::VideoMode({400, 400}), title)
{
}

Game::~Game()
{
}

void Game::OnClosed()
{
	m_window.close();
}

void Game::OnKeyPress(const sf::Event::KeyPressed& keyPressed)
{
	if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
	{
		m_window.close();
	}
}

void Game::Run(Game& game)
{
	while (game.m_window.isOpen())
	{
		while (const std::optional event = game.m_window.pollEvent())
		{
			// Close window: exit
			if (event->is<sf::Event::Closed>())
				game.OnClosed();
			else if (const auto key = event->getIf<sf::Event::KeyPressed>())
				game.OnKeyPress(*key);
		}
		game.m_window.clear();
		game.m_window.display();
	}
}
