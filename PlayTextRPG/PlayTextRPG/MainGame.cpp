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
	cout << "���� ȭ��" << endl;
	cout << "�ƹ� ��ư�̳� �����ּ���" << endl;
	cin.get();
	
	m_Login->Update();
}

void MainGame::Release()
{
	SAFE_DELETE(m_Login);
}
