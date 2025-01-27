#pragma once

#include "../GameObject.h"
#include "../../Utility/StageData.h"

enum eKuriboState
{
	WALK,   //�����E�ʏ���
	STEP,   //���܂ꂽ���
};

class kuribo : public GameObject
{
private:
	std::vector<int> move_animation;   //�ړ��̃A�j���[�V����


	//�A�j���[�V�����p
	const int animation_num[2] = {0,1};
	int animation_count;
	float animation_time;

	static kuribo* instance;

	//����
	Vector2D direction;

	kuribo* Kuribo;

public:

	//�N���{�[�̏��
	eKuriboState kuribo_state;

	kuribo();
	~kuribo();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screen_offset) const override;
	virtual void Finalize() override;

	/*virtual void OnHitCollision(GameObject* hit_object) ;*/

	void SetVelocity(float velo);

	static kuribo* GetInstance();

private:

	void Movement(float delta_second);
	void AnimeCount(float delta_second);
};

