//
//  PauseScene.h
//  astroid
//
//  Created by Allison Wampler on 11/2/14.
//
//

#ifndef __astroid__PauseScene__
#define __astroid__PauseScene__

class PauseMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(PauseMenu);
    
    void Resume(Ref *pSender);
    void GoToMainMenuScene(Ref *pSender);
    void Retry(Ref *pSender);
};

#endif /* defined(__astroid__PauseScene__) */
