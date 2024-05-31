#include "include/InputManager.h"

#include <raylib.h>

MM::InputManager *MM::InputManager::s_pInstance= nullptr;


MM::InputManager::InputManager(){
}

bool MM::InputManager::IsKeyPressed(Keys key){
    return ::IsKeyPressed(key);
}

bool MM::InputManager::IsKeyPressedRepeat(Keys key){
    return ::IsKeyPressedRepeat(key);
}

bool MM::InputManager::IsKeyDown(Keys key){
    return ::IsKeyDown(key);
}

bool MM::InputManager::IsKeyReleased(Keys key){
    return ::IsKeyReleased(key);
}

bool MM::InputManager::IsKeyUp(Keys key){
    return ::IsKeyUp(key);
}

void MM::InputManager::SetExitKey(Keys key){
    ::SetExitKey(key);
}
