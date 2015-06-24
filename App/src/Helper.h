#pragma once

namespace cocos2d
{
	class Node;
}

namespace Mighty
{
	#include "enum_class_CardType.h"
}

void ShowCardList(cocos2d::Node* parent, std::function<void(Mighty::CardType)> clickCallback);