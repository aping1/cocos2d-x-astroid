//
//  GameOverScene.cpp
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#include "GameOverScene.h"

USING_NS_CC;

Scene * GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOver::create();
    
    scene->addChild(layer);
}

bool GameOver::init()
{
    if( !Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->
        geVisibleSize();
    Point origin = Director::getInstance()->
        getVisibleOrigin();
    
    return true;
}


void GameOver::GoToGameScene(cocos2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();
    Director::getInstance()->replaceScene(scene);
}

void GameOver::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    
    Director::getInstance()->replaceScene(scene);
}