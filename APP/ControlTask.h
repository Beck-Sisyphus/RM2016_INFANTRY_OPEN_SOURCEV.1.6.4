#ifndef _CONTROL_TASK_H_
#define _CONTROL_TASK_H_
#include "main.h"

//initiate status:
typedef enum
{
    PREPARE_STATE,     		//上电后初始化状态 4s钟左右
    STANDBY_STATE,			//云台停止不转状态
    NORMAL_STATE,			//无输入状态
    STOP_STATE,        	//停止运动状态
    CALI_STATE,    			//校准状态
}WorkState_e;

#define PREPARE_TIME_TICK_MS 4000      //prapare time in ms

#define STATE_SWITCH_DELAY_TICK 100000   //mode change delay count in ms

#define YAW_POSITION_KP_DEFAULTS  25
#define YAW_POSITION_KI_DEFAULTS  0
#define YAW_POSITION_KD_DEFAULTS  0

#define YAW_SPEED_KP_DEFAULTS  35
#define YAW_SPEED_KI_DEFAULTS  0
#define YAW_SPEED_KD_DEFAULTS  0

// avoid bang --->  position:20.0  speed:19.0
//big bang   22.5 20.0
#define PITCH_POSITION_KP_DEFAULTS  20.0
#define PITCH_POSITION_KI_DEFAULTS  0
#define PITCH_POSITION_KD_DEFAULTS  0

#define PITCH_SPEED_KP_DEFAULTS  19.0
#define PITCH_SPEED_KI_DEFAULTS  0
#define PITCH_SPEED_KD_DEFAULTS  0

#define PID_SHOOT_MOTOR_SPEED_INIT (7)
#define PID_SHOOT_MOTOR_SPEED      (10)
#define PID_SHOOT_MOTOR_CHECK_SPEED (3)

#define CHASSIS_SPEED_ATTENUATION   (1.0f)

#define CHASSIS_MOTOR_ROTATE_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	1.20f,\
	0.0f,\
	0.0f,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	5000,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

//gimbal position pid control
//20  19
#define GIMBAL_MOTOR_PITCH_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	PITCH_POSITION_KP_DEFAULTS,\
	PITCH_POSITION_KI_DEFAULTS,\
	PITCH_POSITION_KD_DEFAULTS,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

//gimbal speed pid control
#define GIMBAL_MOTOR_PITCH_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	PITCH_SPEED_KP_DEFAULTS,\
	PITCH_SPEED_KI_DEFAULTS,\
	PITCH_SPEED_KD_DEFAULTS,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

//gimbal yaw position pid control
#define GIMBAL_MOTOR_YAW_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	YAW_POSITION_KP_DEFAULTS,\
	YAW_POSITION_KI_DEFAULTS,\
	YAW_POSITION_KD_DEFAULTS,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	5000,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

//gimbal yaw speed pid control
#define GIMBAL_MOTOR_YAW_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	YAW_SPEED_KP_DEFAULTS,\
	YAW_SPEED_KI_DEFAULTS,\
	YAW_SPEED_KD_DEFAULTS,\
	0,\
	0,\
	0,\
	4900,\
	1000,\
	1500,\
	0,\
	4900,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

//D参数原来为0.4
#define CHASSIS_MOTOR_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	220.f,\
	0.0f,\
	0.0f,\
	0,\
	0,\
	0,\
	4900,\
	3500,\
	1500,\
	0,\
	4950,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

#define SHOOT_MOTOR_POSITION_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	220.f,\
	0.0f,\
	0.0f,\
	0,\
	0,\
	0,\
	4900,\
	3500,\
	1500,\
	0,\
	4950,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

#define SHOOT_MOTOR_SPEED_PID_DEFAULT \
{\
	0,\
	0,\
	{0,0},\
	50.0f,\
	0.5f,\
	0.0f,\
	0,\
	0,\
	0,\
	1000,\
	200,\
	100,\
	0,\
	4950,\
	0,\
	0,\
	0,\
	&PID_Calc,\
	&PID_Reset,\
}\

#define PID_CALI_DEFAULT  \
{\
	0,\
	0,\
	0,\
	0,\
}\

extern PID_Regulator_t CMRotatePID;      		//底盘跟随云台PID
extern PID_Regulator_t GMPPositionPID;      	//pitch轴位置环PID
extern PID_Regulator_t GMPSpeedPID;      		//pitch轴速度换PID
extern PID_Regulator_t GMYPositionPID;			//yaw轴位置环PID
extern PID_Regulator_t GMYSpeedPID;      		//yaw轴速度环PID

extern PID_Regulator_t ShootMotorPositionPID;    //射击电机位置环PID
extern PID_Regulator_t ShootMotorSpeedPID;       //射击电机速度环PID

extern PID_Regulator_t CM1SpeedPID;				 //底盘电机速度环PID
extern PID_Regulator_t CM2SpeedPID;
extern PID_Regulator_t CM3SpeedPID;
extern PID_Regulator_t CM4SpeedPID;

WorkState_e GetWorkState(void);
void ControtLoopTaskInit(void);
void WorkStateFSM(void);
static void WorkStateSwitchProcess(void);
void Control_Task(void);
void GMPitchControlLoop(void);
void GMYawControlLoop(void);
void GMPitchControlLoop(void);
void GimbalYawControlModeSwitch(void);   //模式切换处理，得到位置环的设定值和给定值
void SetGimbalMotorOutput(void);
#endif
