#pragma once
#include "map.h"
#include <string>
#include <vector>

struct savedata
{
	int hp, atk, def, now_floor;
	void init(int _hp, int _atk, int _def, int _nowf) {hp=_hp;atk=_atk;def=_def;now_floor=_nowf;}
};

class constants
{
public:
	static const int MESSAGE_NONE = 0;
	static const int MESSAGE_QUIT = 1;
	static const int MESSAGE_RESTART = 2;
	static const int MESSAGE_SAVE = 3;
	static const int MESSAGE_LOAD = 4;
	static const int MESSAGE_WIN = 5;
	static const int MESSAGE_LOSE = 6;
	static const int MESSAGE_FLYING = 7;
	static const int MESSAGE_NPC = 8;
	static const int MESSAGE_HINT = 9;

	constants();
	void init();
	void loadResources();
	void destroy();
	void setMsg(const char*[50]);
	void setMsg(const char*);
	bool isFree() {return !moving && !opening && !battling && !flooring && msg==MESSAGE_NONE;}
	void goOn(c_hero*, c_map_floor*, float);
	void save(FILE*);
	void load(FILE*);
	void printInfo();

	int msg;
	vector<string> hint;
	int nowcnt;
	long lasttime;

	float playtime;
	int step;

	bool canfly,book,stick,cross,trueend;
	bool attack_flag,defence_flag,yellow_flag,blue_flag,red_flag,small_flag,big_flag;
	bool moving,opening,battling,flooring,music;
	int map_floornum,map_height,map_width,volume,bgmvolume,ScreenLeft,special_floornum;

	savedata sd[10];
	int wanttosave;

	float lefttime;

	// ���ڴ򿪵���
	c_map_door *map_openingdoor;
	// ����ս���Ĺ���
	c_monster *monster_battling;
	// ����ս�������ԭʼ����ֵ
	int monster_life;

	// HGE
	HGE *hge;

	//��������
	HTEXTURE ht_map,ht_icon,ht_hero,ht_monster,ht_skin,ht_npc,ht_special;

	//������Ч
	HEFFECT he_GetItem,he_OpenDoor,he_Attack, he_Music;
	HCHANNEL hc_Music;

	//����ͼ��
	hgeSprite *s_ground,*s_wall,*s_water,*s_sky,*s_lightning,*s_barrier;
	hgeSprite *s_redjewel,*s_bluejewel,*s_redkey,*s_bluekey,*s_yellowkey,*s_allkey;
	hgeSprite *s_redpotion,*s_bluepotion,*s_coin,*s_fly,*s_fly2,*s_cross,*s_floor,*s_stick,*s_drink;
	hgeSprite *s_sword1,*s_shield1,*s_sword2,*s_shield2,*s_sword3,*s_shield3;
	hgeSprite *s_enemyinfo, *s_level, *s_storey, *s_heart, *s_expr, *s_damage, *s_time, *s_step;
	hgeSprite *s_reddoor,*s_bluedoor,*s_yellowdoor,*s_upstair,*s_downstair,*s_specialdoor;
	hgeSprite *s_shopleft,*s_shopright;

	hgeSprite *s_portal, *s_sigh, *s_sighed, *s_up, *s_left, *s_right, *s_down, *s_flower, *s_box, *s_boxed;
	hgeSprite *s_atk, *s_def, *s_life;

	// ����
	hgeFont *hgef;

	// ��������
	float time_move,time_open,time_animation,time_battle,time_floor;
	// �������Ƿ�ʼ
	bool isMyTurn, beatStarted;

};