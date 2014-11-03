//
//  GameOverScene.h
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#ifndef __astroid__GameOverScene__
#define __astroid__GameOverScene__

#include "cocos2d.h"

class GameOver : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameOver);
    
    void GoToGameScene(Ref *pSender);
    void GoToMainMenuScene(Ref *pSender);
    void der();
};

#endif /* defined(__astroid__GameOverScene__) */
