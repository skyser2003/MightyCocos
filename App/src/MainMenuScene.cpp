#include "stdafx.h"
#include "MainMenuScene.h"

#include "GameScene.h"
#include "OptionScene.h"

#include "Helper.h"

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
	auto label = Label::createWithTTF("TEST", "fonts/Marker Felt.ttf", 24);

	// Game start button
	CreateLabel(this, Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - label->getContentSize().height),
		"START GAME", "fonts/Marker Felt.ttf", 24, CC_CALLBACK_1(MainMenuScene::StartGameCallback, this));

	// Option button
	CreateLabel(this, Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2 - label->getContentSize().height * 2),
		"OPTION", "fonts/Marker Felt.ttf", 24, CC_CALLBACK_1(MainMenuScene::OptionCallback, this));

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