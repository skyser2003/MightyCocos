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