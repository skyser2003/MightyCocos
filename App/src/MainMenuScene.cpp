#include "stdafx.h"
#include "MainMenuScene.h"

#include "GameScene.h"
#include "OptionScene.h"

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

	// Game start button
	auto label = Label::createWithTTF("START GAME", "fonts/Marker Felt.ttf", 24);
	auto labelMenu = MenuItemLabel::create(label);
	labelMenu->setCallback(CC_CALLBACK_1(MainMenuScene::StartGameCallback, this));

	auto menu = Menu::create();
	menu->addChild(labelMenu);

	menu->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - label->getContentSize().height));

	// Option button
	auto label2 = Label::createWithTTF("OPTION", "fonts/Marker Felt.ttf", 24);
	auto labelMenu2 = MenuItemLabel::create(label2);
	labelMenu2->setCallback(CC_CALLBACK_1(MainMenuScene::OptionCallback, this));

	auto menu2 = Menu::create();
	menu2->addChild(labelMenu2);

	menu2->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - label->getContentSize().height * 2));

	addChild(menu);
	addChild(menu2);

	return true;
}

void MainMenuScene::StartGameCallback(Ref* ref)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->pushScene(scene);
}

void MainMenuScene::OptionCallback(Ref* ref)
{
	auto scene = OptionScene::createScene();
	Director::getInstance()->pushScene(scene);
}