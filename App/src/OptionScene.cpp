#include "stdafx.h"
#include "OptionScene.h"

#include "Helper.h"

USING_NS_CC;

Scene* OptionScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = OptionScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool OptionScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto label = Label::createWithTTF("TEST", "fonts/Marker Felt.ttf", 24);

	CreateLabel(this, Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - label->getContentSize().height),
		"MIGHTY", "fonts/Marker Felt.ttf", 24, [this](Menu* menu)
	{
		ShowCardList(this, [this](Menu* menu, Mighty::CardType type)
		{
			// Set mighty card type in config
			removeChild(menu);
		});
	});

	// TODO : create option menu for other functional cards, e.g. joker, joker call

	return true;
}