#pragma once

#include "../GameObject.h"
#include "../../Utility/Vector2D.h"
#include "../../Utility/StageData.h"

// �v���C���[���
enum ePlayerState
{
	IDLE,		// �ҋ@���
	MOVE,		// �ړ����
	DIE,		// ���S���
	Damage,     //�_���[�W
	Jump,       //�W�����v
};

/// <summary>
/// �v���C���[�N���X�i�p�b�N�}���j
/// </summary>
class Player : public GameObject
{
private:
	// �i�s�������
	enum eDirectionState : unsigned char
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NONE,
	};

private:
	std::vector<int> move_animation;		// �ړ��̃A�j���[�V�����摜
	std::vector<int> jump_animation;        //�W�����v�̃A�j���[�V�����摜
	std::vector<int> dying_animation;		// ���S�̃A�j���[�V�����摜

	Vector2D old_location;					// �O���location(�W�����v)
	Vector2D velocity;						// �ړ���

	Vector2D jump_location;
	Vector2D jump_velocity;

	eDirectionState now_direction_state;	// ���ݐi�s�������
	eDirectionState next_direction_state;	// ����i�s�������
	int food_count;							// �a��H�ׂ���
	float animation_time;					// �A�j���[�V��������
	//int animation_count;					// �A�j���[�V�����Y��
	//ePanelID old_panel;						// �O��p�l�����
	bool is_power_up;						// �p���[�a��H�ׂ����H
	bool is_destroy;						// ���񂾏�ԂɂȂ������H

	// �ړ��A�j���[�V�����̏���
	const int animation_num[4] = { 1, 2, 3, 2, };
	const int jump_animation_num[2] = { 1,5 };

	//�A�j���[�V�����̃J�E���g
	int animation_count;
	
	//��ʃX�N���[���p
	bool scroll_end;
	int g_velocity;

	//�W�����v��SE
	int jump_SE;

	Player* player;
public:
	int screenoffset;   //�X�N���[���p�̌��_�p�̕ϐ�

	



public:
	ePlayerState player_state;				// �v���C���[���

	static Player* GetInstance();

private:
	static Player* instance;

public:
	Player();
	virtual ~Player();

	virtual void Initialize() override;
	virtual void Update(float delta_second) override;
	virtual void Draw(const Vector2D& screen_offset) const override;

	/*void Draw(float sscreen_offsetcre);*/

	virtual void Finalize() override;

	/// <summary>
	/// �����蔻��ʒm����
	/// </summary>
	/// <param name="hit_object">���������Q�[���I�u�W�F�N�g�̃|�C���^</param>
	virtual void OnHitCollision(GameObjectBase* hit_object) override;

public:
	/// <summary>
	/// �a��H�ׂ����擾
	/// </summary>
	/// <returns>�a��H�ׂ���</returns>
	int GetFoodCount() const;

	/// <summary>
	/// �v���C���[�̏�Ԃ��擾����
	/// </summary>
	/// <returns>�v���C���[�̏��</returns>
	ePlayerState GetPlayerState() const;

	/// <summary>
	/// �v���C���[���p���[�A�b�v���Ă邩�m�F����
	/// </summary>
	/// <returns>�v���C���[�̏��</returns>
	bool GetPowerUp() const;

	/// <summary>
	/// �p���[�_�E��������
	/// </summary>
	void SetPowerDown();

	/// <summary>
	/// �v���C���[���p���[�A�b�v���Ă邩�m�F����
	/// </summary>
	/// <returns>�v���C���[�̏��</returns>
	bool GetDestroy() const;

	//�ʒu���擾����
	const Vector2D& GetVelocity() const;

	void SetScrollEnd();

	//�v���C���[�̏��
	ePlayerState PlayerState();

private:
	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void Movement(float delta_second);
	/// <summary>
	/// �A�j���[�V��������
	/// </summary>
	/// <param name="delta_second">1�t���[��������̎���</param>
	void AnimationControl(float delta_second);

};
