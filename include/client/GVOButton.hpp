#pragma once

#ifndef GVOBUTTON_HPP__
#define GVOBUTTON_HPP__

#include	<SFML/Graphics.hpp>
#include	<list>
#include	<functional>
#include	"IGVObject.hpp"
#include	"IGVAMouseClick.hpp"
#include	"IGVAMouseHover.hpp"
#include	"IGVAKeyPressed.hpp"
#include	"GVOText.hpp"

class GVOButton : public IGVObject
{
public:
	GVOButton(sf::Vector2f pos, sf::Texture const &texture, sf::Vector2f const &scale, std::function<bool()> enable = []() { return true; }, std::function<bool()> visibility = []() { return true; });
	virtual ~GVOButton();
	virtual sf::Drawable*	getDrawable(void);
	sf::Sprite				&getSprite(void);

public:
	void	addAction(IGVAMouseClick *action);
	void	addAction(IGVAMouseHover *action);
	void	addAction(IGVAKeyPressed *action);
	virtual void	mouseClick(sf::Vector2f const &pos);
	virtual void	mouseMove(sf::Vector2f const &pos);
	virtual void	keyPressed(sf::Vector2f const &pos, sf::Uint32 const &key);

public:
	GVOText						*mText;

private:
	std::function<bool()>		mEnable;
	std::function<bool()>		mVisibility;
	sf::Sprite					mSprite;
	sf::Vector2f				mPos;
	std::list<IGVAMouseClick *>	mClickActions;
	std::list<IGVAMouseHover *>	mHoverActions;
	std::list<IGVAKeyPressed *>	mKeyActions;
};

#endif // !GVOBUTTON_HPP__
