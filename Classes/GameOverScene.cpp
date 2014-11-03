//
//  GameOverScene.cpp
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOver::create();
    
    scene->addChild(layer);
    
    return scene;
}
void GameOver::der()
{
    
}
bool GameOver::init()
{
    // Super init First
    if( !Layer::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->
        getVisibleSize();
    Point origin = Director::getInstance()->
        getVisibleOrigin();
    
    auto menuTitle = MenuItemImage::create("GameOverScreen/Game_Over.png",
                                           "GameOverScreen/Game_Over.png");
    auto retryItem = MenuItemImage::create("GameOverScreen/Retry_Button.png",
                                           "GameOverScreen/Retry_Button(Click).png",
                                           CC_CALLBACK_1(GameOver::GoToGameScene, this));
    auto mainMenuItem = MenuItemImage::create("GameOverScreen/Menu_Button.png",
                                              "GameOverScreen/Menu_Button(Click).png",
                                              CC_CALLBACK_1(GameOver::GoToMainMenuScene, this));
    auto menu = Menu::create(menuTitle, retryItem, mainMenuItem, NULL);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 4);
    this->addChild(menu);
    
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