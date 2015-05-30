#include "stdafx.h"
#include "MainMenuScene.h"

#include "GameScene.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainMenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto label = Label::createWithTTF("START GAME", "fonts/Marker Felt.ttf", 24);
	auto labelMenu = MenuItemLabel::create(label);

	labelMenu->setCallback([this](Ref* ref)
	{
		auto gameScene = GameScene::createScene();
		Director::getInstance()->pushScene(gameScene);
	});

	auto menu = Menu::create();
	menu->addChild(labelMenu);

	menu->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - label->getContentSize().height));

	addChild(menu);

	return true;
}