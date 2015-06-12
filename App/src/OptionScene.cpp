#include "stdafx.h"
#include "OptionScene.h"

#include "CardType.h"
#include "CardUtilFunc.h"

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

	// 	auto label = Label::createWithTTF("OPTION", "fonts/Marker Felt.ttf", 24);
	// 	auto labelMenu = MenuItemLabel::create(label);
	// 
	// 	auto menu = Menu::create();
	// 	menu->addChild(labelMenu);
	// 
	// 	menu->setPosition(Vec2(origin.x + visibleSize.width / 2,
	// 		origin.y + visibleSize.height / 2 - label->getContentSize().height));
	// 
	// 	addChild(menu);

	ShowCardList();

	return true;
}

void OptionScene::ShowCardList()
{
	std::vector<Mighty::CardType> deck;

	for (auto type : Mighty::CardTypes())
	{
		if (type == Mighty::CardType::JC)
		{
			continue;
		}

		deck.push_back(type);
	}

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto menu = Menu::create();

	auto bgImage = MenuItemImage::create("HelloWorld.png", "CloseSelected.png");
	const auto& bgImageSize = bgImage->getContentSize();
	bgImage->setPosition(bgImageSize.width / 2, bgImageSize.height / 2);
	bgImage->setScale(2.0f);

	auto offset = -1 * bgImageSize / 2;

	// Card image size
	int horizontalPadding = 10;
	int verticalPadding = 10;
	int cardPerColumn = 13;
	int cardWidth = (bgImageSize.width * bgImage->getScale() - (cardPerColumn + 1) * horizontalPadding) / cardPerColumn;
	int cardHeight = 0;
	float cardScale = 1.0f;
	{
		auto cardImageDir = "card_images/" + Mighty::Util::GetCardResourceName(Mighty::CardType::C2) + ".png";
		auto cardImage = MenuItemImage::create(cardImageDir, "CloseSelceted.png");
		auto size = cardImage->getContentSize();
		cardScale = cardWidth / size.width;
		cardHeight = cardScale * size.height;
	}

	for (int i = 0; i < deck.size(); ++i)
	{
		auto type = deck[i];

		auto cardImageDir = "card_images/" + Mighty::Util::GetCardResourceName(type) + ".png";

		auto cardImage = MenuItemImage::create(
			cardImageDir,
			"CloseSelected.png");

		int column = i % cardPerColumn;

		cardImage->setPosition(
			offset.x + horizontalPadding + column * (cardWidth + horizontalPadding) + cardWidth / 2,
			offset.y + (cardHeight + verticalPadding) * (i / cardPerColumn) + cardHeight / 2
			);
		cardImage->setScale(cardScale);
		menu->addChild(cardImage, 2);
	}

	menu->addChild(bgImage, 1);
	menu->setPosition((visibleSize.width - bgImageSize.width) / 2, (visibleSize.height - bgImageSize.height) / 2);

	addChild(menu);
}