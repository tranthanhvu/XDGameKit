//
//  AppListener.cpp
//  GiatXeng
//
//  Created by VuTT5 on 9/23/15.
//
//

#include "AppListener.hpp"

AppListener::AppListener() {
}

AppListener::~AppListener() {
    
}

void AppListener::OnCreateMamagers() {
    
}

void AppListener::OnReleaseManagers() {
    
}

void AppListener::OnInitialize() {
    
}

void AppListener::OnDestroy() {
    
}

void AppListener::OnRegisterComponentPrototype() {
    
}

void AppListener::BeforeUpdateInput(float _delta) {
    
}

void AppListener::AfterUpdateInput(float _delta) {
    
}

void AppListener::BeforeUpdateAI(float _delta) {
    
}

void AppListener::AfterUpdateAI(float _delta) {
    
}

void AppListener::BeforeUpdatePhys(float _delta) {
    
}

void AppListener::AfterUpdatePhys(float _delta) {
    
}

void AppListener::BeforeUpdateTransform(float _delta) {
    
}

void AppListener::AfterUpdateTransform(float _delta) {
    
}

void AppListener::BeforeUpdateHUD(float _delta) {
    
}

void AppListener::AfterUpdateHUD(float _delta) {
    
}

void AppListener::BeforeDisplay(float _delta) {
    
}

void AppListener::AfterDisplay(float _delta) {
    
}

void AppListener::BeforeHUD(float _delta) {

}

void AppListener::AfterHUD(float _delta) {

}

bool AppListener::IsAppEnd() {
    return false;
}

void AppListener::Pause() {
    m_bPause = true;
}

void AppListener::Resume() {
    m_bPause = false;
}

bool AppListener::IsPause() const {
    return m_bPause;
}