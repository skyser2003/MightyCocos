#pragma once

namespace cocos2d
{
	class Node;
	class Menu;
}

namespace Mighty
{
	#include "enum_class_CardType.h"
}

void ShowCardList(cocos2d::Node* parent, std::function<void(cocos2d::Menu*, Mighty::CardType)> clickCallback);
void CreateLabel(cocos2d::Node* parent, cocos2d::Vec2 position, const std::string& text, const std::string& font, int fontSize, std::function<void(cocos2d::Menu*)> clickCallback);