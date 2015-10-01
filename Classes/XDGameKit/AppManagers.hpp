//
//  AppManagers.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/23/15.
//
//

#ifndef AppManagers_hpp
#define AppManagers_hpp

#include "Singleton.h"
class AppListener;

class AppManager: public Singleton<AppManager> {
    DECLARE_SINGLETON(AppManager);
    
public:
    void Initialize(AppListener* _listener, bool readScriptByJson = false, float _physUpdateTime = 0.03f);
    void Desstroy();
    bool Update(float _delta);
    void Display();
    void ProcessInput(int _action, int _id, int _x, int _y, int _oldX, int _oldY);
    
private:
    AppManager();
    ~AppManager();
    void CreateManagers();
    void ReleaseManagers();
    void DoInit();
    void DoDestroy();
    void RegisterComponentPrototypes();
    void UpdateInput(float _delta);
    void UpdateAI(float _delta);
    void UpdatePhys(float _delta);
    void UpdateTransform(float _delta);
    void UpdateDisplay(float _delta);
    void UpdateHUD(float _delta);
    void PostUpdate(float _delta);

    void DoDisplay();
    void DoHUD();
    void PostDisplay();
    
    void DoProcessInput(int _action, int _id, int _x, int _y, int _oldX, int _oldY);
    
    AppListener* m_pListener;
    
    // Phys update is special -----------------
    float m_fPhysTimer;
    float m_fPhysUpdateTime;
    // ----------------------------------------
    
};

#endif /* AppManagers_hpp */
