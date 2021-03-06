   #define _IRPowOFF   0x00
   #define _IRPowON    0x01
   #define _IrDAPowON  0x05
   #define _IRPowStat  0x02

   extern unsigned char IRPowerCtrl(unsigned char ctrl);
/*
1.红 外 电 源 控 制
参 数:
     ctrl
        _IRPowOFF      关闭红外电源，并设为有线模式
        _IRPowON       打开红外电源，并设为普红外模式
        _IrDAPowON     打开红外电源，并设为IrDA模式
        _IRPowStat     获取红外电源状态
返 回 参 数 :
	无
函 数 值 :
	0 旧 状 态 为 关 闭
	1 旧 状 态 为 打 开
*/



   extern void SetIRMFreq(long freq);
/*
2.设 制 红 外 调 制 频 率
参 数:
	freq
	  以 Hz 为 单 位 的 频 率 值 如 38000 Hz。
	  0 表 示 关 闭 红 外 调 制 频 率．使 用 完
	       之 后 必 需 关 闭．
返 回 参 数 :
	无
函 数 值 :
	无
*/


   extern void SetIROutput(unsigned char io);
/*
3.设 置 红 外 输 出
参 数:
	io
	  0  输 出 低 电 平
	  1  输 出 高 电 平
	  2  红 外 输 出 恢 复 正 常(确 省) ,
 	     红 外 输 出 作 为 COM2输 出� 完 全
	     由 COM2 口 控 制
返 回 参 数 :
	无
函 数 值 :
	无
*/


   extern unsigned char GetIRInput(void);
/*
4.取 得  红 外 输 入
参 数:
	无  �
返 回 参 数 :
	无
函 数 值 :
	0 为 低 电 平
	1 为 高 电 平
*/

