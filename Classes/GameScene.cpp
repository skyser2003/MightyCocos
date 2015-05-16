#include "stdafx.h"
#include "GameScene.h"

#include "Game.h"
#include "AbstractPlayer.h"
#include "CardUtilFunc.h"
#include "Card.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	// Init game
	game.reset(new Mighty::Game());
	game->Init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	for (const auto& pair : game->GetPlayers())
	{
		auto player = pair.second;

		auto cardImageDir = "card_images/" + Mighty::Util::GetCardResourceName(player->GetCardList()[0]->GetType()) + ".png";

		auto cardImage = MenuItemImage::create(
			cardImageDir,
			"CloseSelected.png",
			CC_CALLBACK_1(GameScene::menuCloseCallback, this));

		cardImage->setPosition(Vec2((player->GetID() + 0.5f) * cardImage->getContentSize().width,
			origin.y + cardImage->getContentSize().height / 2));

		// create menu, it's an autorelease object
		auto menu = Menu::create(cardImage, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 1);
	}

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Mighty", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
