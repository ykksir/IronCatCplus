﻿#ifndef __RESOURCE__SHOW__H__
#define __RESOURCE__SHOW__H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "NodeMsg.h"
#include "StoreData.h"
USING_NS_CC;
using namespace std;
using namespace ui;
using namespace cocostudio;

class ResourceShow :public Layer, public NodeMsg,public PayCBDelegate
{
public:
	CREATE_FUNC(ResourceShow);
	virtual bool init();

private:
	void updateUi();
	virtual const char* getClassName(){ return "ResourceShow"; }
	virtual void exeMsg(MsgType type, int data, cocos2d::Ref * pob);
	void updateBySeconds(float sec);
	void buttonHandle(Ref* pSender, ui::Widget::TouchEventType type);	//所有button的控制器
	void onExit();
	void onEnter();
	void checkMintNum();
	void payCB(PayTag tag)override;
private:
	TextBMFont* m_GoldText;			//金币数量 文本
	TextBMFont* m_FishText;			//鱼干数量 文本
	TextBMFont* m_GinerText;		//体力数量 文本
	TextBMFont* m_ReTimeText;

	Button* m_TopBt[3];				//顶部 按钮

	int m_BeginTime;				//恢复体力的开始时间
	int m_EndTime;					//恢复体力的结束时间
};



#endif 