#include "MainGame.h"
#include "pch.h"
#include "Color.h"

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
	setColor(SKYBLUE);
	cout << " ! 전사 !";
	setColor(RED);
	cout<<"만 구현되어 있습니다" << endl;
	cout << "미구현 리스트" << endl;
	cout << "1.보스던전" << endl;
	cout << "2.저장 불러오기" << endl;
	setColor(YELLOW);
	cout << "아무 버튼이나 눌러주세요" << endl;
	cin.get();
	
	m_Login->Update();
}

void MainGame::Release()
{
	SAFE_DELETE(m_Login);
}
