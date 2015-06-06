#include "stdafx.h"
#include "GameScene.h"

#include "Game.h"
#include "AbstractPlayer.h"
#include "CardUtilFunc.h"
#include "Card.h"
#include "CardRole.h"
#include "AbstractPlayer.h"

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
	game->Init(game);
	game->StartNewRound();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	imageScale = 0.7f;

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

		for (size_t i = 0; i < player->GetHandCardList().size(); ++i)
		{
			auto card = player->GetHandCardList()[i];
			auto cardImageDir = "card_images/" + Mighty::Util::GetCardResourceName(card->GetType()) + ".png";


			auto cardImage = MenuItemImage::create(
				cardImageDir,
				"CloseSelected.png");

			cardImage->setPosition(Vec2(standard.x + direction.x * (i + 0.5f) * imageScale * cardImage->getContentSize().width,
				standard.y + direction.y * cardImage->getContentSize().height / 2 * imageScale));
			cardImage->setScale(imageScale);

			// create menu, it's an autorelease object
			auto menu = Menu::create(cardImage, NULL);
			menu->setPosition(Vec2::ZERO);
			this->addChild(menu, 1);

			cardImageList.emplace(card->GetType(), menu);

			auto callback = [this, card, menu](Ref* ref)
			{
				cardClickCallback(card, menu);
			};

			cardImage->setCallback(callback);
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

void GameScene::cardClickCallback(std::shared_ptr<Mighty::Card> card, cocos2d::Menu* menu)
{
	if (game->IsPlayable(card) == false)
	{
		return;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto* image = static_cast<cocos2d::MenuItemImage*>(menu->getChildren().at(0));
	image->setCallback(nullptr);
	image->setPosition(
		visibleSize.height / 2.0f + game->GetCurrentRoundCardCount() * image->getContentSize().width * imageScale,
		visibleSize.height / 2.0f
		);

	game->PlayCard(card);

	if (game->IsRoundFinished() == true)
	{
		// Logic
		auto player = game->GetWinningCard()->GetPlayer();
		const auto& cardList = game->GetCurrentRoundCardList();

		player->AddAcquiredCard(cardList);

		// UI
		for (const auto& card : cardList)
		{
			auto* menu = cardImageList[card->GetType()];
			menu->setVisible(false);
		}

		for (auto pair : cardImageList)
		{
			auto* menu = pair.second;
			menu->setColor(Color3B::WHITE);
		}

		// Begin next round
		game->StartNewRound();
	}
	else
	{
		// UI
		for (auto pair : game->GetPlayers())
		{
			auto player = pair.second;
			for (auto card : player->GetHandCardList())
			{
				auto* menu = cardImageList[card->GetType()];

				if (game->IsPlayable(card) == true)
				{
					menu->setColor(Color3B::WHITE);
				}
				else
				{
					menu->setColor(Color3B::GRAY);
				}
			}
		}
	}
}