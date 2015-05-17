#include "stdafx.h"
#include "GameScene.h"

#include "Game.h"
#include "AbstractPlayer.h"
#include "CardUtilFunc.h"
#include "Card.h"
#include "CardRole.h"

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
		Vec2 standard = Director::getInstance()->getVisibleOrigin();
		Vec2 direction;

		auto player = pair.second;

		switch (player->GetID())
		{
		case 0:
		{
			direction = Vec2(1.0f, 1.0f);
		}
		break;

		case 1:
		{
			direction = Vec2(1.0f, 1.0f);
		}
		break;

		case 2:
		{
			direction = Vec2(-1.0f, 1.0f);
		}
		break;

		case 3:
		{
			direction = Vec2(-1.0f, -1.0f);
		}
		break;

		case 4:
		{
			direction = Vec2(1.0f, -1.0f);
		}
		break;
		}

		if (direction.x == -1.0f)
		{
			standard.x = visibleSize.width;
		}
		if (direction.y == -1.0f)
		{
			standard.y = visibleSize.height;
		}

		if (player->GetID() == 1)
		{
			standard.x += visibleSize.width / 3;
		}

		for (size_t i = 0; i < player->GetCardList().size(); ++i)
		{
			auto card = player->GetCardList()[i];
			auto cardImageDir = "card_images/" + Mighty::Util::GetCardResourceName(card->GetType()) + ".png";

			auto callback = [this, card](Ref* ref)
			{
				cardClickCallback(card);
			};

			auto cardImage = MenuItemImage::create(
				cardImageDir,
				"CloseSelected.png",
				callback);

			float scale = 0.7f;

			cardImage->setPosition(Vec2(standard.x + direction.x * (i + 0.5f) * scale * cardImage->getContentSize().width,
				standard.y + direction.y * cardImage->getContentSize().height / 2 * scale));
			cardImage->setScale(scale);

			// create menu, it's an autorelease object
			auto menu = Menu::create(cardImage, NULL);
			menu->setPosition(Vec2::ZERO);
			this->addChild(menu, 1);
		}
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

void GameScene::cardClickCallback(std::shared_ptr<Mighty::Card> card)
{
	game->PlayCard(card);
}