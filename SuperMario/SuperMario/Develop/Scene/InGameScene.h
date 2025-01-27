#pragma once

#include "SceneBase.h"

class InGameScene : public SceneBase
{
private:
	class Player* player;		// �v���C���[���
	class kuribo* Kuribo;


	//int back_ground_image;		// �w�i�摜
	int back_ground_BGM;		// BGM
	//bool pause_flag;			// �ꎞ��~�t���O
	//float scroll;   //�w�i��ʈʒu�ւ�
	float velocity;

	//�^�C�g�����UI�̐ݒ�
	int mario_ui;
	int mario_world;
	int mario_time;

	int fream_time;   //�t���[���̎��Ԑݒ�

public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Initialize() override;
	virtual eSceneType Update(const float& delta_second) override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	// ���݂̃V�[���^�C�v�����擾����
	virtual const eSceneType GetNowSceneType() const override;

};

