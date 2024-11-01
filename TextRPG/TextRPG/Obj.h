#pragma once
#include "Define.h"  // Define.h 파일에 INFO 구조체가 정의되어 있어야 합니다.

class Obj {
public:
    Obj();
    Obj(const char* pName, int _iHp, int _iAttack);
    virtual ~Obj();

    void Render();
    INFO Get_Info() const { return m_info; }
    void Set_Damage(int _iAttack) { m_info.m_iHp -= _iAttack; }

    virtual bool Load_Data() { return false; }
    virtual bool Save_Data() { return false; }
    virtual void Create_Obj(const char* pName, int _iHp, int _iAttack) { ; }
    virtual bool Select_Job() { return false; }
    virtual void Set_Hp(int _iHp) { m_info.m_iHp = _iHp; }

protected:
    INFO m_info;  
};