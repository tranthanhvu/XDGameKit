//
//  AppListener.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/23/15.
//
//

#ifndef AppListener_hpp
#define AppListener_hpp

class AppListener: public cocos2d::Ref {
public:
    AppListener();
    virtual ~AppListener();
    
    virtual void OnCreateMamagers();
    virtual void OnReleaseManagers();
    virtual void OnInitialize();
    virtual void OnDestroy();
    virtual void OnRegisterComponentPrototype();
    virtual void BeforeUpdateInput(float _delta);
    virtual void AfterUpdateInput(float _delta);
    virtual void BeforeUpdateAI(float _delta);
    virtual void AfterUpdateAI(float _delta);
    virtual void BeforeUpdatePhys(float _delta);
    virtual void AfterUpdatePhys(float _delta);
    virtual void BeforeUpdateTransform(float _delta);
    virtual void AfterUpdateTransform(float _delta);
    virtual void BeforeUpdateHUD(float _delta);
    virtual void AfterUpdateHUD(float _delta);
    virtual void BeforeDisplay(float _delta);
    virtual void AfterDisplay(float _delta);
    virtual void BeforeHUD(float _delta);
    virtual void AfterHUD(float _delta);
    virtual bool IsAppEnd();
    virtual void Pause();
    virtual void Resume();
    bool IsPause() const;
private:
    bool m_bPause;
};

#endif /* AppListener_hpp */
