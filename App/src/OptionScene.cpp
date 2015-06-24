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

	ShowCardList(this, [](Mighty::CardType type)
	{

	});

	return true;
}