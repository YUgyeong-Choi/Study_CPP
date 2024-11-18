#include "MainGame.h"
#include "Define.h"
#include "pch.h"

MainGame::MainGame():m_pLogin(nullptr)
{}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Update()
{
	cout << "시작 화면" << endl;
	cout << " ! 전사 !";
	cout << "만 구현되어 있습니다" << endl;
	cout << "미구현 리스트" << endl;
	cout << "1.보스던전" << endl;
	cout << "2.저장 불러오기" << endl;
	cout << "아무 버튼이나 눌러주세요" << endl;
	system("pause");

	m_pLogin = new Login;
	m_pLogin->Update();
}

void MainGame::Release()
{
	SAFE_DELETE<Login*>(m_pLogin);
}
