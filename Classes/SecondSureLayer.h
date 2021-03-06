﻿#ifndef __SECOND_SURE_LAYER__H__
#define __SECOND_SURE_LAYER__H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "PayCBDelegate.h"

#define _SECOND_SURE_OK_ "_SECOND_SURE_OK_" //二次确认成功

USING_NS_CC;
using namespace std;
using namespace ui;
using namespace cocostudio;

class SecondSureLayer : public Layer, public PayCBDelegate
{
private:
	Sprite* m_PropSpr;	//要购买的物品的图片展示
	Button* m_CloseBt;	//关闭按钮
	Button* m_SureBt;	//确认按钮
	int m_PaySid;
public:
	static SecondSureLayer* create(int sdkSid, Sprite* buyProp, string desc);
	bool init(int sdkSid, Sprite* buyProp, string desc);
	void buttonHandle(Ref* pSender, TouchEventType type);
	virtual void payCB(PayTag tag);
	void onEnter() override;
	void onExit() override;
};

#endif 