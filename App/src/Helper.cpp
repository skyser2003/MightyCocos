#include "stdafx.h"
#include "Helper.h"

#include "CardType.h"
#include "CardUtilFunc.h"

USING_NS_CC;

void ShowCardList(cocos2d::Node* parent, std::function<void(Menu*, Mighty::CardType)> clickCallback)
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

	for (size_t i = 0; i < deck.size(); ++i)
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
		cardImage->setCallback([clickCallback, menu, type](Ref* ref)
		{
			clickCallback(menu, type);
		});

		menu->addChild(cardImage, 2);
	}

	menu->addChild(bgImage, 1);
	menu->setPosition((visibleSize.width - bgImageSize.width) / 2, (visibleSize.height - bgImageSize.height) / 2);

	parent->addChild(menu);
}

void CreateLabel(cocos2d::Node* parent, cocos2d::Vec2 position, const std::string& text, const std::string& font, int fontSize, std::function<void(cocos2d::Menu*)> clickCallback)
{
	auto label = Label::createWithTTF(text, font, 24);
	auto labelMenu = MenuItemLabel::create(label);

	auto menu = Menu::create();
	menu->addChild(labelMenu);
	menu->setPosition(position);

	labelMenu->setCallback([clickCallback, menu](Ref* ref)
	{
		clickCallback(menu);
	});

	parent->addChild(menu);
}