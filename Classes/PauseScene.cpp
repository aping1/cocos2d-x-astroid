//
//  PauseScene.cpp
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#include "PauseScene.h"
#include "GameScreen.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* PauseMenu::createScene()
{
    
    auto scene = Scene::create();
    
    auto layer = PauseMenu::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool PauseMenu::init()
{
    if ( !Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    return true;
}

void PauseMenu::Resume(cocos2d::Ref *pSender)
{
    Director::getInstance()->popScene();
}

void PauseMenu::GoToMainMenuScene(cocos2d::Ref *pSender)
{
    auto scene = MainMenu::createScene();
    
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}


void PauseMenu::Retry(cocos2d::Ref *pSender)
{
    auto scene = GameScreen::createScene();
    
    Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(scene);
}
