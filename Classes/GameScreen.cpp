//
//  GameScreen.cpp
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#include "GameScreen.h"
#include "PauseScene.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene *GameScreen::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScreen::create()
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
    Director::getInstance()->pushScene(scene);
}
