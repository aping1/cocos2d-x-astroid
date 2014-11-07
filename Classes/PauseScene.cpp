//
//  PauseScene.cpp
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#include "PauseScene.h"
#include "GameScene.h"
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
    
    auto resumeItem = MenuItemImage::create("PauseScreen/Resume_Button.png",
                                            "PauseScreen/Resume_Button(Click).png",
                                            CC_CALLBACK_1(PauseMenu::Resume, this));
    auto retryItem = MenuItemImage::create("PauseScreen/Retry_Button.png",
                                           "PauseScreen/Retry_Button(Click).png",
                                           CC_CALLBACK_1(PauseMenu::Retry, this));
    auto mainMenuItem = MenuItemImage::create("PauseScreen/Menu_Button.png",
                                              "PauseScreen/Menu_Button(Click).png",
                                              CC_CALLBACK_1(PauseMenu::GoToMainMenuScene, this));
    auto menu = Menu::create(resumeItem, retryItem, mainMenuItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);
    
    auto backgroundSprite = Sprite::create("PauseScreen/Pause_Background.png");
    backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(backgroundSprite, -1);
    
    
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
