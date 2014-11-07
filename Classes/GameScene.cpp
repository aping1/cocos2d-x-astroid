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
#include <iostream>

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
                                           "GameScreen/Pause_Button(Click).png",
                                           CC_CALLBACK_1(GameScreen::GoToPauseScene, this));
    pauseItem->setPosition(Point(pauseItem->getContentSize().width - (pauseItem->getContentSize().width / 4) + origin.x,
                                 visibleSize.height - pauseItem->getContentSize().height +(pauseItem->getContentSize().width/4)+ origin.y));
    auto menu = Menu::create(pauseItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    for(int i = 0; i <= 2; i ++)
    {
        backgroundSpriteArray[i] = Sprite::create("GameScreen/Game_Screen_Background.png");
        backgroundSpriteArray[i]->setPosition(Point((visibleSize.width / 2) + origin.x,  origin.y + (visibleSize.height / 2) +  (visibleSize.height * (i - 1))));
//        backgroundSpriteArray[i]->setPosition(Point((visibleSize.width / 2) + origin.x, (-1 * visibleSize.height  * i) + origin.y));
        this->addChild(backgroundSpriteArray[i], -2);
    }
    printf("height: %f width: %f", visibleSize.height, visibleSize.width);
    this->schedule(schedule_selector(GameScreen::spawnAsteroid), 1.0);
    this->scheduleUpdate();
    return true;
}

void GameScreen::spawnAsteroid(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    int asteroidIndex = (arc4random() % 3) + 1;
    __String* asteroidString = __String::createWithFormat("GameScreen/Asteroid_%i.png", asteroidIndex);
    
    Sprite *tempAsteroid = Sprite::create(asteroidString->getCString());
    
    int xRandomPosition = (arc4random() % (int)(visibleSize.width - (tempAsteroid->getContentSize().width / 2))) + (tempAsteroid->getContentSize().width / 2);
    
    tempAsteroid->setPosition(Point(xRandomPosition + origin.x, -tempAsteroid->getContentSize().height + origin.y));
    _asteroids.push_back(tempAsteroid);
    this->addChild(_asteroids[_asteroids.size() - 1], -1);
}

void GameScreen::GoToPauseScene(Ref *pSender)
{
    auto scene = PauseMenu::createScene();
    
    Director::getInstance()->pushScene(scene);
    
}

void GameScreen::GoToGameOverScene(Ref *pSender)
{
    auto scene = GameOver::createScene();
    
    Director::getInstance()->pushScene(TransitionFade::create(1.0, scene));
}

void GameScreen::update(float dt)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    for(int i = 0; i <= 2; i ++)
    {
        if (backgroundSpriteArray[i]->getPosition().y >= (visibleSize.height  *  2) + (visibleSize.height /2))
        {
            backgroundSpriteArray[i]->setPosition(Point((visibleSize.width / 2) + origin.x, origin.y + (-1 * visibleSize.height)));
        }
    }
    for(int i = 0; i <= 2; i++)
    {
        backgroundSpriteArray[i]->setPosition(Point(backgroundSpriteArray[i]->getPosition().x, backgroundSpriteArray[i]->getPosition().y + (0.75 * visibleSize.height * dt)));
        
    }
    std::cout << "Size of stuff " << (0 < _asteroids.size()) << std::endl;
    for (int i = 0; i < _asteroids.size(); i++)
    {
        
        _asteroids[i]->setPosition(Point(_asteroids[i]->getPosition().x, _asteroids[i]->getPosition().y + (0.75 * visibleSize.height * dt)));
        
        if (_asteroids[i]->getPosition().y > visibleSize.height * 2)
        {
            this->removeChild(_asteroids[i]);
            _asteroids.erase(_asteroids.begin() + i);
        }
    }
}
