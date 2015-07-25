#pragma once

namespace Mighty
{
	#include "enum_class_CardType.h"

	class Game;
	class Card;
}

class GameScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void cardClickCallback(std::shared_ptr<Mighty::Card> card, cocos2d::Menu* menu);

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
private:
	float scale;
	std::shared_ptr<Mighty::Game> game;
	std::map<Mighty::CardType, cocos2d::Menu*> cardImageList;
};