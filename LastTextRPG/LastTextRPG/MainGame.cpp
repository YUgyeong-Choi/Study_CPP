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
	cout << "���� ȭ��" << endl;
	cout << " ! ���� !";
	cout << "�� �����Ǿ� �ֽ��ϴ�" << endl;
	cout << "�̱��� ����Ʈ" << endl;
	cout << "1.��������" << endl;
	cout << "2.���� �ҷ�����" << endl;
	cout << "�ƹ� ��ư�̳� �����ּ���" << endl;
	system("pause");

	m_pLogin = new Login;
	m_pLogin->Update();
}

void MainGame::Release()
{
	SAFE_DELETE<Login*>(m_pLogin);
}
