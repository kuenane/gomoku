#pragma once

#ifndef MOUSEHOVERCHANGECOLOR_HPP_
#define MOUSEHOVERCHANGECOLOR_HPP_

#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	"IGVAMouseHover.hpp"

class GVAMouseHoverChangeColor : public IGVAMouseHover
{
public:
	GVAMouseHoverChangeColor(sf::Color const &color, sf::Color const &baseColor) : mColor(color), mBaseColor(baseColor) {}
	virtual ~GVAMouseHoverChangeColor(void) {}
	virtual void Act(sf::Sprite &texture, sf::Vector2f const &mousePosition)
	{
		if (mousePosition.x >= texture.getGlobalBounds().left && mousePosition.x <= texture.getGlobalBounds().left + texture.getGlobalBounds().width &&
			mousePosition.y >= texture.getGlobalBounds().top && mousePosition.y <= texture.getGlobalBounds().top + texture.getGlobalBounds().height)
			texture.setColor(mColor);
		else
			texture.setColor(mBaseColor);
	}

private:
	sf::Color	mColor;
	sf::Color	mBaseColor;
};

#endif // !MOUSEHOVERCHANGECOLOR_HPP_
