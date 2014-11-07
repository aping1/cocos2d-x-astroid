//
//  GameScene.h
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#ifndef __astroid__GameScene__
#define __astroid__GameScene__

#include "cocos2d.h"

class GameScreen : public cocos2d::Layer
{
private:
    cocos2d::Sprite *backgroundSpriteArray[2];
    std::vector<cocos2d::Sprite *> _asteroids;

public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameScreen)
    
    void GoToPauseScene(Ref *pSender);
    void GoToGameOverScene(Ref * pSender);
    void update(float dt);
    void spawnAsteroid(float dt);
};

#endif /* defined(__astroid__GameScene__) */
