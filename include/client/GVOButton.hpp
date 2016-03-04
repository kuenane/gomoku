#pragma once

#ifndef GVOBUTTON_HPP__
#define GVOBUTTON_HPP__

#include	<SFML/Graphics.hpp>
#include	<list>
#include	"IGVObject.hpp"
#include	"IGVAMouseClick.hpp"
#include	"IGVAMouseHover.hpp"

class GVOButton : public IGVObject
{
public:
	GVOButton(sf::Vector2f pos, sf::Texture const &texture, sf::Vector2f const &scale);
	virtual ~GVOButton();
	virtual sf::Drawable*	getDrawable(void);

public:
	void	addAction(IGVAMouseClick *mouseAction);
	void	addAction(IGVAMouseHover *mouseAction);
	void	mouseClick(sf::Vector2f const &pos);
	void	mouseMove(sf::Vector2f const &pos);

private:
	sf::Sprite					mSprite;
	sf::Vector2f				mPos;
	std::list<IGVAMouseClick *>	mClickActions;
	std::list<IGVAMouseHover *>	mHoverActions;
};

#endif // !GVOBUTTON_HPP__
