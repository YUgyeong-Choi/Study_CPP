#include "MainGame.h"
#include "pch.h"
#include "Define.h"

MainGame::MainGame()
{
	m_Login = nullptr;
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	if(!m_Login) m_Login = new Login;
}

void MainGame::Update()
{
	cout << "시작 화면" << endl;
	cout << "아무 버튼이나 눌러주세요" << endl;
	cin.get();
	
	m_Login->Update();
}

void MainGame::Release()
{
	SAFE_DELETE(m_Login);
}
