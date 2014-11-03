//
//  GameScreen.cpp
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#include "GameScene.h"
#include "PauseScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene *GameScreen::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScreen::create();
    scene->addChild(layer);
    return scene;
}

bool GameScreen::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto pauseItem = MenuItemImage::create("GameScreen/Pause_Button.png",
                                           "GameScreen/Pause_Button(click).png",
                                           CC_CALLBACK_1(GameScreen::GoToGameOverScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) + origin.x,
                                 visibleSize.height - pauseItem->getContentSize().height +(pauseItem->getContentSize().width/4)+ origin.y));
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    return true;
}

void GameScreen::GoToPauseScene(cocos2d::Ref *pSender)
{
    auto scene = PauseMenu::createScene();
    
    Director::getInstance()->pushScene(scene);
    
}

void GameScreen::GoToGameOverScene(cocos2d::Ref *pSender)
{
    auto scene = GameOver::createScene();
    
    Director::getInstance()->pushScene(TransitionFade::create(1.0, scene));
}
